#pragma once

#include "../Foundation/NSObject.hpp"
#include "EAGLDefines.hpp"
#include "EAGLDrawable.hpp"
#include "EAGLPrivate.hpp"
#include "EAGLTypes.hpp"

namespace EAGL {
class Context : public NS::Referencing<Context> {
 public:
  static Context* alloc();
  Context* init(RenderingAPI rendering_api);

  static Context* currentContext();
  static bool setCurrentContext(Context* context);

  bool renderbufferStorage(NS::UInteger target, Drawable* drawable);
  bool presentRenderbuffer(NS::UInteger target);
};
}  // namespace EAGL

_EAGL_INLINE EAGL::Context* EAGL::Context::alloc() {
  return NS::Object::sendMessage<EAGL::Context*>(_NS_PRIVATE_CLS(EAGLContext),
                                                 _NS_PRIVATE_SEL(alloc));
}

_EAGL_INLINE EAGL::Context* EAGL::Context::init(
    EAGL::RenderingAPI rendering_api) {
  return NS::Object::sendMessage<EAGL::Context*>(
      this, _NS_PRIVATE_SEL(initWithAPI_), rendering_api);
}

_EAGL_INLINE EAGL::Context* EAGL::Context::currentContext() {
  return NS::Object::sendMessage<EAGL::Context*>(
      _NS_PRIVATE_CLS(EAGLContext), _NS_PRIVATE_SEL(currentContext));
}

_EAGL_INLINE bool EAGL::Context::setCurrentContext(EAGL::Context* context) {
  return NS::Object::sendMessage<bool>(_NS_PRIVATE_CLS(EAGLContext),
                                       _NS_PRIVATE_SEL(setCurrentContext_),
                                       context);
}

_EAGL_INLINE bool EAGL::Context::renderbufferStorage(NS::UInteger target,
                                                     EAGL::Drawable* drawable) {
  return NS::Object::sendMessage<bool>(
      this, _NS_PRIVATE_SEL(renderbufferStorage_fromDrawable_), target,
      drawable);
}

_EAGL_INLINE bool EAGL::Context::presentRenderbuffer(NS::UInteger target) {
  return NS::Object::sendMessage<bool>(
      this, _NS_PRIVATE_SEL(presentRenderbuffer_), target);
}
