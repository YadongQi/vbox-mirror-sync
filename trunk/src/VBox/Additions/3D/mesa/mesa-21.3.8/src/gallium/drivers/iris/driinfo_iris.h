// iris specific driconf options

DRI_CONF_SECTION_DEBUG
   DRI_CONF_DUAL_COLOR_BLEND_BY_LOCATION(false)
   DRI_CONF_DISABLE_THROTTLING(false)
   DRI_CONF_ALWAYS_FLUSH_CACHE(false)
   DRI_CONF_OPT_B(sync_compile, false, "Always compile synchronously (will cause stalls)")
DRI_CONF_SECTION_END

DRI_CONF_SECTION_PERFORMANCE
   DRI_CONF_OPT_E(bo_reuse, 1, 0, 1, "Buffer object reuse",)
DRI_CONF_SECTION_END
