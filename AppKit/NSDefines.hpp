#pragma once

#include "../Foundation/NSDefines.hpp"

#define _AK_EXPORT _NS_EXPORT
#define _AK_EXTERN _NS_EXTERN
#define _AK_INLINE _NS_INLINE
#define _AK_PACKED _NS_PACKED

#define _AK_CONST(type, name) _NS_CONST(type, name)
#define _AK_ENUM(type, name) _NS_ENUM(type, name)
#define _AK_OPTIONS(type, name) _NS_OPTIONS(type, name)

#define _AK_VALIDATE_SIZE(ns, name) _NS_VALIDATE_SIZE(ns, name)
#define _AK_VALIDATE_ENUM(ns, name) _NS_VALIDATE_ENUM(ns, name)
