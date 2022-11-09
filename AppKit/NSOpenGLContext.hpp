#pragma once

#include "../Foundation/NSObject.hpp"
#include "NSDefines.hpp"
#include "NSOpenGLPixelFormat.hpp"
#include "NSPrivate.hpp"

namespace NS {
class OpenGLContext : public NS::Referencing<OpenGLContext> {
 public:
  static OpenGLContext* alloc();
  OpenGLContext* init(OpenGLPixelFormat* pixel_format,
                      OpenGLContext* share_context);

  static void clearCurrentContext();
  static OpenGLContext* currentContext();
  void makeCurrentContext();

  void flushBuffer();
};
}  // namespace NS

_AK_INLINE NS::OpenGLContext* NS::OpenGLContext::alloc() {
  return NS::Object::sendMessage<NS::OpenGLContext*>(
      _AK_PRIVATE_CLS(NSOpenGLContext), _AK_PRIVATE_SEL(alloc));
}

_AK_INLINE NS::OpenGLContext* NS::OpenGLContext::init(
    NS::OpenGLPixelFormat* pixel_format, NS::OpenGLContext* share_context) {
  return NS::Object::sendMessage<NS::OpenGLContext*>(
      this, _AK_PRIVATE_SEL(initWithFormat_shareContext_), pixel_format,
      share_context);
}

_AK_INLINE void NS::OpenGLContext::clearCurrentContext() {
  NS::Object::sendMessage<NS::OpenGLContext*>(
      _AK_PRIVATE_CLS(NSOpenGLContext), _AK_PRIVATE_SEL(clearCurrentContext));
}

_AK_INLINE NS::OpenGLContext* NS::OpenGLContext::currentContext() {
  return NS::Object::sendMessage<NS::OpenGLContext*>(
      _AK_PRIVATE_CLS(NSOpenGLContext), _AK_PRIVATE_SEL(currentContext));
}

_AK_INLINE void NS::OpenGLContext::makeCurrentContext() {
  NS::Object::sendMessage<NS::OpenGLContext*>(
      this, _AK_PRIVATE_SEL(makeCurrentContext));
}

_AK_INLINE void NS::OpenGLContext::flushBuffer() {
  NS::Object::sendMessage<NS::OpenGLContext*>(this,
                                              _AK_PRIVATE_SEL(flushBuffer));
}
