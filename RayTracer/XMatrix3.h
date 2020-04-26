#pragma once
#include "XVector.h"

struct XMatrix3
{
	__declspec(align(16)) float Matrix[3][3]{};

	XMatrix3();
	XMatrix3(float m00, float m01, float m02,
	         float m10, float m11, float m12,
	         float m20, float m21, float m22);

	XMatrix3(XVector r1, XVector r2, XVector r3);

	// Arithmetic Operations
	XMatrix3& operator+=(const XMatrix3& rhs);
	XMatrix3& operator-=(const XMatrix3& rhs);
	XMatrix3& operator*=(const XMatrix3& rhs);
	XMatrix3& operator*=(float scale);
	XMatrix3& operator/=(float scale);
	
	// Identity Functions
	void SetIdentity();
	XMatrix3 Tranpose() const;
	float Determinant() const;
	bool IsMatrixInvertible() const;
	XMatrix3 Inverse() const;
	
	static XMatrix3 Identity();
	
	// Accessors
	float operator()(Uint32 row, Uint32 col) const;
	float At(Uint32 row, Uint32 col) const;
	float& operator()(Uint32 row, Uint32 col);
	float& At(Uint32 row, Uint32 col);

	std::string ToString() const;
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XMatrix3& lhs, const XMatrix3& rhs)
{
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			if(lhs(row, col) != rhs(row, col))
				return false;
		}
	}
	return true;
}

inline XMatrix3 operator+(const XMatrix3& lhs, const XMatrix3& rhs)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			matrix(row, col) = lhs(row, col) + rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix3 operator-(const XMatrix3& lhs, const XMatrix3& rhs)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			matrix(row, col) = lhs(row, col) - rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix3 operator-(const XMatrix3& lhs)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			matrix(row, col) = -lhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix3 operator*(const XMatrix3& lhs, const XMatrix3& rhs)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			for(Uint32 ind = 0; ind != 3; ind++)
			{
				matrix(row, col) += lhs(row, ind) * rhs(ind, col);
			}
		}
	}
	return matrix;
}

inline XMatrix3 operator*(const XMatrix3& lhs, const float scale)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			matrix(row, col) = lhs(row, col) * scale;
		}
	}
	return matrix;
}

inline XMatrix3 operator/(const XMatrix3& lhs, const float scale)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			matrix(row, col) = lhs(row, col) / scale;
		}
	}
	return matrix;
}

//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XMatrix3::XMatrix3()
{
	Matrix[0][0] = 0.0f; Matrix[0][1] = 0.0f;  Matrix[0][2] = 0.0f;
	Matrix[1][0] = 0.0f; Matrix[1][1] = 0.0f;  Matrix[1][2] = 0.0f;
	Matrix[2][0] = 0.0f; Matrix[2][1] = 0.0f;  Matrix[2][2] = 0.0f;
}

inline XMatrix3::XMatrix3(const float m00, const float m01, const float m02, 
                          const float m10, const float m11, const float m12, 
                          const float m20, const float m21, const float m22)
{
	Matrix[0][0] = m00;	Matrix[0][1] = m01;	Matrix[0][2] = m02;
	Matrix[1][0] = m10;	Matrix[1][1] = m11;	Matrix[1][2] = m12;
	Matrix[2][0] = m20;	Matrix[2][1] = m21;	Matrix[2][2] = m22;
}

inline XMatrix3::XMatrix3(const XVector r1, const XVector r2, const XVector r3)
{
	Matrix[0][0] = r1.X; Matrix[0][1] = r1.Y; Matrix[0][2] = r1.Z;
	Matrix[1][0] = r2.X; Matrix[1][1] = r2.Y; Matrix[1][2] = r2.Z;
	Matrix[2][0] = r3.X; Matrix[2][1] = r3.Y; Matrix[2][2] = r3.Z;
}


inline XMatrix3& XMatrix3::operator+=(const XMatrix3& rhs)
{
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			(*this)(row, col) += rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix3& XMatrix3::operator-=(const XMatrix3& rhs)
{
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			(*this)(row, col) -= rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix3& XMatrix3::operator*=(const XMatrix3& rhs)
{
	auto matrix = XMatrix3();
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			for(Uint32 ind = 0; ind != 3; ind++)
			{
				matrix(row, col) += (*this)(row, ind) * rhs(ind, col);
			}
		}
	}
	*this = matrix;
	return *this;
}

inline XMatrix3& XMatrix3::operator*=(const float scale)
{
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			for(Uint32 ind = 0; ind != 3; ind++)
			{
				(*this)(row, col) *= scale;
			}
		}
	}
	return *this;
}

inline XMatrix3& XMatrix3::operator/=(const float scale)
{
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			for(Uint32 ind = 0; ind != 3; ind++)
			{
				(*this)(row, col) /= scale;
			}
		}
	}
	return *this;
}

inline void XMatrix3::SetIdentity()
{
	Matrix[0][0] = 1.0f; Matrix[0][1] = 0.0f;  Matrix[0][2] = 0.0f;
	Matrix[1][0] = 0.0f; Matrix[1][1] = 1.0f;  Matrix[1][2] = 0.0f;
	Matrix[2][0] = 0.0f; Matrix[2][1] = 0.0f;  Matrix[2][2] = 1.0f;
}

inline XMatrix3 XMatrix3::Tranpose() const
{
	auto transposed = *this;
	for(Uint32 row = 0; row != 3; row++)
	{
		for(Uint32 col = 0; col != 3; col++)
		{
			if(row <= col) continue;
			std::swap(transposed(row, col), transposed(col, row));
		}
	}
	return transposed;
}

inline float XMatrix3::Determinant() const
{
	return Matrix[0][0] * (
				Matrix[1][1] * Matrix[2][2] - Matrix[1][2] * Matrix[2][1]
				) -
			Matrix[1][0] * (
				Matrix[0][1] * Matrix[2][2] - Matrix[0][2] * Matrix[2][1]
				) +
			Matrix[2][0] * (
				Matrix[0][1] * Matrix[1][2] - Matrix[0][2] * Matrix[1][1]
				);
}

inline bool XMatrix3::IsMatrixInvertible() const
{
	return Determinant() != 0.0f;
}

inline XMatrix3 XMatrix3::Identity()
{
	return {XVector(1.0f, 0.0f, 0.0f),
		    XVector(0.0f, 1.0f, 0.0f),
			XVector(0.0f, 0.0f, 1.0f)};
}

inline float XMatrix3::operator()(const Uint32 row, const Uint32 col) const
{
	if (row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float XMatrix3::At(const Uint32 row, const Uint32 col) const
{
	if (row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float& XMatrix3::operator()(const Uint32 row, const Uint32 col)
{
	if (row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float& XMatrix3::At(const Uint32 row, const Uint32 col)
{
	if (row > 2 || col > 2) throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline std::string XMatrix3::ToString() const
{
	return std::to_string(Matrix[0][0]);
}