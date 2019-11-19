#include "Math.h"

#include <cmath>

const auto EPSILON = 0.00000001F;

bool Math::IsEqual(const float _a, const float _b)
{
	return (fabs(_a - _b) < EPSILON);
}
