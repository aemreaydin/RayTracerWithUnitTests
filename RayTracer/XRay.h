#pragma once

#include "XVector.h"

struct XRay
{
	XVector Origin;
	XVector Direction;

	XRay(const XVector origin, const XVector direction);
	
	XVector PointAtTimeT(float t) const;
};

inline XRay::XRay(const XVector origin, const XVector direction) : Origin(origin), Direction(direction)
	{}

inline XVector XRay::PointAtTimeT(const float t) const
{
	return Origin + Direction * t;
}
