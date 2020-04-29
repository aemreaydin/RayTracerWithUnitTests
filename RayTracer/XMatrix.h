#pragma once
#include "XVector4.h"
#include "XMatrix3.h"

#include <DirectXMath.h>

__declspec(align(16)) struct XMatrix
{
	float Matrix[4][4]{};

	XMatrix();
	XMatrix(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33);

	XMatrix(XVector4 r1, XVector4 r2, XVector4 r3, XVector4 r4);
	XMatrix(XVector r1, XVector r2, XVector r3, XVector r4);

	// Arithmetic Operations
	XMatrix &operator+=(const XMatrix &rhs);
	XMatrix &operator-=(const XMatrix &rhs);
	XMatrix &operator*=(const XMatrix &rhs);
	XMatrix &operator*=(float scale);
	XMatrix &operator/=(float scale);

	// Identity Functions
	void SetIdentity();
	XMatrix Tranpose() const;
	float Determinant() const;
	bool IsMatrixInvertible() const;
	XMatrix Inverse() const;

	static XMatrix Identity();
	static XMatrix Translate(const XMatrix &mat, const XVector4 &translate, XVector4 &point);
	static XMatrix Scale(const XMatrix &mat, const XVector4 &scale, XVector4 &point);
	static XMatrix RotateX(const XMatrix &mat, float angleInRadians, XVector4 &point);
	static XMatrix RotateY(const XMatrix &mat, float angleInRadians, XVector4 &point);
	static XMatrix RotateZ(const XMatrix &mat, float angleInRadians, XVector4 &point);
	static XMatrix Shear(const XMatrix &mat, float xy, float xz, float yx, float yz, float zx, float zy, XVector4 &point);
	static XMatrix Transform(const XMatrix &mat, const XVector4 &translate, const XVector4 &rotate, const XVector4 &scale, XVector4 &point);

	// Accessors
	float operator()(Uint32 row, Uint32 col) const;
	float At(Uint32 row, Uint32 col) const;
	float &operator()(Uint32 row, Uint32 col);
	float &At(Uint32 row, Uint32 col);

	std::string ToString() const;
};

//// START OF NON-MEMBER OPERATOR OVERLOADS
inline bool operator==(const XMatrix &lhs, const XMatrix &rhs)
{
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			if (!XMath::IsNearlyEqual(lhs(row, col), rhs(row, col), SMALL_EPSILON))
				return false;
		}
	}
	return true;
}

inline XMatrix operator+(const XMatrix &lhs, const XMatrix &rhs)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) + rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix operator-(const XMatrix &lhs, const XMatrix &rhs)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) - rhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix operator-(const XMatrix &lhs)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = -lhs(row, col);
		}
	}
	return matrix;
}

inline XMatrix operator*(const XMatrix &lhs, const XMatrix &rhs)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			for (Uint32 ind = 0; ind != 4; ind++)
			{
				matrix(row, col) += lhs(row, ind) * rhs(ind, col);
			}
		}
	}
	return matrix;
}

inline XVector4 operator*(const XMatrix &lhs, const XVector4 &rhs)
{
	auto vector = XVector4();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			vector(row) += lhs(row, col) * rhs(col);
		}
	}
	return vector;
}

inline XMatrix operator*(const XMatrix &lhs, const float scale)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) * scale;
		}
	}
	return matrix;
}

inline XMatrix operator/(const XMatrix &lhs, const float scale)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			matrix(row, col) = lhs(row, col) / scale;
		}
	}
	return matrix;
}

//// END OF NON-MEMBER OPERATOR OVERLOADS

inline XMatrix::XMatrix()
{
	Matrix[0][0] = 0.0f;
	Matrix[0][1] = 0.0f;
	Matrix[0][2] = 0.0f;
	Matrix[0][3] = 0.0f;
	Matrix[1][0] = 0.0f;
	Matrix[1][1] = 0.0f;
	Matrix[1][2] = 0.0f;
	Matrix[1][3] = 0.0f;
	Matrix[2][0] = 0.0f;
	Matrix[2][1] = 0.0f;
	Matrix[2][2] = 0.0f;
	Matrix[2][3] = 0.0f;
	Matrix[3][0] = 0.0f;
	Matrix[3][1] = 0.0f;
	Matrix[3][2] = 0.0f;
	Matrix[3][3] = 0.0f;
}

inline XMatrix::XMatrix(const float m00, const float m01, const float m02, const float m03,
						const float m10, const float m11, const float m12, const float m13,
						const float m20, const float m21, const float m22, const float m23,
						const float m30, const float m31, const float m32, const float m33)
{
	Matrix[0][0] = m00;
	Matrix[0][1] = m01;
	Matrix[0][2] = m02;
	Matrix[0][3] = m03;
	Matrix[1][0] = m10;
	Matrix[1][1] = m11;
	Matrix[1][2] = m12;
	Matrix[1][3] = m13;
	Matrix[2][0] = m20;
	Matrix[2][1] = m21;
	Matrix[2][2] = m22;
	Matrix[2][3] = m23;
	Matrix[3][0] = m30;
	Matrix[3][1] = m31;
	Matrix[3][2] = m32;
	Matrix[3][3] = m33;
}

inline XMatrix::XMatrix(const XVector4 r1, const XVector4 r2, const XVector4 r3, const XVector4 r4)
{
	Matrix[0][0] = r1.X;
	Matrix[0][1] = r1.Y;
	Matrix[0][2] = r1.Z;
	Matrix[0][3] = r1.W;
	Matrix[1][0] = r2.X;
	Matrix[1][1] = r2.Y;
	Matrix[1][2] = r2.Z;
	Matrix[1][3] = r2.W;
	Matrix[2][0] = r3.X;
	Matrix[2][1] = r3.Y;
	Matrix[2][2] = r3.Z;
	Matrix[2][3] = r3.W;
	Matrix[3][0] = r4.X;
	Matrix[3][1] = r4.Y;
	Matrix[3][2] = r4.Z;
	Matrix[3][3] = r4.W;
}

inline XMatrix::XMatrix(const XVector r1, const XVector r2, const XVector r3, const XVector r4)
{
	Matrix[0][0] = r1.X;
	Matrix[0][1] = r1.Y;
	Matrix[0][2] = r1.Z;
	Matrix[0][3] = 0.0f;
	Matrix[1][0] = r2.X;
	Matrix[1][1] = r2.Y;
	Matrix[1][2] = r2.Z;
	Matrix[1][3] = 0.0f;
	Matrix[2][0] = r3.X;
	Matrix[2][1] = r3.Y;
	Matrix[2][2] = r3.Z;
	Matrix[2][3] = 0.0f;
	Matrix[3][0] = r4.X;
	Matrix[3][1] = r4.Y;
	Matrix[3][2] = r4.Z;
	Matrix[3][3] = 0.0f;
}

inline XMatrix &XMatrix::operator+=(const XMatrix &rhs)
{
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			(*this)(row, col) += rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix &XMatrix::operator-=(const XMatrix &rhs)
{
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			(*this)(row, col) -= rhs(row, col);
		}
	}
	return *this;
}

inline XMatrix &XMatrix::operator*=(const XMatrix &rhs)
{
	auto matrix = XMatrix();
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			for (Uint32 ind = 0; ind != 4; ind++)
			{
				matrix(row, col) += (*this)(row, ind) * rhs(ind, col);
			}
		}
	}
	*this = matrix;
	return *this;
}

inline XMatrix &XMatrix::operator*=(const float scale)
{
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			for (Uint32 ind = 0; ind != 4; ind++)
			{
				(*this)(row, col) *= scale;
			}
		}
	}
	return *this;
}

inline XMatrix &XMatrix::operator/=(const float scale)
{
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			for (Uint32 ind = 0; ind != 4; ind++)
			{
				(*this)(row, col) /= scale;
			}
		}
	}
	return *this;
}

inline void XMatrix::SetIdentity()
{
	Matrix[0][0] = 1.0f;
	Matrix[0][1] = 0.0f;
	Matrix[0][2] = 0.0f;
	Matrix[0][3] = 0.0f;
	Matrix[1][0] = 0.0f;
	Matrix[1][1] = 1.0f;
	Matrix[1][2] = 0.0f;
	Matrix[1][3] = 0.0f;
	Matrix[2][0] = 0.0f;
	Matrix[2][1] = 0.0f;
	Matrix[2][2] = 1.0f;
	Matrix[2][3] = 0.0f;
	Matrix[3][0] = 0.0f;
	Matrix[3][1] = 0.0f;
	Matrix[3][2] = 0.0f;
	Matrix[3][3] = 1.0f;
}

inline XMatrix XMatrix::Tranpose() const
{
	auto transposed = *this;
	for (Uint32 row = 0; row != 4; row++)
	{
		for (Uint32 col = 0; col != 4; col++)
		{
			if (row <= col)
				continue;
			std::swap(transposed(row, col), transposed(col, row));
		}
	}
	return transposed;
}

inline float XMatrix::Determinant() const
{
	return Matrix[0][0] * (Matrix[1][1] * (Matrix[2][2] * Matrix[3][3] - Matrix[2][3] * Matrix[3][2]) -
						   Matrix[2][1] * (Matrix[1][2] * Matrix[3][3] - Matrix[1][3] * Matrix[3][2]) +
						   Matrix[3][1] * (Matrix[1][2] * Matrix[2][3] - Matrix[1][3] * Matrix[2][2])) -
		   Matrix[1][0] * (Matrix[0][1] * (Matrix[2][2] * Matrix[3][3] - Matrix[2][3] * Matrix[3][2]) -
						   Matrix[2][1] * (Matrix[0][2] * Matrix[3][3] - Matrix[0][3] * Matrix[3][2]) +
						   Matrix[3][1] * (Matrix[0][2] * Matrix[2][3] - Matrix[0][3] * Matrix[2][2])) +
		   Matrix[2][0] * (Matrix[0][1] * (Matrix[1][2] * Matrix[3][3] - Matrix[1][3] * Matrix[3][2]) -
						   Matrix[1][1] * (Matrix[0][2] * Matrix[3][3] - Matrix[0][3] * Matrix[3][2]) +
						   Matrix[3][1] * (Matrix[0][2] * Matrix[1][3] - Matrix[0][3] * Matrix[1][2])) -
		   Matrix[3][0] * (Matrix[0][1] * (Matrix[1][2] * Matrix[2][3] - Matrix[1][3] * Matrix[2][2]) -
						   Matrix[1][1] * (Matrix[0][2] * Matrix[2][3] - Matrix[0][3] * Matrix[2][2]) +
						   Matrix[2][1] * (Matrix[0][2] * Matrix[1][3] - Matrix[0][3] * Matrix[1][2]));
}

inline bool XMatrix::IsMatrixInvertible() const
{
	return Determinant() != 0.0f;
}

inline XMatrix XMatrix::Inverse() const
{
	if (!IsMatrixInvertible())
		return Identity();

	using namespace DirectX;
	// ReSharper disable once CppLocalVariableMayBeConst
	auto dstMatrix = XMatrix();

	const auto xmMatrix = XMLoadFloat4x4A(reinterpret_cast<const XMFLOAT4X4A *>(Matrix));
	const auto xmDstMatrix = XMMatrixInverse(nullptr, xmMatrix);
	XMStoreFloat4x4A(reinterpret_cast<XMFLOAT4X4A *>(dstMatrix.Matrix), xmDstMatrix);

	return dstMatrix;
}

inline XMatrix XMatrix::Identity()
{
	return {XVector4(1.0f, 0.0f, 0.0f, 0.0f),
			XVector4(0.0f, 1.0f, 0.0f, 0.0f),
			XVector4(0.0f, 0.0f, 1.0f, 0.0f),
			XVector4(0.0f, 0.0f, 0.0f, 1.0f)};
}

inline XMatrix XMatrix::Translate(const XMatrix &mat, const XVector4 &translate, XVector4 &point)
{
	auto transMat = mat;
	transMat(0, 3) = translate.X;
	transMat(1, 3) = translate.Y;
	transMat(2, 3) = translate.Z;

	point += mat * translate;
	return mat * transMat;
}

inline XMatrix XMatrix::Scale(const XMatrix &mat, const XVector4 &scale, XVector4 &point)
{
	auto scaleMat = mat;
	scaleMat(0, 0) = scale.X;
	scaleMat(1, 1) = scale.Y;
	scaleMat(2, 2) = scale.Z;

	point *= mat * scale;
	return mat * scaleMat;
}

inline XMatrix XMatrix::RotateX(const XMatrix &mat, const float angleInRadians, XVector4 &point)
{
	if (angleInRadians == 0.0f)
		return mat;
	auto rotateMat = Identity();
	rotateMat(1, 1) = cosf(angleInRadians);
	rotateMat(1, 2) = -sinf(angleInRadians);
	rotateMat(2, 1) = sinf(angleInRadians);
	rotateMat(2, 2) = cosf(angleInRadians);

	point = rotateMat * point;
	return mat * rotateMat;
}

inline XMatrix XMatrix::RotateY(const XMatrix &mat, const float angleInRadians, XVector4 &point)
{
	if (angleInRadians == 0.0f)
		return mat;
	auto rotateMat = Identity();
	rotateMat(0, 1) = cosf(angleInRadians);
	rotateMat(0, 2) = sinf(angleInRadians);
	rotateMat(2, 0) = -sinf(angleInRadians);
	rotateMat(2, 2) = cosf(angleInRadians);

	point = rotateMat * point;
	return mat * rotateMat;
}

inline XMatrix XMatrix::RotateZ(const XMatrix &mat, const float angleInRadians, XVector4 &point)
{
	if (angleInRadians == 0.0f)
		return mat;
	auto rotateMat = Identity();
	rotateMat(0, 0) = cosf(angleInRadians);
	rotateMat(0, 1) = -sinf(angleInRadians);
	rotateMat(1, 0) = sinf(angleInRadians);
	rotateMat(1, 1) = cosf(angleInRadians);

	point = rotateMat * point;
	return mat * rotateMat;
}

inline XMatrix XMatrix::Shear(const XMatrix &mat, const float xy, const float xz, const float yx, const float yz, const float zx, const float zy, XVector4 &point)
{
	auto shearMat = Identity();
	shearMat(0, 1) = xy;
	shearMat(0, 2) = xz;
	shearMat(1, 0) = yx;
	shearMat(1, 2) = yz;
	shearMat(2, 0) = zx;
	shearMat(2, 1) = zy;

	point = shearMat * point;
	return mat * shearMat;
}

inline XMatrix XMatrix::Transform(const XMatrix &mat, const XVector4 &translate, const XVector4 &rotate, const XVector4 &scale,
								  XVector4 &point)
{
	auto newPoint = point;
	const auto transMat = Translate(mat, translate, newPoint);
	const auto scaleMat = Scale(mat, scale, newPoint);
	const auto rotZMat = RotateZ(mat, rotate.Z, newPoint);
	const auto rotYMat = RotateY(mat, rotate.Y, newPoint);
	const auto rotXMat = RotateX(mat, rotate.X, newPoint);
	const auto rotMat = rotZMat * rotYMat * rotXMat;
	const auto transformMat = transMat * scaleMat * rotMat;
	point = transformMat * point;
	return mat * transformMat;
}

inline float XMatrix::operator()(const Uint32 row, const Uint32 col) const
{
	if (row > 3 || col > 3)
		throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float XMatrix::At(const Uint32 row, const Uint32 col) const
{
	if (row > 3 || col > 3)
		throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float &XMatrix::operator()(const Uint32 row, const Uint32 col)
{
	if (row > 3 || col > 3)
		throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline float &XMatrix::At(const Uint32 row, const Uint32 col)
{
	if (row > 3 || col > 3)
		throw std::runtime_error("Matrix out of bounds.");
	return Matrix[row][col];
}

inline std::string XMatrix::ToString() const
{
	return std::to_string(Matrix[0][0]);
}