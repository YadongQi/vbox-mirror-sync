#include "d3d11_enums.h"

std::ostream& operator << (std::ostream& os, D3D_FEATURE_LEVEL e) {
  switch (e) {
    ENUM_NAME(D3D_FEATURE_LEVEL_9_1);
    ENUM_NAME(D3D_FEATURE_LEVEL_9_2);
    ENUM_NAME(D3D_FEATURE_LEVEL_9_3);
    ENUM_NAME(D3D_FEATURE_LEVEL_10_0);
    ENUM_NAME(D3D_FEATURE_LEVEL_10_1);
    ENUM_NAME(D3D_FEATURE_LEVEL_11_0);
    ENUM_NAME(D3D_FEATURE_LEVEL_11_1);
    ENUM_DEFAULT(e);
  }
}
