#pragma once
#include <iostream>

struct alignas(16) XVector {
	float X, Y, Z;

	XVector();
	XVector(float x, float y, float z);

	XVector& operator+=(const XVector& rhs);
	XVector& operator*=(const XVector& rhs);
	XVector& operator*=(float scale);
};

XVector operator+(const XVector& lhs, const XVector& rhs);


XVector operator-(const XVector& lhs, const XVector& rhs);
XVector operator-(const XVector& lhs);
XVector operator-(const XVector& lhs, float value);


XVector operator*(const XVector& lhs, const XVector& rhs);

XVector operator*(const XVector& lhs, float scale);

XVector operator/(const XVector& lhs, float scale);
bool operator==(const XVector& lhs, const XVector& rhs);
std::ostream& operator<< (std::ostream& stream, const XVector vec);



struct XVector4 {
	float X;
	float Y;
	float Z;
	float W;

	XVector4();
	XVector4(float x, float y, float z, float w = 1.0F);
	explicit XVector4(const XVector& vec3, float w = 1.0F);

	XVector4& operator=(const XVector4& other);

	bool IsPoint() const;
};

XVector4 operator+(const XVector4& lhs, const XVector4& rhs);
XVector4 operator-(const XVector4& lhs, const XVector4& rhs);
XVector4 operator-(const XVector4& lhs);
XVector4 operator-(const XVector4& lhs, float value);
XVector4 operator*(const XVector4& lhs, float scale);
XVector4 operator/(const XVector4& lhs, float scale);
bool operator==(const XVector4& lhs, const XVector4& rhs);
