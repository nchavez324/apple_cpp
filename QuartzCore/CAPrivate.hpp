#pragma once

#include "CADefines.hpp"

#include <objc/runtime.h>

#define _CA_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _CA_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

#if defined(CA_PRIVATE_IMPLEMENTATION)

#define _CA_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define _CA_PRIVATE_IMPORT __attribute__((weak_import))

#if __OBJC__
#define _CA_PRIVATE_OBJC_LOOKUP_CLASS(symbol) ((__bridge void*)objc_lookUpClass(#symbol))
#else
#define _CA_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#endif // __OBJC__

#define _CA_PRIVATE_DEF_CLS(symbol) void* s_k##symbol _CA_PRIVATE_VISIBILITY = _CA_PRIVATE_OBJC_LOOKUP_CLASS(symbol);
#define _CA_PRIVATE_DEF_PRO(symbol)
#define _CA_PRIVATE_DEF_SEL(accessor, symbol) SEL s_k##accessor _CA_PRIVATE_VISIBILITY = sel_registerName(symbol);
#define _CA_PRIVATE_DEF_STR(type, symbol)                \
    _CA_EXTERN type const CA##symbol _CA_PRIVATE_IMPORT; \
    type const                       CA::symbol = (nullptr != &CA##symbol) ? CA##symbol : nullptr;

#else

#define _CA_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _CA_PRIVATE_DEF_PRO(symbol)
#define _CA_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _CA_PRIVATE_DEF_STR(type, symbol)

#endif // CA_PRIVATE_IMPLEMENTATION


namespace CA
{
namespace Private
{
    namespace Class
    {

        _CA_PRIVATE_DEF_CLS(CAEAGLLayer);
        _CA_PRIVATE_DEF_CLS(CAMetalLayer);

    } // Class
} // Private
} // CA

namespace CA
{
namespace Private
{
    namespace Protocol
    {

        _CA_PRIVATE_DEF_PRO(CAMetalDrawable);

    } // Protocol
} // Private
} // CA

namespace CA
{
namespace Private
{
    namespace Selector
    {

        _CA_PRIVATE_DEF_SEL(alloc,
            "alloc");
        _CA_PRIVATE_DEF_SEL(device,
            "device");
        _CA_PRIVATE_DEF_SEL(drawableSize,
            "drawableSize");    
        _CA_PRIVATE_DEF_SEL(framebufferOnly,
            "framebufferOnly");
        _CA_PRIVATE_DEF_SEL(init,
            "init");
        _CA_PRIVATE_DEF_SEL(layer,
            "layer");
        _CA_PRIVATE_DEF_SEL(nextDrawable,
            "nextDrawable");
        _CA_PRIVATE_DEF_SEL(opaque,
            "opaque");
        _CA_PRIVATE_DEF_SEL(pixelFormat,
            "pixelFormat");
        _CA_PRIVATE_DEF_SEL(setDevice_,
            "setDevice:");
        _CA_PRIVATE_DEF_SEL(setDrawableSize_,
            "setDrawableSize:");
        _CA_PRIVATE_DEF_SEL(setFramebufferOnly_,
            "setFramebufferOnly:");
        _CA_PRIVATE_DEF_SEL(setOpaque_,
            "setOpaque:");
        _CA_PRIVATE_DEF_SEL(setPixelFormat_,
            "setPixelFormat:");
        _CA_PRIVATE_DEF_SEL(texture,
            "texture");

    } // Class
} // Private
} // CA
