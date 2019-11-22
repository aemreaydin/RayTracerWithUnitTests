#pragma once
#include <iostream>

struct XVec3 {
	float X, Y, Z;
	float R, G, B;

	XVec3();
	XVec3(float x, float y, float z);
};

XVec3 operator+(const XVec3& lhs, const XVec3& rhs);
XVec3 operator-(const XVec3& lhs, const XVec3& rhs);
XVec3 operator-(const XVec3& lhs);
XVec3 operator-(const XVec3& lhs, float value);
XVec3 operator*(const XVec3& lhs, const XVec3& rhs);
XVec3 operator*(const XVec3& lhs, float scale);
XVec3 operator/(const XVec3& lhs, float scale);
bool operator==(const XVec3& lhs, const XVec3& rhs);
std::ostream& operator<< (std::ostream& stream, const XVec3 vec);

struct XVec4 {
	float X, R;
	float Y, G;
	float Z, B;
	float W, A;

	XVec4();
	XVec4(float x, float y, float z, float w = 1.0F);
	explicit XVec4(const XVec3& vec3, float w = 1.0F);

	XVec4& operator=(const XVec4& other);

	bool IsPoint() const;
};

XVec4 operator+(const XVec4& lhs, const XVec4& rhs);
XVec4 operator-(const XVec4& lhs, const XVec4& rhs);
XVec4 operator-(const XVec4& lhs);
XVec4 operator-(const XVec4& lhs, float value);
XVec4 operator*(const XVec4& lhs, float scale);
XVec4 operator/(const XVec4& lhs, float scale);
bool operator==(const XVec4& lhs, const XVec4& rhs);
