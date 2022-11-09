#pragma once

#include "../Foundation/NSObject.hpp"
#include "NSDefines.hpp"
#include "NSOpenGLContext.hpp"
#include "NSOpenGLPixelFormat.hpp"
#include "NSPrivate.hpp"

namespace NS {
class OpenGLView : public NS::Referencing<OpenGLView> {
 public:
  OpenGLPixelFormat* pixelFormat();
  void setPixelFormat(OpenGLPixelFormat* pixel_format);

  OpenGLContext* openGLContext();
  void setOpenGLContext(OpenGLContext* open_gl_context);

  bool wantsBestResolutionOpenGLSurface();
  void setWantsBestResolutionOpenGLSurface(bool value);
};
}  // namespace NS

_AK_INLINE NS::OpenGLPixelFormat* NS::OpenGLView::pixelFormat() {
  return NS::Object::sendMessage<NS::OpenGLPixelFormat*>(
      this, _AK_PRIVATE_SEL(pixelFormat));
}

_AK_INLINE void NS::OpenGLView::setPixelFormat(
    NS::OpenGLPixelFormat* pixel_format) {
  NS::Object::sendMessage<void>(this, _AK_PRIVATE_SEL(setPixelFormat_),
                                pixel_format);
}

_AK_INLINE NS::OpenGLContext* NS::OpenGLView::openGLContext() {
  return NS::Object::sendMessage<NS::OpenGLContext*>(
      this, _AK_PRIVATE_SEL(openGLContext));
}

_AK_INLINE void NS::OpenGLView::setOpenGLContext(
    NS::OpenGLContext* open_gl_context) {
  NS::Object::sendMessage<void>(this, _AK_PRIVATE_SEL(setOpenGLContext_),
                                open_gl_context);
}

_AK_INLINE bool NS::OpenGLView::wantsBestResolutionOpenGLSurface() {
  return NS::Object::sendMessage<bool>(
      this, _AK_PRIVATE_SEL(wantsBestResolutionOpenGLSurface));
}

_AK_INLINE void NS::OpenGLView::setWantsBestResolutionOpenGLSurface(
    bool value) {
  NS::Object::sendMessage<void>(
      this, _AK_PRIVATE_SEL(setWantsBestResolutionOpenGLSurface_), value);
}
