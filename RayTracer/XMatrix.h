#pragma once
#include "XVector4.h"

struct XMatrix4
{
	__declspec(align(16)) float Matrix[4][4]{};

	XMatrix4();
	XMatrix4(float m00, float m01, float m02, float m03,
	         float m10, float m11, float m12, float m13,
	         float m20, float m21, float m22, float m23,
	         float m30, float m31, float m32, float m33);

	XMatrix4(XVector4 r1, XVector4 r2, XVector4 r3, XVector4 r4);
	XMatrix4(XVector r1, XVector r2, XVector r3, XVector r4);

	// Arithmetic Operations
	XMatrix4& operator+=(const XMatrix4& rhs);
	XMatrix4& operator-=(const XMatrix4& rhs);
	XMatrix4& operator*=(const XMatrix4& rhs);
	XMatrix4& operator*=(float scale);
	XMatrix4& operator/=(float scale);
	
	// Identity Functions
	void SetIdentity();
	static XMatrix4 Identity();

	// Accessors
	float operator()(Uint32 row, Uint32 col) const;
	float At(Uint32 row, Uint32 col) const;
	float& operator()(Uint32 row, Uint32 col);
	float& At(Uint32 row, Uint32 col);
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XMatrix4& lhs, const XMatrix4& rhs)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			if(lhs(row, col) != rhs(row, col))
				return false;
		}
	}
	return true;
}

inline XMatrix4 operator+(const XMatrix4& lhs, const XMatrix4& rhs)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) + rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix4 operator-(const XMatrix4& lhs, const XMatrix4& rhs)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) - rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix4 operator-(const XMatrix4& lhs)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = -lhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix4 operator*(const XMatrix4& lhs, const XMatrix4& rhs)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			for(Uint32 ind = 0; ind != 4; ind++)
			{
				matrix(row, col) = lhs(row, ind) * rhs(ind, col);
			}
		}
	}
	return matrix;
}

inline XMatrix4 operator*(const XMatrix4& lhs, const float scale)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) * scale;
		}
	}
	return matrix;
}

inline XMatrix4 operator/(const XMatrix4& lhs, const float scale)
{
	auto matrix = XMatrix4();
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) / scale;
		}
	}
	return matrix;
}

//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XMatrix4::XMatrix4()
{
	Matrix[0][0] = 0.0f; Matrix[0][1] = 0.0f;  Matrix[0][2] = 0.0f;  Matrix[0][3] = 0.0f;
	Matrix[1][0] = 0.0f; Matrix[1][1] = 0.0f;  Matrix[1][2] = 0.0f;  Matrix[1][3] = 0.0f;
	Matrix[2][0] = 0.0f; Matrix[2][1] = 0.0f;  Matrix[2][2] = 0.0f;  Matrix[2][3] = 0.0f;
	Matrix[3][0] = 0.0f; Matrix[3][1] = 0.0f;  Matrix[3][2] = 0.0f;  Matrix[3][3] = 0.0f;
}

inline XMatrix4::XMatrix4(const float m00, const float m01, const float m02, const float m03, 
                          const float m10, const float m11, const float m12, const float m13, 
                          const float m20, const float m21, const float m22, const float m23, 
                          const float m30, const float m31, const float m32, const float m33)
{
	Matrix[0][0] = m00;	Matrix[0][1] = m01;	Matrix[0][2] = m02;	Matrix[0][3] = m03;
	Matrix[1][0] = m10;	Matrix[1][1] = m11;	Matrix[1][2] = m12;	Matrix[1][3] = m13;
	Matrix[2][0] = m20;	Matrix[2][1] = m21;	Matrix[2][2] = m22;	Matrix[2][3] = m23;
	Matrix[3][0] = m30;	Matrix[3][1] = m31;	Matrix[3][2] = m32;	Matrix[3][3] = m33;
}

inline XMatrix4::XMatrix4(const XVector4 r1, const XVector4 r2, const XVector4 r3, const XVector4 r4)
{
	Matrix[0][0] = r1.X; Matrix[0][1] = r1.Y; Matrix[0][2] = r1.Z; Matrix[0][3] = r1.W;
	Matrix[1][0] = r2.X; Matrix[1][1] = r2.Y; Matrix[1][2] = r2.Z; Matrix[1][3] = r2.W;
	Matrix[2][0] = r3.X; Matrix[2][1] = r3.Y; Matrix[2][2] = r3.Z; Matrix[2][3] = r3.W;
	Matrix[3][0] = r4.X; Matrix[3][1] = r4.Y; Matrix[3][2] = r4.Z; Matrix[3][3] = r4.W;
}

inline XMatrix4::XMatrix4(const XVector r1, const XVector r2, const XVector r3, const XVector r4)
{
	Matrix[0][0] = r1.X; Matrix[0][1] = r1.Y; Matrix[0][2] = r1.Z; Matrix[0][3] = 0.0f;
	Matrix[1][0] = r2.X; Matrix[1][1] = r2.Y; Matrix[1][2] = r2.Z; Matrix[1][3] = 0.0f;
	Matrix[2][0] = r3.X; Matrix[2][1] = r3.Y; Matrix[2][2] = r3.Z; Matrix[2][3] = 0.0f;
	Matrix[3][0] = r4.X; Matrix[3][1] = r4.Y; Matrix[3][2] = r4.Z; Matrix[3][3] = 0.0f;
}

inline XMatrix4& XMatrix4::operator+=(const XMatrix4& rhs)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			(*this)(row, col) += rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix4& XMatrix4::operator-=(const XMatrix4& rhs)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			(*this)(row, col) -= rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix4& XMatrix4::operator*=(const XMatrix4& rhs)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			for(Uint32 ind = 0; ind != 4; ind++)
			{
				(*this)(row, col) = (*this)(row, ind) * rhs(ind, col);
			}
		}
	}
	return *this;
}

inline XMatrix4& XMatrix4::operator*=(const float scale)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			for(Uint32 ind = 0; ind != 4; ind++)
			{
				(*this)(row, col) *= scale;
			}
		}
	}
	return *this;
}

inline XMatrix4& XMatrix4::operator/=(const float scale)
{
	for(Uint32 row = 0; row != 4; row++)
	{
		for(Uint32 col = 0; col != 4; col++)
		{
			for(Uint32 ind = 0; ind != 4; ind++)
			{
				(*this)(row, col) /= scale;
			}
		}
	}
	return *this;
}

inline void XMatrix4::SetIdentity()
{
	Matrix[0][0] = 1.0f; Matrix[0][1] = 0.0f;  Matrix[0][2] = 0.0f;  Matrix[0][3] = 0.0f;
	Matrix[1][0] = 0.0f; Matrix[1][1] = 1.0f;  Matrix[1][2] = 0.0f;  Matrix[1][3] = 0.0f;
	Matrix[2][0] = 0.0f; Matrix[2][1] = 0.0f;  Matrix[2][2] = 1.0f;  Matrix[2][3] = 0.0f;
	Matrix[3][0] = 0.0f; Matrix[3][1] = 0.0f;  Matrix[3][2] = 0.0f;  Matrix[3][3] = 1.0f;
}

inline XMatrix4 XMatrix4::Identity()
{
	return {XVector4(1.0f, 0.0f, 0.0f, 0.0f),
		    XVector4(0.0f, 1.0f, 0.0f, 0.0f),
		    XVector4(0.0f, 0.0f, 1.0f, 0.0f),
			XVector4(0.0f, 0.0f, 0.0f, 1.0f)};
}

inline float XMatrix4::operator()(const Uint32 row, const Uint32 col) const
{
	if (row > 3 || col > 3) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float XMatrix4::At(const Uint32 row, const Uint32 col) const
{
	if (row > 3 || col > 3) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float& XMatrix4::operator()(const Uint32 row, const Uint32 col)
{
	if (row > 3 || col > 3) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float& XMatrix4::At(const Uint32 row, const Uint32 col)
{
	if (row > 3 || col > 3) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

//struct XMatrix2 {
//	XMatrix2(float m00, float m01, float m10, float m11);
//	float At(uint32_t row, uint32_t col);
//
//	std::vector<std::vector<float>> Matrix;
//};
//
//struct XMatrix3 {
//	XMatrix3(float m00, float m01, float m02, 
//			float m10, float m11, float m12,
//			float m20, float m21, float m22);
//	float At(uint32_t row, uint32_t col);
//
//	std::vector<std::vector<float>> Matrix;
//};

//XMatrix2::XMatrix2(const float m00, const float m01, const float m10, const float m11) {
//	Matrix = {
//		{m00, m01},
//		{m10, m11}
//	};
//}
//
//float XMatrix2::At(const uint32_t row, const uint32_t col) {
//	if(row > 1 || col > 1) throw std::runtime_error("Matrix out of bounds.");
//	return Matrix[row][col];
//}
//
//XMatrix3::XMatrix3(const float m00, const float m01, const float m02, 
//				 const float m10, const float m11, const float m12, 
//				 const float m20, const float m21, const float m22) {
//		Matrix = {
//		{m00, m01, m02},
//		{m10, m11, m12},
//		{m20, m21, m22},
//	};
//}
//float XMatrix3::At(const uint32_t row, const uint32_t col) {
//	if(row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
//	return Matrix[row][col];
//}


//// TODO WHAT IS THIS SHIT???
//bool operator==(XMatrix4 &lhs, XMatrix4 &rhs) {
//	for(auto row = 0; row != 4; ++row) {
//		for(auto col = 0; col != 4; ++col) {
//			if(lhs.At(row, col) != rhs.At(row, col))
//				return false;
//		}
//	}
//	return true;
//}
