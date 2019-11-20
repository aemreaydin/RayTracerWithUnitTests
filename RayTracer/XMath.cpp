#include "XMath.h"
#include "XVector.h"

#include <cmath>

const auto EPSILON = 0.00000001F;

bool XMath::IsEqual(const float a, const float b) {
	return (fabs(a - b) < EPSILON);
}

template<typename T>
float XMath::Magnitude(const T& vec) {
	return sqrtf(powf(vec.X, 2.0F) + powf(vec.Y, 2.0F) + powf(vec.Z, 2.0F));
}

template<typename T>
T XMath::Normalize(const T& vec) {
	return vec / Magnitude(vec);
}

template<typename T>
float XMath::DotProduct(const T& vecA, const T& vecB) {
	return (vecA.X * vecB.X) + (vecA.Y * vecB.Y) + (vecA.Z * vecB.Z);
}

template<typename T>
T XMath::CrossProduct(const T& vecA, const T& vecB) {
	return T{
		vecA.Y * vecB.Z - vecA.Z * vecB.Y,
		vecA.Z * vecB.X - vecA.X * vecB.Z,
		vecA.X * vecB.Y - vecA.Y * vecB.X
	};
}
