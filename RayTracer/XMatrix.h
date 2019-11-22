#pragma once
#include <vector>

struct XVec4;


struct XMat2x2 {
	XMat2x2(float m00, float m01, float m10, float m11);
	float At(const uint32_t row, const uint32_t col);

	std::vector<std::vector<float>> Matrix;
};

struct XMat3x3 {
	XMat3x3(float m00, float m01, float m02, 
			float m10, float m11, float m12,
			float m20, float m21, float m22);
	float At(const uint32_t row, const uint32_t col);

	std::vector<std::vector<float>> Matrix;
};

struct XMat4x4
{
	XMat4x4(float m00, float m01, float m02, float m03,
		  float m10, float m11, float m12, float m13,
		  float m20, float m21, float m22, float m23,
		  float m30, float m31, float m32, float m33);
	XMat4x4(XVec4 r1, XVec4 r2, XVec4 r3, XVec4 r4);

	std::vector<XVec4> matrix;
	std::vector<std::vector<float>> Matrix;

	float At(const uint32_t row, const uint32_t col);
};
