#pragma once
#include <cmath>

using Uint32 = uint32_t;
static constexpr auto EPSILON = 1e-8;

class XMath {
public:
	static bool IsNearlyEqual(const float a, const float b, const float epsilon = EPSILON) {
		return (fabs(a - b) < epsilon);
	}
	template<typename T>
	static T Clamp(T value, const T min, const T max) {
		if(value < min)
			value = min;
		else if(value > max)
			value = max;
		return value;
	}
};


