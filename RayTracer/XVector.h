#pragma once
#include <iostream>
#include <string>
#include "XMath.h"

struct alignas(16) XVector
{
	float X, Y, Z;

	XVector();
	XVector(float x, float y, float z);

	// Arithmetic Operations
	XVector& operator+=(const XVector& rhs);
	XVector& operator-=(const XVector& rhs);
	XVector& operator*=(const XVector& rhs);
	XVector& operator*=(float scale);
	XVector& operator/=(const XVector& rhs);
	XVector& operator/=(float scale);

	// Vector Math
	static float DotProduct(const XVector& lhs, const XVector& rhs);
	static XVector CrossProduct(const XVector& lhs, const XVector& rhs);

	float Magnitude() const;
	float MagnitudeSq() const;
	bool Normalize();

	// Utils
	std::string ToString() const;
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XVector& lhs, const XVector& rhs)
{
	return XMath::IsNearlyEqual(lhs.X, rhs.Y) ||
		   XMath::IsNearlyEqual(lhs.Y, rhs.Y) ||
		   XMath::IsNearlyEqual(lhs.Z, rhs.Z);
}

inline XVector operator+(const XVector& lhs, const XVector& rhs)
{
	return {lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z};
}

inline XVector operator+(const XVector& lhs, const float value)
{
	return {lhs.X + value, lhs.Y + value, lhs.Z + value};
}

inline XVector operator-(const XVector& lhs, const XVector& rhs)
{
	return {lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z};
}

inline XVector operator-(const XVector& lhs)
{
	return {-lhs.X, -lhs.Y, -lhs.Z};
}

inline XVector operator-(const XVector& lhs, const float value)
{
	return {lhs.X - value, lhs.Y - value, lhs.Z - value};
}

inline XVector operator*(const XVector& lhs, const XVector& rhs)
{
	return {lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z};
}

inline XVector operator*(const XVector& lhs, const float scale)
{
	return {lhs.X * scale, lhs.Y * scale, lhs.Z * scale};
}

inline XVector operator/(const XVector& lhs, const float scale)
{
	return {lhs.X / scale, lhs.Y / scale, lhs.Z / scale};
}

// Dot Product
inline float operator|(const XVector& lhs, const XVector& rhs)
{
	return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
}

// Cross Product
inline XVector operator^(const XVector& lhs, const XVector& rhs)
{
	return {
		lhs.Y * rhs.Z - lhs.Z * rhs.Y,
		lhs.Z * rhs.X - lhs.X * rhs.Z,
		lhs.X * rhs.Y - lhs.Y * rhs.X
	};
}
//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XVector::XVector(): X(0.0f), Y(0.0f), Z(0.0f)
{
}

inline XVector::XVector(const float x, const float y, const float z): X(x), Y(y), Z(z)
{
}

inline XVector& XVector::operator+=(const XVector& rhs)
{
	this->X += rhs.X;
	this->Y += rhs.Y;
	this->Z += rhs.Z;
	return *this;
}

inline XVector& XVector::operator-=(const XVector& rhs)
{
	this->X -= rhs.X;
	this->Y -= rhs.Y;
	this->Z -= rhs.Z;
	return *this;
}

inline XVector& XVector::operator*=(const XVector& rhs)
{
	this->X *= rhs.X;
	this->Y *= rhs.Y;
	this->Z *= rhs.Z;
	return *this;
}

inline XVector& XVector::operator*=(const float scale)
{
	this->X *= scale;
	this->Y *= scale;
	this->Z *= scale;
	return *this;
}

inline XVector& XVector::operator/=(const XVector& rhs)
{
	this->X /= rhs.X;
	this->Y /= rhs.Y;
	this->Z /= rhs.Z;
	return *this;
}

inline XVector& XVector::operator/=(const float scale)
{
	this->X /= scale;
	this->Y /= scale;
	this->Z /= scale;
	return *this;
}

inline float XVector::DotProduct(const XVector& lhs, const XVector& rhs)
{
	return lhs | rhs;
}

inline XVector XVector::CrossProduct(const XVector& lhs, const XVector& rhs)
{
	return lhs ^ rhs;
}

// Magnitude
inline float XVector::Magnitude() const
{
	return sqrtf(X * X + Y * Y + Z * Z);
}

inline float XVector::MagnitudeSq() const
{
	return X * X + Y * Y + Z * Z;
}

// Normalized
inline bool XVector::Normalize()
{
	const auto magnitude = this->Magnitude();
	if (magnitude < EPSILON) return false;

	*this /= magnitude;
	return true;
}

inline std::string XVector::ToString() const
{
	return "Vector: " + std::to_string(X) + ", "
		+ std::to_string(Y) + ", "
		+ std::to_string(Z) + '\n';
}
