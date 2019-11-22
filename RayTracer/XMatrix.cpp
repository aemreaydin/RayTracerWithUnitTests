#include "XMatrix.h"
#include "XVector.h"

XMat2x2::XMat2x2(const float m00, const float m01, const float m10, const float m11) {
	Matrix = {
		{m00, m01},
		{m10, m11}
	};
}

float XMat2x2::At(const uint32_t row, const uint32_t col) {
	if(row > 1 || col > 1) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

XMat3x3::XMat3x3(const float m00, const float m01, const float m02, 
				 const float m10, const float m11, const float m12, 
				 const float m20, const float m21, const float m22) {
		Matrix = {
		{m00, m01, m02},
		{m10, m11, m12},
		{m20, m21, m22},
	};
}
float XMat3x3::At(const uint32_t row, const uint32_t col) {
	if(row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

XMat4x4::XMat4x4(const float m00, const float m01, const float m02, const float m03, 
			 const float m10, const float m11, const float m12, const float m13, 
			 const float m20, const float m21, const float m22, const float m23, 
			 const float m30, const float m31, const float m32, const float m33) {
	Matrix = {
		{m00, m01, m02, m03},
		{m10, m11, m12, m13},
		{m20, m21, m22, m23},
		{m30, m31, m32, m33}
	};
	matrix = {
		XVec4{m00, m01, m02, m03},
		XVec4{m10, m11, m12, m13},
		XVec4{m20, m21, m22, m23},
		XVec4{m30, m31, m32, m33}
	};
}

XMat4x4::XMat4x4(const XVec4 r1, const XVec4 r2, const XVec4 r3, const XVec4 r4) {
	Matrix = {
		{r1.X, r1.Y, r1.Z, r1.W},
		{r2.X, r2.Y, r2.Z, r2.W},
		{r3.X, r3.Y, r3.Z, r3.W},
		{r4.X, r4.Y, r4.Z, r4.W},
	};
	matrix = {r1, r2, r3, r4};
}

float XMat4x4::At(const uint32_t row, const uint32_t col) {
	if(row > 3 || col > 3) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}
