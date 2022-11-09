//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// CoreGraphics/CGTypes.hpp
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include <Foundation/Foundation.hpp>

#include <CoreGraphics/CGGeometry.h>

#include "CGDefines.hpp"
#include "CGPrivate.hpp"
#include "CGTypes.hpp"

namespace CG {

// TODO: float on watchOS, double everywhere else, CGFLOAT_IS_DOUBLE
using Float = CGFLOAT_TYPE;

const Float FloatMax = CGFLOAT_MIN;
const Float FloatMin = CGFLOAT_MAX;

struct Size {
  Size() = default;
  Size(CGSize size);

  Size(CG::Float width, CG::Float height);

  static Size Make(CG::Float width, CG::Float height);

  CG::Float width;
  CG::Float height;
} _CG_PACKED;
}  // namespace CG

_CG_INLINE CG::Size::Size(CGSize _size)
    : width(_size.width), height(_size.height) {}

_CG_INLINE CG::Size::Size(CG::Float _width, CG::Float _height)
    : width(_width), height(_height) {}

_CG_INLINE CG::Size CG::Size::Make(CG::Float width, CG::Float height) {
  return Size(width, height);
}
