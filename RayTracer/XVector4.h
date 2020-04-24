#pragma once
#include "XVector.h"

struct XVector4
{
	float X;
	float Y;
	float Z;
	float W;

	XVector4() : X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
	{ }

	XVector4(const float x, const float y, const float z, const float w = 1.0F) : X(x), Y(y), Z(z), W(w)
	{ }

	explicit XVector4(const XVector& vec3, const float w = 1.0F) : X(vec3.X), Y(vec3.Y), Z(vec3.Z), W(w)
	{ }

	~XVector4() = default;
	XVector4(const XVector4& rhs) = default;
	XVector4(XVector4&& rhs) = default;
	XVector4& operator=(const XVector4& rhs) = default;
	XVector4& operator=(XVector4&& rhs) = default;

	XVector4& operator+=(const XVector4& rhs)
	{
		this->X += rhs.X;
		this->Y += rhs.Y;
		this->Z += rhs.Z;
		return *this;
	}

	XVector4& operator-=(const XVector4& rhs)
	{
		this->X -= rhs.X;
		this->Y -= rhs.Y;
		this->Z -= rhs.Z;
		return *this;
	}

	XVector4& operator*=(const XVector4& rhs)
	{
		this->X *= rhs.X;
		this->Y *= rhs.Y;
		this->Z *= rhs.Z;
		return *this;
	}

	XVector4& operator*=(const float scale)
	{
		this->X *= scale;
		this->Y *= scale;
		this->Z *= scale;
		return *this;
	}

	XVector4& operator/=(const float scale)
	{
		this->X /= scale;
		this->Y /= scale;
		this->Z /= scale;
		return *this;
	}

	std::string ToString() const;
};

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

inline bool operator==(const XVector4& lhs, const XVector4& rhs)
{
	return XMath::IsNearlyEqual(lhs.X, rhs.Y) ||
	       XMath::IsNearlyEqual(lhs.Y, rhs.Y) ||
	       XMath::IsNearlyEqual(lhs.Z, rhs.Z) ||
	       XMath::IsNearlyEqual(lhs.W, rhs.W);
}

inline std::string XVector4::ToString() const
{
	return "Vector: " + std::to_string(X) + ", "
	       + std::to_string(Y) + ", "
	       + std::to_string(Z) + ", "
	       + std::to_string(W) + '\n';
}
