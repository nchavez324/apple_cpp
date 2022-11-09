#pragma once

#include <objc/runtime.h>

#include "NSDefines.hpp"

#define _AK_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _AK_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

#if defined(AK_PRIVATE_IMPLEMENTATION)

#define _AK_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define _AK_PRIVATE_IMPORT __attribute__((weak_import))

#if __OBJC__
#define _AK_PRIVATE_OBJC_LOOKUP_CLASS(symbol) \
  ((__bridge void*)objc_lookUpClass(#symbol))
#else
#define _AK_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#endif  // __OBJC__

#define _AK_PRIVATE_DEF_CLS(symbol)          \
  void* s_k##symbol _AK_PRIVATE_VISIBILITY = \
      _AK_PRIVATE_OBJC_LOOKUP_CLASS(symbol);
#define _AK_PRIVATE_DEF_PRO(symbol)
#define _AK_PRIVATE_DEF_SEL(accessor, symbol) \
  SEL s_k##accessor _AK_PRIVATE_VISIBILITY = sel_registerName(symbol);
#define _AK_PRIVATE_DEF_STR(type, symbol)              \
  _AK_EXTERN type const NS##symbol _AK_PRIVATE_IMPORT; \
  type const NS::symbol = (nullptr != &NS##symbol) ? NS##symbol : nullptr;

#else

#define _AK_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _AK_PRIVATE_DEF_PRO(symbol)
#define _AK_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _AK_PRIVATE_DEF_STR(type, symbol)

#endif  // AK_PRIVATE_IMPLEMENTATION

namespace NS {
namespace Private {
namespace Class {
_AK_PRIVATE_DEF_CLS(NSOpenGLContext);
_AK_PRIVATE_DEF_CLS(NSOpenGLPixelFormat);
_AK_PRIVATE_DEF_CLS(NSOpenGLView);
}  // namespace Class
}  // namespace Private
}  // namespace NS

namespace NS {
namespace Private {
namespace Protocol {}  // namespace Protocol
}  // namespace Private
}  // namespace NS

namespace NS {
namespace Private {
namespace Selector {
_AK_PRIVATE_DEF_SEL(clearCurrentContext, "clearCurrentContext");
_AK_PRIVATE_DEF_SEL(currentContext, "currentContext");
_AK_PRIVATE_DEF_SEL(flushBuffer, "flushBuffer");
_AK_PRIVATE_DEF_SEL(init_, "init:");
_AK_PRIVATE_DEF_SEL(initWithAttributes_, "initWithAttributes:");
_AK_PRIVATE_DEF_SEL(initWithFormat_shareContext_,
                    "initWithFormat:shareContext:");
_AK_PRIVATE_DEF_SEL(makeCurrentContext, "makeCurrentContext");
_AK_PRIVATE_DEF_SEL(openGLContext, "openGLContext");
_AK_PRIVATE_DEF_SEL(pixelFormat, "pixelFormat");
_AK_PRIVATE_DEF_SEL(setOpenGLContext_, "setOpenGLContext:");
_AK_PRIVATE_DEF_SEL(setPixelFormat_, "setPixelFormat:");
_AK_PRIVATE_DEF_SEL(setWantsBestResolutionOpenGLSurface_,
                    "setWantsBestResolutionOpenGLSurface:");
_AK_PRIVATE_DEF_SEL(wantsBestResolutionOpenGLSurface,
                    "wantsBestResolutionOpenGLSurface");
}  // namespace Selector
}  // namespace Private
}  // namespace NS
