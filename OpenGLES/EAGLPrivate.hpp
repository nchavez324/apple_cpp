#pragma once

#include <objc/runtime.h>

#include "EAGLDefines.hpp"

#define _EAGL_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _EAGL_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

#if defined(EAGL_PRIVATE_IMPLEMENTATION)

#define _EAGL_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define _EAGL_PRIVATE_IMPORT __attribute__((weak_import))

#if __OBJC__
#define _EAGL_PRIVATE_OBJC_LOOKUP_CLASS(symbol) \
  ((__bridge void*)objc_lookUpClass(#symbol))
#else
#define _EAGL_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#endif  // __OBJC__

#define _EAGL_PRIVATE_DEF_CLS(symbol)          \
  void* s_k##symbol _EAGL_PRIVATE_VISIBILITY = \
      _EAGL_PRIVATE_OBJC_LOOKUP_CLASS(symbol);
#define _EAGL_PRIVATE_DEF_PRO(symbol)
#define _EAGL_PRIVATE_DEF_SEL(accessor, symbol) \
  SEL s_k##accessor _EAGL_PRIVATE_VISIBILITY = sel_registerName(symbol);
#define _EAGL_PRIVATE_DEF_STR(type, symbol)                   \
  _EAGL_EXTERN type const kEAGL##symbol _EAGL_PRIVATE_IMPORT; \
  type const EAGL::symbol =                                   \
      (nullptr != &kEAGL##symbol) ? kEAGL##symbol : nullptr;

#else

#define _EAGL_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _EAGL_PRIVATE_DEF_PRO(symbol)
#define _EAGL_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _EAGL_PRIVATE_DEF_STR(type, symbol)

#endif  // EAGL_PRIVATE_IMPLEMENTATION

namespace EAGL {
namespace Private {
namespace Class {
_EAGL_PRIVATE_DEF_CLS(EAGLContext);
}  // namespace Class
}  // namespace Private
}  // namespace EAGL

namespace EAGL {
namespace Private {
namespace Protocol {
_EAGL_PRIVATE_DEF_PRO(EAGLDrawable);
}  // namespace Protocol
}  // namespace Private
}  // namespace EAGL

namespace EAGL {
namespace Private {
namespace Selector {
_EAGL_PRIVATE_DEF_SEL(alloc, "alloc");
_EAGL_PRIVATE_DEF_SEL(initWithAPI_, "initWithAPI:");
_EAGL_PRIVATE_DEF_SEL(currentContext, "currentContext");
_EAGL_PRIVATE_DEF_SEL(drawableProperties, "drawableProperties");
_EAGL_PRIVATE_DEF_SEL(presentRenderbuffer_, "presentRenderbuffer:");
_EAGL_PRIVATE_DEF_SEL(renderbufferStorage_fromDrawable_,
                      "renderbufferStorage:fromDrawable:");
_EAGL_PRIVATE_DEF_SEL(setCurrentContext_, "setCurrentContext:");
_EAGL_PRIVATE_DEF_SEL(setDrawableProperties_, "setDrawableProperties:");
}  // namespace Selector
}  // namespace Private
}  // namespace EAGL
