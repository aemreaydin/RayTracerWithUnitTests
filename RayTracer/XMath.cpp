#include "XMath.h"

#include <cmath>

const auto EPSILON = 0.00000001F;

bool XMath::IsEqual(const float a, const float b) {
	return (fabs(a - b) < EPSILON);
}