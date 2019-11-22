#pragma once
#include <cmath>


class XMath {
public:
	static constexpr auto EPSILON = 0.00000001F;
	static bool IsEqual(const float a, const float b) {
		return (fabs(a - b) < EPSILON);
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


template<typename T>
class XVectorMath {
public:
	static float Magnitude(const T& vec) {
		return sqrtf(powf(vec.X, 2.0F) + powf(vec.Y, 2.0F) + powf(vec.Z, 2.0F));
	}

	static T Normalize(const T& vec) {
		return vec / Magnitude(vec);
	}

	static float DotProduct(const T& vecA, const T& vecB) {
		return (vecA.X * vecB.X) + (vecA.Y * vecB.Y) + (vecA.Z * vecB.Z);
	}

	static T CrossProduct(const T& vecA, const T& vecB) {
		return T{
			vecA.Y * vecB.Z - vecA.Z * vecB.Y,
			vecA.Z * vecB.X - vecA.X * vecB.Z,
			vecA.X * vecB.Y - vecA.Y * vecB.X
		};
	}
};