#pragma once
#include "XVector4.h"

struct XColor
{
	XVector4 Color;

	XColor();
	XColor(float r, float g, float b, float a = 1.0f);
	explicit XColor(const XVector& rgb, float a = 1.0f);

	XColor& operator+=(const XColor& rhs);
	XColor& operator-=(const XColor& rhs);
	XColor& operator*=(const XColor& rhs);
	XColor& operator*=(float scale);

	std::string ToString() const;
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XColor& lhs, const XColor& rhs)
{
	return lhs.Color == rhs.Color;
}

inline XColor operator+(const XColor& lhs, const XColor& rhs)
{
	return {lhs.Color.X + rhs.Color.X, lhs.Color.Y + rhs.Color.Y, lhs.Color.Z + rhs.Color.Z, 1.0f};
}

inline XColor operator-(const XColor& lhs, const XColor& rhs)
{
	return {lhs.Color.X - rhs.Color.X, lhs.Color.Y - rhs.Color.Y, lhs.Color.Z - rhs.Color.Z, 1.0f};
}

inline XColor operator*(const XColor& lhs, const XColor& rhs)
{
	return {lhs.Color.X * rhs.Color.X, lhs.Color.Y * rhs.Color.Y, lhs.Color.Z * rhs.Color.Z, 1.0f};
}

inline XColor operator*(const XColor& lhs, const float scale)
{
	return {lhs.Color.X * scale, lhs.Color.Y * scale, lhs.Color.Z * scale, 1.0f};
}
//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XColor::XColor()
{
	Color.X = 0.0f;
	Color.Y = 0.0f;
	Color.Z = 0.0f;
	Color.W = 1.0f;
}

inline XColor::XColor(const float r, const float g, const float b, const float a)
{
	Color.X = r;
	Color.Y = g;
	Color.Z = b;
	Color.W = a;
}

inline XColor::XColor(const XVector& rgb, const float a)
{
	Color.X = rgb.X;
	Color.Y = rgb.Y;
	Color.Z = rgb.Z;
	Color.W = a;
}

inline XColor& XColor::operator+=(const XColor& rhs)
{
	Color.X += rhs.Color.X;
	Color.Y += rhs.Color.Y;
	Color.Z += rhs.Color.Z;

	return *this;
}

inline XColor& XColor::operator-=(const XColor& rhs)
{
	Color.X -= rhs.Color.X;
	Color.Y -= rhs.Color.Y;
	Color.Z -= rhs.Color.Z;

	return *this;
}

inline XColor& XColor::operator*=(const XColor& rhs)
{
	Color.X *= rhs.Color.X;
	Color.Y *= rhs.Color.Y;
	Color.Z *= rhs.Color.Z;

	return *this;
}

inline XColor& XColor::operator*=(const float scale)
{
	Color.X *= scale;
	Color.Y *= scale;
	Color.Z *= scale;

	return *this;
}

inline std::string XColor::ToString() const
{
	return "Color: " + std::to_string(Color.X) + ", "
	+ std::to_string(Color.Y) + ", "
	+ std::to_string(Color.Z) + '\n';
}
