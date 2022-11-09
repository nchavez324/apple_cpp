#pragma once

#include <Foundation/Foundation.hpp>

#include "EAGLDefines.hpp"
#include "EAGLPrivate.hpp"

namespace EAGL {

_EAGL_CONST(NS::String*, DrawablePropertyRetainedBacking);
_EAGL_CONST(NS::String*, DrawablePropertyColorFormat);

_EAGL_CONST(NS::String*, ColorFormatRGBA8);
_EAGL_CONST(NS::String*, ColorFormatRGB565);
_EAGL_CONST(NS::String*, ColorFormatSRGBA8);

class Drawable : public NS::Referencing<Drawable> {
 public:
  NS::Dictionary* drawableProperties();
  void setDrawableProperties(NS::Dictionary* drawable_properties);
};

}  // namespace EAGL

_EAGL_PRIVATE_DEF_STR(NS::String*, DrawablePropertyRetainedBacking);
_EAGL_PRIVATE_DEF_STR(NS::String*, DrawablePropertyColorFormat);

_EAGL_PRIVATE_DEF_STR(NS::String*, ColorFormatRGBA8);
_EAGL_PRIVATE_DEF_STR(NS::String*, ColorFormatRGB565);
_EAGL_PRIVATE_DEF_STR(NS::String*, ColorFormatSRGBA8);

_EAGL_INLINE NS::Dictionary* EAGL::Drawable::drawableProperties() {
  return NS::Object::sendMessage<NS::Dictionary*>(
      this, _EAGL_PRIVATE_SEL(drawableProperties));
}

_EAGL_INLINE void EAGL::Drawable::setDrawableProperties(
    NS::Dictionary* drawable_properties) {
  NS::Object::sendMessage<NS::Dictionary *>(
      this, _EAGL_PRIVATE_SEL(setDrawableProperties_), drawable_properties);
}
