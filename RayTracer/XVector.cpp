#include "XVector.h"
#include "XMath.h"

#include <string>

XVector::XVector() {
	X = 0.0F;
	Y = 0.0F;
	Z = 0.0F;
}

XVector::XVector(const float x, const float y, const float z) {
	X = x;
	Y = y;
	Z = z;
}

XVector& XVector::operator+=(const XVector& rhs)
{
	this->X += rhs.X; this->Y += rhs.Y; this->Z += rhs.Z;
	return *this;
}

XVector& XVector::operator*=(const XVector& rhs)
{
	this->X *= rhs.X; this->Y *= rhs.Y; this->Z *= rhs.Z;
	return *this;
}

XVector& XVector::operator*=(const float scale)
{
	this->X *= scale; this->Y *= scale; this->Z *= scale;
	return *this;
}


XVector operator+(const XVector& lhs, const XVector& rhs) {
	return { lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z };
}



XVector operator-(const XVector& lhs, const XVector& rhs) {
	return { lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z };
}

XVector operator-(const XVector& lhs) {
	return { -lhs.X, -lhs.Y, -lhs.Z };
}

XVector operator-(const XVector& lhs, const float value) {
	return { lhs.X - value, lhs.Y - value, lhs.Z - value };
}

XVector operator*(const XVector &lhs, const XVector &rhs) {
	return { lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z };
}

XVector operator*=(const XVector& lhs, const XVector& rhs)
{
	return { lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z };
}

XVector operator*(const XVector& lhs, const float scale) {
	return { lhs.X * scale, lhs.Y * scale, lhs.Z * scale };
}

XVector operator*=(const XVector& lhs, float scale)
{
	return { lhs.X * scale, lhs.Y * scale, lhs.Z * scale };
}

XVector operator/(const XVector& lhs, const float scale) {
	return { lhs.X / scale, lhs.Y / scale, lhs.Z / scale };
}

bool operator==(const XVector& lhs, const XVector& rhs) {
	return XMath::IsEqual(lhs.X, rhs.Y) ||
		XMath::IsEqual(lhs.Y, rhs.Y) ||
		XMath::IsEqual(lhs.Z, rhs.Z);
}

std::ostream & operator<<(std::ostream &stream, const XVector vec) {
	return stream << "Vector: " << std::to_string(vec.X) << ", "
								<< std::to_string(vec.Y) << ", "
								<< std::to_string(vec.Z);
}

XVector4::XVector4() {
	X = 0.0F;
	Y = 0.0F;
	Z = 0.0F;
	W = 1.0F;
}

XVector4::XVector4(const float x, const float y, const float z, const float w) {
	X = x;
	Y = y;
	Z = z;
	W = w;
}

XVector4::XVector4(const XVector& vec3, const float w) {
	X = vec3.X;
	Y = vec3.Y;
	Z = vec3.Z;
	W = w;
}

XVector4& XVector4::operator=(const XVector4& other) {
	X = other.X;
	Y = other.Y;
	Z = other.Z;
	W = other.W;

	return *this;
}

bool XVector4::IsPoint() const {
	return W == 1.0F;
}

XVector4 operator+(const XVector4& lhs, const XVector4& rhs) {
	return { lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z, lhs.W + rhs.W };
}

XVector4 operator-(const XVector4& lhs, const XVector4& rhs) {
	return { lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z, lhs.W - rhs.W };
}

XVector4 operator-(const XVector4& lhs, const float value) {
	return { lhs.X - value, lhs.Y - value, lhs.Z - value, lhs.W - value };
}

XVector4 operator*(const XVector4& lhs, const float scale) {
	return { lhs.X * scale, lhs.Y * scale, lhs.Z * scale, lhs.W * scale };
}

XVector4 operator/(const XVector4& lhs, const float scale) {
	return { lhs.X / scale, lhs.Y / scale, lhs.Z / scale, lhs.W / scale };
}

XVector4 operator-(const XVector4& lhs) {
	return { -lhs.X, -lhs.Y, -lhs.Z, -lhs.W };
}

bool operator==(const XVector4& lhs, const XVector4& rhs) {
	return XMath::IsEqual(lhs.X, rhs.Y) ||
		XMath::IsEqual(lhs.Y, rhs.Y) ||
		XMath::IsEqual(lhs.Z, rhs.Z) ||
		XMath::IsEqual(lhs.W, rhs.W);
}
