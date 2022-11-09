//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// CoreGraphics/CGPrivate.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#include "CGDefines.hpp"

#include <objc/runtime.h>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#define _CG_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _CG_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#if defined(CG_PRIVATE_IMPLEMENTATION)

#define _CG_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#define _CG_PRIVATE_IMPORT __attribute__((weak_import))

#if __OBJC__
#define _CG_PRIVATE_OBJC_LOOKUP_CLASS(symbol) ((__bridge void*)objc_lookUpClass(#symbol))
#else
#define _CG_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#endif // __OBJC__

#define _CG_PRIVATE_DEF_CLS(symbol) void* s_k##symbol _CG_PRIVATE_VISIBILITY = _CG_PRIVATE_OBJC_LOOKUP_CLASS(symbol);
#define _CG_PRIVATE_DEF_PRO(symbol)
#define _CG_PRIVATE_DEF_SEL(accessor, symbol) SEL s_k##accessor _CG_PRIVATE_VISIBILITY = sel_registerName(symbol);
#define _CG_PRIVATE_DEF_STR(type, symbol)                \
    _CG_EXTERN type const CG##symbol _CG_PRIVATE_IMPORT; \
    type const                       CG::symbol = (nullptr != &CG##symbol) ? CG##symbol : nullptr;

#else

#define _CG_PRIVATE_DEF_CLS(symbol) extern void* s_k##symbol;
#define _CG_PRIVATE_DEF_PRO(symbol)
#define _CG_PRIVATE_DEF_SEL(accessor, symbol) extern SEL s_k##accessor;
#define _CG_PRIVATE_DEF_STR(type, symbol)

#endif // CG_PRIVATE_IMPLEMENTATION

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CG
{
namespace Private
{
    namespace Class
    {

    } // Class
} // Private
} // CG

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CG
{
namespace Private
{
    namespace Protocol
    {

    } // Protocol
} // Private
} // CG

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace CG
{
namespace Private
{
    namespace Selector
    {

    } // Class
} // Private
} // CG

//-------------------------------------------------------------------------------------------------------------------------------------------------------------
