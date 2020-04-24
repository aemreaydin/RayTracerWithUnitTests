#pragma once
#include "XVector.h"

struct XVector4
{
	float X;
	float Y;
	float Z;
	float W;

	XVector4();
	XVector4(float x,float y, float z, float w = 1.0F);
	explicit XVector4(const XVector& vec3, float w = 1.0F);

	// Arithmetic Operations
	XVector4& operator+=(const XVector4& rhs);
	XVector4& operator-=(const XVector4& rhs);
	XVector4& operator*=(const XVector4& rhs);
	XVector4& operator*=(float scale);
	XVector4& operator/=(float scale);

	std::string ToString() const;
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XVector4& lhs, const XVector4& rhs)
{
	return XMath::IsNearlyEqual(lhs.X, rhs.Y) &&
		   XMath::IsNearlyEqual(lhs.Y, rhs.Y) &&
		   XMath::IsNearlyEqual(lhs.Z, rhs.Z) &&
		   XMath::IsNearlyEqual(lhs.W, rhs.W);
}

inline XVector4 operator+(const XVector4& lhs, const XVector4& rhs)
{
	return {lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z};
}

inline XVector4 operator-(const XVector4& lhs, const XVector4& rhs)
{
	return {lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z, lhs.W - rhs.W};
}

inline XVector4 operator-(const XVector4& lhs, const float value)
{
	return {lhs.X - value, lhs.Y - value, lhs.Z - value, lhs.W - value};
}

inline XVector4 operator-(const XVector4& lhs)
{
	return {-lhs.X, -lhs.Y, -lhs.Z, -lhs.W};
}

inline XVector4 operator*(const XVector4& lhs, const XVector4& rhs)
{
	return {lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z, lhs.W * rhs.W};
}

inline XVector4 operator*(const XVector4& lhs, const float scale)
{
	return {lhs.X * scale, lhs.Y * scale, lhs.Z * scale, lhs.W * scale};
}

inline XVector4 operator/(const XVector4& lhs, const float scale)
{
	return {lhs.X / scale, lhs.Y / scale, lhs.Z / scale, lhs.W / scale};
}

// Dot Product
inline float operator|(const XVector4& lhs, const XVector4& rhs)
{
	return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
}

// Cross Product
inline XVector4 operator^(const XVector4& lhs, const XVector4& rhs)
{
	return {
		lhs.Y * rhs.Z - lhs.Z * rhs.Y,
		lhs.Z * rhs.X - lhs.X * rhs.Z,
		lhs.X * rhs.Y - lhs.Y * rhs.X,
		0.0f
	};
}
//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XVector4::XVector4(): X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
{
}

inline XVector4::XVector4(const float x, const float y, const float z, const float w): X(x), Y(y), Z(z), W(w)
{
}

inline XVector4::XVector4(const XVector& vec3, const float w): X(vec3.X), Y(vec3.Y), Z(vec3.Z), W(w)
{
}

inline XVector4& XVector4::operator+=(const XVector4& rhs)
{
	this->X += rhs.X;
	this->Y += rhs.Y;
	this->Z += rhs.Z;
	return *this;
}

inline XVector4& XVector4::operator-=(const XVector4& rhs)
{
	this->X -= rhs.X;
	this->Y -= rhs.Y;
	this->Z -= rhs.Z;
	return *this;
}

inline XVector4& XVector4::operator*=(const XVector4& rhs)
{
	this->X *= rhs.X;
	this->Y *= rhs.Y;
	this->Z *= rhs.Z;
	return *this;
}

inline XVector4& XVector4::operator*=(const float scale)
{
	this->X *= scale;
	this->Y *= scale;
	this->Z *= scale;
	return *this;
}

inline XVector4& XVector4::operator/=(const float scale)
{
	this->X /= scale;
	this->Y /= scale;
	this->Z /= scale;
	return *this;
}

inline std::string XVector4::ToString() const
{
	return "Vector: " + std::to_string(X) + ", "
	       + std::to_string(Y) + ", "
	       + std::to_string(Z) + ", "
	       + std::to_string(W) + '\n';
}
