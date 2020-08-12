/** @file
  GUIDs used for UEFI Properties Table in the UEFI 2.5 specification.

  Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef __EFI_PROPERTIES_TABLE_H__
#define __EFI_PROPERTIES_TABLE_H__

#define EFI_PROPERTIES_TABLE_GUID {\
  0x880aaca3, 0x4adc, 0x4a04, {0x90, 0x79, 0xb7, 0x47, 0x34, 0x8, 0x25, 0xe5} \
}

typedef struct {
  UINT32    Version;
  UINT32    Length;
  UINT64    MemoryProtectionAttribute;
} EFI_PROPERTIES_TABLE;

#define EFI_PROPERTIES_TABLE_VERSION  0x00010000

//
// Memory attribute (Not defined bit is reserved)
//
#define EFI_PROPERTIES_RUNTIME_MEMORY_PROTECTION_NON_EXECUTABLE_PE_DATA        0x1

extern EFI_GUID gEfiPropertiesTableGuid;

#endif
