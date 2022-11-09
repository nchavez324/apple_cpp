#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "../CoreGraphics/CGTypes.hpp"
#include "../Metal/MTLDevice.hpp"
#include "../Metal/MTLDrawable.hpp"
#include "../Metal/MTLPixelFormat.hpp"
#include "../Foundation/NSObject.hpp"

#include "CADefines.hpp"
#include "CAMetalDrawable.hpp"
#include "CAPrivate.hpp"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CA
{
class MetalLayer : public NS::Referencing<MetalLayer>
{
public:
    static MetalLayer*   layer();
    static MetalLayer*   alloc();
    MetalLayer*          init();

    class MTL::Device*   device();
    void                 setDevice(MTL::Device *device);

    MTL::PixelFormat     pixelFormat() const;
    void                 setPixelFormat(MTL::PixelFormat pixelFormat);

    bool                 framebufferOnly() const;
    void                 setFramebufferOnly(bool framebufferOnly);

    CG::Size             drawableSize() const;
    void                 setDrawableSize(CG::Size size);

    class MetalDrawable* nextDrawable();
};
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalLayer* CA::MetalLayer::alloc()
{
    return NS::Object::sendMessage<MetalLayer *>(_CA_PRIVATE_CLS(CAMetalLayer), _CA_PRIVATE_SEL(alloc));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalLayer* CA::MetalLayer::init()
{
    return NS::Object::sendMessage<MetalLayer *>(this, _CA_PRIVATE_SEL(init));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalLayer* CA::MetalLayer::layer()
{
    return NS::Object::sendMessage<MetalLayer *>(_CA_PRIVATE_CLS(CAMetalLayer), _CA_PRIVATE_SEL(layer));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE MTL::Device* CA::MetalLayer::device()
{
    return Object::sendMessage<MTL::Device*>(this, _CA_PRIVATE_SEL(device));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE void CA::MetalLayer::setDevice(MTL::Device* device)
{
    Object::sendMessage<void>(this, _CA_PRIVATE_SEL(setDevice_), device);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE MTL::PixelFormat CA::MetalLayer::pixelFormat() const
{
    return Object::sendMessage<MTL::PixelFormat>(this, _CA_PRIVATE_SEL(pixelFormat));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


_CA_INLINE void CA::MetalLayer::setPixelFormat(MTL::PixelFormat pixelFormat)
{
    Object::sendMessage<void>(this, _CA_PRIVATE_SEL(setPixelFormat_), pixelFormat);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE bool CA::MetalLayer::framebufferOnly() const
{
    return Object::sendMessage<bool>(this, _CA_PRIVATE_SEL(framebufferOnly));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------


_CA_INLINE void CA::MetalLayer::setFramebufferOnly(bool framebufferOnly)
{
    Object::sendMessage<void>(this, _CA_PRIVATE_SEL(setFramebufferOnly_), framebufferOnly);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CG::Size CA::MetalLayer::drawableSize() const
{
    return Object::sendMessage<CG::Size>(this, _CA_PRIVATE_SEL(drawableSize));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE void CA::MetalLayer::setDrawableSize(CG::Size size)
{
    Object::sendMessage<void>(this, _CA_PRIVATE_SEL(setDrawableSize_), size);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_CA_INLINE CA::MetalDrawable* CA::MetalLayer::nextDrawable()
{
    return Object::sendMessage<MetalDrawable*>(this, _CA_PRIVATE_SEL(nextDrawable));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
