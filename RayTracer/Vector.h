#pragma once
struct Vec3 {
	float x, r;
	float y, g;
	float z, b;

	Vec3();
	Vec3(float _x, float _y, float _z);

	Vec3 operator+ (const Vec3& other);
	Vec3 operator- (const Vec3 & other);
	Vec3 operator- ();
};

struct Vec4 {
	float x, r;
	float y, g;
	float z, b;
	float w, a;

	Vec4();
	Vec4(float _x, float _y, float _z, float _w);
	Vec4(Vec3 _vec3);

	Vec4 operator+ (const Vec4& other);
	Vec4 operator- (const Vec4& other);
	Vec4 operator- (float value);
	Vec4 operator- ();
	Vec4& operator= (const Vec4 & other);
	bool operator== (const Vec4& other);

	bool IsPoint();
};