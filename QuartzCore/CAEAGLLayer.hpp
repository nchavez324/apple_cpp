#pragma once

#include "../Foundation/NSDictionary.hpp"
#include "../Foundation/NSObject.hpp"
#include "../OpenGLES/EAGLDrawable.hpp"
#include "CADefines.hpp"
#include "CAPrivate.hpp"

namespace CA {
class EAGLLayer : public NS::Referencing<EAGLLayer, EAGL::Drawable> {
 public:
  static EAGLLayer* layer();
  static EAGLLayer* alloc();
  EAGLLayer* init();

  bool opaque();
  // TODO: For some reason the linker doesn't find the ObjC method :/
  void setOpaque(bool opaque);
};
}  // namespace CA

_CA_INLINE CA::EAGLLayer* CA::EAGLLayer::layer() {
  return NS::Object::sendMessage<EAGLLayer*>(_CA_PRIVATE_CLS(CAEAGLLayer),
                                             _CA_PRIVATE_SEL(layer));
}

_CA_INLINE CA::EAGLLayer* CA::EAGLLayer::alloc() {
  return NS::Object::sendMessage<EAGLLayer*>(_CA_PRIVATE_CLS(CAEAGLLayer),
                                             _CA_PRIVATE_SEL(alloc));
}

_CA_INLINE CA::EAGLLayer* CA::EAGLLayer::init() {
  return NS::Object::sendMessage<EAGLLayer*>(this, _CA_PRIVATE_SEL(init));
}

_CA_INLINE bool CA::EAGLLayer::opaque() {
  return NS::Object::sendMessage<bool>(this, _CA_PRIVATE_SEL(opaque));
}

_CA_INLINE void CA::EAGLLayer::setOpaque(bool opaque) {
  NS::Object::sendMessage<void>(this, _CA_PRIVATE_SEL(setOpaque_), opaque);
}
