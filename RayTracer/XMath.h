#pragma once

struct XVec3;
struct XVec4;

// TODO Remove W from the matrix operations as w is 0 on vectors and write a template???
class XMath {
public:
	static bool IsEqual(float a, float b);
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