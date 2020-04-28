#pragma once
#include <cmath>

using Uint32 = uint32_t;

static constexpr float PI = 3.1415926535897932f;
static constexpr float HALF_PI = 1.57079632679f;
static constexpr float EPSILON = 1e-8f;
static constexpr float SMALL_EPSILON = 1e-4f;

class XMath
{
public:
	static bool IsNearlyEqual(const float a, const float b, const float epsilon = EPSILON)
	{
		return (fabs(a - b) < epsilon);
	}

	template <typename T>
	static T Clamp(T value, const T min, const T max)
	{
		if (value < min)
			value = min;
		else if (value > max)
			value = max;
		return value;
	}
};
