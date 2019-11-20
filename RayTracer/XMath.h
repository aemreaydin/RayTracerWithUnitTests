#pragma once

struct XVec3;
struct XVec4;

// TODO Remove W from the matrix operations as w is 0 on vectors and write a template???
class XMath {
public:
	static bool IsEqual(float a, float b);

	template<typename T>
	static float Magnitude(const T& vec);
	
	template<typename T>
	static T Normalize(const T& vec);

	template<typename T>
	static float DotProduct(const T& vecA, const T& vecB);

	template<typename T>
	static T CrossProduct(const T& vecA, const T& vecB);
};



