#include "XVector.h"
#include "XMath.h"

#include <string>

XVec3::XVec3() {
	X = R = 0.0F;
	Y = G = 0.0F;
	Z = B = 0.0F;
}

XVec3::XVec3(const float x, const float y, const float z) {
	X = R = x;
	Y = G = y;
	Z = B = z;
}

XVec3 operator+(const XVec3& lhs, const XVec3& rhs) {
	return { lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z };
}

XVec3 operator-(const XVec3& lhs, const XVec3& rhs) {
	return { lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z };
}

XVec3 operator-(const XVec3& lhs) {
	return { -lhs.X, -lhs.Y, -lhs.Z };
}

XVec3 operator-(const XVec3& lhs, const float value) {
	return { lhs.X - value, lhs.Y - value, lhs.Z - value };
}

XVec3 operator*(const XVec3 &lhs, const XVec3 &rhs) {
	return { lhs.X * rhs.X, lhs.Y * rhs.Y, lhs.Z * rhs.Z };
}

XVec3 operator*(const XVec3& lhs, const float scale) {
	return { lhs.X * scale, lhs.Y * scale, lhs.Z * scale };
}

XVec3 operator/(const XVec3& lhs, const float scale) {
	return { lhs.X / scale, lhs.Y / scale, lhs.Z / scale };
}

bool operator==(const XVec3& lhs, const XVec3& rhs) {
	return XMath::IsEqual(lhs.X, rhs.Y) ||
		XMath::IsEqual(lhs.Y, rhs.Y) ||
		XMath::IsEqual(lhs.Z, rhs.Z);
}

std::ostream & operator<<(std::ostream &stream, const XVec3 vec) {
	return stream << "Vector: " << std::to_string(vec.X) << ", "
								<< std::to_string(vec.Y) << ", "
								<< std::to_string(vec.Z);
}

XVec4::XVec4() {
	X = R = 0.0F;
	Y = G = 0.0F;
	Z = B = 0.0F;
	W = A = 1.0F;
}

XVec4::XVec4(const float x, const float y, const float z, const float w) {
	X = R = x;
	Y = G = y;
	Z = B = z;
	W = A = w;
}

XVec4::XVec4(const XVec3& vec3, const float w) {
	X = R = vec3.X;
	Y = G = vec3.Y;
	Z = B = vec3.Z;
	W = A = w;
}

XVec4& XVec4::operator=(const XVec4& other) {
	X = R = other.X;
	Y = G = other.Y;
	Z = B = other.Z;
	W = A = other.W;

	return *this;
}

bool XVec4::IsPoint() const {
	return W == 1.0F;
}

XVec4 operator+(const XVec4& lhs, const XVec4& rhs) {
	return { lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z, lhs.W + rhs.W };
}

XVec4 operator-(const XVec4& lhs, const XVec4& rhs) {
	return { lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z, lhs.W - rhs.W };
}

XVec4 operator-(const XVec4& lhs, const float value) {
	return { lhs.X - value, lhs.Y - value, lhs.Z - value, lhs.W - value };
}

XVec4 operator*(const XVec4& lhs, const float scale) {
	return { lhs.X * scale, lhs.Y * scale, lhs.Z * scale, lhs.W * scale };
}

XVec4 operator/(const XVec4& lhs, const float scale) {
	return { lhs.X / scale, lhs.Y / scale, lhs.Z / scale, lhs.W / scale };
}

XVec4 operator-(const XVec4& lhs) {
	return { -lhs.X, -lhs.Y, -lhs.Z, -lhs.W };
}

bool operator==(const XVec4& lhs, const XVec4& rhs) {
	return XMath::IsEqual(lhs.X, rhs.Y) ||
		XMath::IsEqual(lhs.Y, rhs.Y) ||
		XMath::IsEqual(lhs.Z, rhs.Z) ||
		XMath::IsEqual(lhs.W, rhs.W);
}
