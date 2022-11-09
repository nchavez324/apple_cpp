#pragma once

#include <Foundation/Foundation.hpp>

#include "EAGLDefines.hpp"
#include "EAGLPrivate.hpp"
#include "EAGLTypes.hpp"

namespace EAGL {

_EAGL_ENUM(NS::UInteger, RenderingAPI){
    RenderingAPIOpenGLES1 = 1,
    RenderingAPIOpenGLES2 = 2,
    RenderingAPIOpenGLES3 = 3,
};

}  // namespace EAGL
