#pragma once

#include "../dxvk/dxvk_device.h"

#include "d3d9_device_child.h"
#include "d3d9_format.h"

namespace dxvk {

  /**
   * \brief Buffer map mode
   */
  enum D3D9_COMMON_BUFFER_MAP_MODE {
    D3D9_COMMON_BUFFER_MAP_MODE_BUFFER,
    D3D9_COMMON_BUFFER_MAP_MODE_DIRECT
  };

  /**
   * \brief Common buffer descriptor
   */
  struct D3D9_BUFFER_DESC {
    D3DRESOURCETYPE Type;
    UINT            Size;
    DWORD           Usage;
    D3D9Format      Format;
    D3DPOOL         Pool;
    DWORD           FVF;
  };

  /**
   * \brief The type of buffer you want to use
   */
  enum D3D9_COMMON_BUFFER_TYPE {
    D3D9_COMMON_BUFFER_TYPE_MAPPING,
    D3D9_COMMON_BUFFER_TYPE_STAGING,
    D3D9_COMMON_BUFFER_TYPE_REAL
  };

  struct D3D9Range {
    D3D9Range() { Clear(); }

    D3D9Range(uint32_t min, uint32_t max)
    : min(min),
      max(max) {

    }

    inline bool IsDegenerate() { return min == max; }

    inline void Conjoin(D3D9Range range) {
      if (IsDegenerate())
        *this = range;
      else {
        min = std::min(range.min, min);
        max = std::max(range.max, max);
      }
    }

    inline bool Overlaps(D3D9Range range) {
      if (IsDegenerate())
        return false;

      return range.max > min && range.min < max;
    }

    inline void Clear() { min = 0; max = 0; }

    uint32_t min = 0;
    uint32_t max = 0;
  };

  class D3D9CommonBuffer {
    static constexpr VkDeviceSize BufferSliceAlignment = 64;
  public:

    D3D9CommonBuffer(
            D3D9DeviceEx*      pDevice,
      const D3D9_BUFFER_DESC*  pDesc);

    HRESULT Lock(
            UINT   OffsetToLock,
            UINT   SizeToLock,
            void** ppbData,
            DWORD  Flags);

    HRESULT Unlock();

    /**
    * \brief Determine the mapping mode of the buffer, (ie. direct mapping or backed)
    */
    inline D3D9_COMMON_BUFFER_MAP_MODE GetMapMode() const {
      return (m_desc.Pool == D3DPOOL_DEFAULT && (m_desc.Usage & (D3DUSAGE_DYNAMIC | D3DUSAGE_WRITEONLY)))
        ? D3D9_COMMON_BUFFER_MAP_MODE_DIRECT
        : D3D9_COMMON_BUFFER_MAP_MODE_BUFFER;
    }

    /**
    * \brief Abstraction for getting a type of buffer (mapping/staging/the real buffer) across mapping modes.
    */
    template <D3D9_COMMON_BUFFER_TYPE Type>
    inline const Rc<DxvkBuffer>& GetBuffer() const {
      if constexpr (Type == D3D9_COMMON_BUFFER_TYPE_MAPPING)
        return GetMapBuffer();
      else if constexpr (Type == D3D9_COMMON_BUFFER_TYPE_STAGING)
        return GetStagingBuffer();
      else //if constexpr (Type == D3D9_COMMON_BUFFER_TYPE_REAL)
        return GetRealBuffer();
    }

    template <D3D9_COMMON_BUFFER_TYPE Type>
    inline DxvkBufferSlice GetBufferSlice() const {
      return GetBufferSlice<Type>(0, m_desc.Size);
    }

    template <D3D9_COMMON_BUFFER_TYPE Type>
    inline DxvkBufferSlice GetBufferSlice(VkDeviceSize offset) const {
      return GetBufferSlice<Type>(offset, m_desc.Size - offset);
    }

    template <D3D9_COMMON_BUFFER_TYPE Type>
    inline DxvkBufferSlice GetBufferSlice(VkDeviceSize offset, VkDeviceSize length) const {
      return DxvkBufferSlice(GetBuffer<Type>(), offset, length);
    }

    inline DxvkBufferSliceHandle AllocMapSlice() {
      return GetMapBuffer()->allocSlice();
    }

    inline DxvkBufferSliceHandle DiscardMapSlice() {
      m_sliceHandle = GetMapBuffer()->allocSlice();
      return m_sliceHandle;
    }

    inline DxvkBufferSliceHandle GetMappedSlice() const {
      return m_sliceHandle;
    }

    inline DWORD GetMapFlags() const      { return m_mapFlags; }
    inline void SetMapFlags(DWORD Flags)  { m_mapFlags = Flags; }

    inline const D3D9_BUFFER_DESC* Desc() const { return &m_desc; }

    static HRESULT ValidateBufferProperties(const D3D9_BUFFER_DESC* pDesc);

    /**
     * \brief The range of the buffer that was changed using Lock calls
     */
    inline D3D9Range& DirtyRange()  { return m_dirtyRange; }

    /**
     * \brief The range of the buffer that might currently be read by the GPU
     */
    inline D3D9Range& GPUReadingRange() { return m_gpuReadingRange; }

    /**
    * \brief Whether or not the buffer was written to by the GPU (in IDirect3DDevice9::ProcessVertices)
    */
    inline bool WasWrittenByGPU() const     { return m_wasWrittenByGPU; }

    /**
    * \brief Sets whether or not the buffer was written to by the GPU
    */
    inline void SetWrittenByGPU(bool state) { m_wasWrittenByGPU = state; }

    inline uint32_t IncrementLockCount() { return ++m_lockCount; }
    inline uint32_t DecrementLockCount() {
      if (m_lockCount == 0)
        return 0;

      return --m_lockCount;
    }
    inline uint32_t GetLockCount() const { return m_lockCount; }

    /**
     * \brief Whether or not the staging buffer needs to be copied to the actual buffer
     */
    inline bool NeedsUpload() { return m_desc.Pool != D3DPOOL_DEFAULT && !m_dirtyRange.IsDegenerate(); }

    inline bool DoesStagingBufferUploads() const { return m_uploadUsingStaging; }

    inline void EnableStagingBufferUploads() {
      if (GetMapMode() != D3D9_COMMON_BUFFER_MAP_MODE_BUFFER)
        return;

      m_uploadUsingStaging = true;
    }

    void PreLoad();

  private:

    Rc<DxvkBuffer> CreateBuffer() const;
    Rc<DxvkBuffer> CreateStagingBuffer() const;

    inline const Rc<DxvkBuffer>& GetMapBuffer() const {
      return m_stagingBuffer != nullptr ? m_stagingBuffer : m_buffer;
    }

    inline const Rc<DxvkBuffer>& GetStagingBuffer() const {
      return m_stagingBuffer;
    }

    inline const Rc<DxvkBuffer>& GetRealBuffer() const {
      return m_buffer;
    }

    D3D9DeviceEx*               m_parent;
    const D3D9_BUFFER_DESC      m_desc;
    DWORD                       m_mapFlags;
    bool                        m_wasWrittenByGPU = false;
    bool                        m_uploadUsingStaging = false;

    Rc<DxvkBuffer>              m_buffer;
    Rc<DxvkBuffer>              m_stagingBuffer;

    DxvkBufferSliceHandle       m_sliceHandle;

    D3D9Range                   m_dirtyRange;
    D3D9Range                   m_gpuReadingRange;

    uint32_t                    m_lockCount = 0;

  };

}