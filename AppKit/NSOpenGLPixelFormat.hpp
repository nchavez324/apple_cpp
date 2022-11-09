#pragma once

#include "../Foundation/NSObject.hpp"
#include "NSDefines.hpp"
#include "NSPrivate.hpp"
#include "NSTypes.hpp"

namespace NS {
class OpenGLPixelFormat : public NS::Referencing<OpenGLPixelFormat> {
 public:
  static OpenGLPixelFormat* alloc();
  OpenGLPixelFormat* init(OpenGLPixelFormatAttribute* attributes);
};
}  // namespace NS

_AK_INLINE NS::OpenGLPixelFormat* NS::OpenGLPixelFormat::alloc() {
  return NS::Object::sendMessage<NS::OpenGLPixelFormat*>(
      _AK_PRIVATE_CLS(NSOpenGLPixelFormat), _AK_PRIVATE_SEL(alloc));
}

_AK_INLINE NS::OpenGLPixelFormat* NS::OpenGLPixelFormat::init(
    OpenGLPixelFormatAttribute* attributes) {
  return NS::Object::sendMessage<NS::OpenGLPixelFormat*>(
      this, _AK_PRIVATE_SEL(initWithAttributes_), attributes);
}
