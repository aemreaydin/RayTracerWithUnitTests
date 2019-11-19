#include "Vector.h"
#include "Math.h"

#include <algorithm>

Vec3::Vec3()
{
	x = r = 0.0F;
	y = g = 0.0F;
	z = b = 0.0F;
}

Vec3::Vec3(float _x, float _y, float _z)
{
	x = r = _x;
	y = g = _y;
	z = b = _z;
}

Vec3 Vec3::operator+(const Vec3& other)
{
	return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other)
{
	return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator-()
{
	return Vec3(-x, -y, -z);
}


Vec4::Vec4()
{
	x = r = 0.0F;
	y = g = 0.0F;
	z = b = 0.0F;
	w = a = 1.0F;
}

Vec4::Vec4(float _x, float _y, float _z, float _w)
{
	x = r = _x;
	y = g = _y;
	z = b = _z;
	w = a = _w;
}

Vec4::Vec4(Vec3 _vec3)
{
	x = r = _vec3.x;
	y = g = _vec3.y;
	z = b = _vec3.z;
	w = a = 1.0F;
}

Vec4 Vec4::operator+(const Vec4& other)
{

	return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vec4 Vec4::operator-(const Vec4& other)
{
	return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vec4 Vec4::operator-(float value)
{
	return Vec4(x - value, y - value, z - value, w - value);
}

Vec4 Vec4::operator-()
{	
	return Vec4(-x, -y, -z, -w);
}

Vec4& Vec4::operator=(const Vec4& other)
{
	x = r = other.x;
	y = g = other.y;
	z = b = other.z;
	w = a = other.w;

	return *this;
}

bool Vec4::operator==(const Vec4& other)
{
	return Math::IsEqual(x, other.x) ||
		Math::IsEqual(y, other.y) ||
		Math::IsEqual(z, other.z) ||
		Math::IsEqual(w, other.w);
}

bool Vec4::IsPoint()
{
	return w == 1.0F || a == 1.0F;
}