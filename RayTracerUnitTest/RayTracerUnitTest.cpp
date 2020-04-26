#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "XMath.h"
#include "XVector.h"
#include "XVector4.h"
#include "XColor.h"
#include "XMatrix.h"
#include "XCanvas.h"
#include "XImageManager.h"

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template <>
			std::wstring ToString<XVector4>(const XVector4& t)
			{
				RETURN_WIDE_STRING(t.ToString().c_str());
			}

			template <>
			std::wstring ToString<XVector>(const XVector& t)
			{
				RETURN_WIDE_STRING(t.ToString().c_str());
			}

			template <>
			std::wstring ToString<XColor>(const XColor& t)
			{
				RETURN_WIDE_STRING(t.ToString().c_str());
			}

			template <>
			std::wstring ToString<XMatrix4>(const XMatrix4& t)
			{
				RETURN_WIDE_STRING(t.ToString().c_str());
			}
		}
	}
}

namespace RayTracerUnitTest
{
	TEST_CLASS(Vector3UnitTest)
	{
		TEST_METHOD(Vec3Magnitude)
		{
			const XVector a(3.0f, 4.0f, 5.0f);
			const XVector b(7.0f, 1.0f, 0.0f);
			Assert::IsTrue(XMath::IsNearlyEqual(sqrtf(50), a.Magnitude()));
			Assert::IsTrue(XMath::IsNearlyEqual(a.Magnitude(), b.Magnitude()));
		}

		TEST_METHOD(Vec3Normalize)
		{
			XVector a(3.0f, 4.0f, 0.0f);
			Assert::IsTrue(a.Normalize());
			Assert::AreEqual(a, XVector(0.6f, 0.8f, 0.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.Magnitude(), 1.0f));
		}

		TEST_METHOD(Vec3DotProduct)
		{
			const XVector a(3.0f, 4.0f, 5.0f);
			const XVector b(2.0f, 1.0f, 8.0f);
			Assert::IsTrue(XMath::IsNearlyEqual(XVector::DotProduct(a, b), 50.0f));
		}

		TEST_METHOD(Vec3CrossProduct)
		{
			const XVector a(1.0f, 2.0f, 3.0f);
			const XVector b(2.0f, 3.0f, 4.0f);
			Assert::AreEqual(XVector::CrossProduct(a, b), XVector(-1.0f, 2.0f, -1.0f));
			Assert::AreEqual(XVector::CrossProduct(b, a), XVector(1.0f, -2.0f, 1.0f));
		}

		TEST_METHOD(Vec3ElementWiseMultiplication)
		{
			const XVector a(1.0f, 2.0f, 3.0f);
			const XVector b(2.0f, 3.0f, 4.0f);
			Assert::AreEqual(a * b, XVector(2.0f, 6.0f, 12.0f));
		}
	};

	TEST_CLASS(Vector4UnitTest)
	{
	public:
		TEST_METHOD(Vec4Addition)
		{
			const XVector4 a(3.0f, -2.0f, 5.0f, 1.0f);
			const XVector4 b(-2.0f, 3.0f, 1.0f, 0.0f);
			Assert::IsTrue(a + b == XVector4(1.0f, 1.0f, 6.0f, 1.0f));
		}

		TEST_METHOD(Vec4Subtraction)
		{
			const XVector4 a(3.0f, -2.0f, 5.0f, 1.0f);
			const XVector4 b(-2.0f, 3.0f, 1.0f, 0.0f);
			Assert::AreEqual(a - b, XVector4(5.0f, -5.0f, 4.0f, 1.0f));
		}

		TEST_METHOD(Vec4Negation)
		{
			const XVector4 a(3.0f, -3.0f, 2.0f, 1.0f);
			const XVector4 b(-3.0f, 3.0f, -2.0f, -1.0f);
			Assert::AreEqual(a, -b);
		}

		TEST_METHOD(Vec4ScalarMultiplication)
		{
			const XVector4 a(3.0f, -3.0f, 6.0f, 3.0f);
			const auto scale = 3.0f;
			const auto fraction = .5f;
			Assert::AreEqual(a * scale, XVector4(9.0f, -9.0f, 18.0f, 9.0f));
			Assert::AreEqual(a * fraction, XVector4(1.5f, -1.5f, 3.0f, 1.5f));
		}

		TEST_METHOD(Vec4ScalarDivision)
		{
			const XVector4 a(3.0f, -3.0f, 6.0f, 3.0f);
			const auto scale = 3.0f;
			Assert::AreEqual(a / scale, XVector4(1.0f, -1.0f, 2.0f, 1.0f));
		}
	};

	TEST_CLASS(MatrixUnitTest)
	{
		TEST_METHOD(Mat4X4Constructor)
		{
			XMatrix4 a{
				1.0f, 2.0f, 3.0f, 4.0f,
				5.5f, 6.5f, 7.5f, 8.5f,
				9.0f, 10.0f, 11.0f, 12.0f,
				13.5f, 14.5f, 15.5f, 16.5f
			};
			XMatrix4 b{
				{XVector4(1.0f, 2.0f, 3.0f, 4.0f)},
				{XVector4(5.5f, 6.5f, 7.5f, 8.5f)},
				{XVector4(9.0f, 10.0f, 11.0f, 12.0f)},
				{XVector4(13.5f, 14.5f, 15.5f, 16.5f)}
			};

			Assert::IsTrue(XMath::IsNearlyEqual(a.At(0, 0), 1.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(0, 3), 4.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(1, 0), 5.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(1, 2), 7.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(2, 2), 11.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(2, 3), 12.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(3, 0), 13.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(3, 2), 15.5f));

			Assert::IsTrue(XMath::IsNearlyEqual(b.At(0, 0), 1.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(0, 3), 4.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(1, 0), 5.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(1, 2), 7.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(2, 2), 11.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(2, 3), 12.0f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(3, 0), 13.5f));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(3, 2), 15.5f));
		}

		TEST_METHOD(MatrixMultiplication)
		{
			XMatrix4 a{
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				9.0f, 8.0f, 7.0f, 6.0f,
				5.0f, 4.0f, 3.0f, 2.0f
			};
			const XMatrix4 b{
				{XVector4(-2.0f, 1.0f, 2.0f, 3.0f)},
				{XVector4(3.0f, 2.0f, 1.0f, -1.0f)},
				{XVector4(4.0f, 3.0f, 6.0f, 5.0f)},
				{XVector4(1.0f, 2.0f, 7.0f, 8.0f)}
			};

			const XMatrix4 c{
				{XVector4(20.0f, 22.0f, 50.0f, 48.0f)},
				{XVector4(44.0f, 54.0f, 114.0f, 108.0f)},
				{XVector4(40.0f, 58.0f, 110.0f, 102.0f)},
				{XVector4(16.0f, 26.0f, 46.0f, 42.0f)}
			};

			Assert::AreEqual(c, a * b);
			a *= b;
			Assert::AreEqual(c, a);
		}

		TEST_METHOD(MatrixTranspose)
		{
			const XMatrix4 a{
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				9.0f, 8.0f, 7.0f, 6.0f,
				5.0f, 4.0f, 3.0f, 2.0f
			};

			const XMatrix4 transposed{
				1.0f, 5.0f, 9.0f, 5.0f,
				2.0f, 6.0f, 8.0f, 4.0f,
				3.0f, 7.0f, 7.0f, 3.0f,
				4.0f, 8.0f, 6.0f, 2.0f
			};

			const auto b = a.Tranpose();
			Assert::AreEqual(b, transposed);
		}

		TEST_METHOD(MatrixInvertable)
		{
			const XMatrix4 a{
				6.0f, 4.0f, 4.0f, 4.0f,
				5.0f, 5.0f, 7.0f, 6.0f,
				4.0f, -9.0f, 3.0f, -7.0f,
				9.0f, 1.0f, 7.0f, 6.0f
			};

			const XMatrix4 b{
				-4.0f, 2.0f, -2.0f, -3.0f,
				9.0f, 6.0f, 2.0f, 6.0f,
				0.0f, -5.0f, 1.0f, -5.0f,
				0.0f, 0.0f, 0.0f, 0.0f
			};

			Assert::IsTrue(a.IsMatrixInvertible());
			Assert::IsFalse(b.IsMatrixInvertible());
		}
		
		TEST_METHOD(MatrixInverse)
		{
			const XMatrix4 a{
				-5.0f, 2.0f, 6.0f, -8.0f,
				1.0f, -5.0f, 1.0f, 8.0f,
				7.0f, 7.0f, -6.0f, -7.0f,
				1.0f, -3.0f, 7.0f, 4.0f
			};

			const XMatrix4 inverse{
				0.21805f, 0.45113f, 0.24060f, -0.04511f,
				-0.80827f, -1.45677f, -0.44361f, 0.52068f,
				-0.07895f, -0.22368f, -0.05263f, 0.19737f,
				-0.52256f, -0.81391f, -0.30075f, 0.30639f
			};

			Assert::AreEqual(a.Inverse(), inverse);
		}

		//TEST_METHOD(Mat3X3Constructor) {
		//	XMatrix3 a{1.0f, 2.0f, 3.0f,
		//			  4.0f, 5.5f, 6.5f,
		//			  7.5f, 8.5f, 9.0f};
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,0), 1.0f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,2), 3.0f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,1), 5.5f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(2,2), 9.0f));
		//}
		//TEST_METHOD(Mat2X2Constructor) {
		//	XMatrix2 a{1.0f, 2.0f,
		//			  3.0f, 4.0f};
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,0), 1.0f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,1), 2.0f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,0), 3.0f));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,1), 4.0f));
		//}

		//TEST_METHOD(Mat4X4Comparison) {
		//	XMatrix4 a{1.0f, 2.0f, 3.0f, 4.0f,
		//			  5.5f, 6.5f, 7.5f, 8.5f,
		//			  9.0f, 10.0f, 11.0f, 12.0f,
		//			  13.5f, 14.5f, 15.5f, 16.5f};
		//	XMatrix4 b{1.0f, 2.0f, 3.0f, 4.0f,
		//			  5.5f, 6.5f, 7.5f, 8.5f,
		//			  9.0f, 10.0f, 11.0f, 12.0f,
		//			  13.5f, 14.5f, 15.5f, 16.5f};
		//	XMatrix4 c{2.0f, 2.0f, 3.0f, 4.0f,
		//			  5.5f, 6.5f, 7.5f, 8.5f,
		//			  9.0f, 10.0f, 11.0f, 12.0f,
		//			  13.5f, 14.5f, 15.5f, 16.5f};

		//	Assert::IsTrue(a == b);
		//	Assert::Isfalse(a == c);
		//}
	};

	TEST_CLASS(MathUnitTest)
	{
	public:
		TEST_METHOD(MathClamp)
		{
			const auto fa = -5.0f;
			const auto fb = 280.0f;
			auto fClamped = XMath::Clamp(fa, 0.0f, 255.0f);
			Assert::IsTrue(XMath::IsNearlyEqual(fClamped, 0.0f));
			fClamped = XMath::Clamp(fb, 0.0f, 255.0f);
			Assert::IsTrue(XMath::IsNearlyEqual(fClamped, 255.0f));
		}
	};

	TEST_CLASS(CanvasUnitTest)
	{
	public:
		TEST_METHOD(CreateCanvas)
		{
			const XCanvas canvas(256, 256);
			Assert::AreEqual(canvas.GetWidth(), 256);
			Assert::AreEqual(canvas.GetHeight(), 256);
		}

		TEST_METHOD(WriteToPixel)
		{
			XCanvas canvas(256, 256);
			const XVector red(255.0f, 0.0f, 0.0f);
			canvas.WriteToPixel(2, 3, red);
			Assert::AreEqual(canvas.GetPixel(2, 3), red);
		}

		TEST_METHOD(SaveCanvasAsPpm)
		{
			XCanvas canvas(3, 3);
			canvas.WriteToPixel(0, 0, XVector(255.0f, 0.0f, 0.0f));
			canvas.WriteToPixel(1, 1, XVector(0.0f, 255.0f, 255.0f));
			canvas.WriteToPixel(2, 2, XVector(0.0f, 0.0f, 255.0f));

			const auto filename = "imageOutput.ppm";
			XImageManager::SaveCanvasAsPpm(filename, canvas);

			std::ifstream readfile(filename);
			Assert::IsTrue(readfile.is_open());

			char out[256];
			readfile.getline(out, 256);
			readfile.getline(out, 256);
			readfile.getline(out, 256);
			readfile.getline(out, 256);
			Assert::AreEqual(out, "255 0 0 0 0 0 0 0 0 ");
			readfile.getline(out, 256);
			Assert::AreEqual(out, "0 0 0 0 255 255 0 0 0 ");
			readfile.getline(out, 256);
			Assert::AreEqual(out, "0 0 0 0 0 0 0 0 255 ");
		}
	};

	TEST_CLASS(ColorTest)
	{
		TEST_METHOD(ColorArithmetic)
		{
			const XColor a(0.9f, 0.6f, 0.75f);
			const XColor b(0.7f, 0.1f, 0.25f);
			const XColor c(1.0f, 0.2f, 0.4f);
			const XColor d(0.9f, 1.0f, 0.1f);

			Assert::AreEqual(XColor(1.6f, 0.7f, 1.0f), a + b);
			Assert::AreEqual(XColor(0.2f, 0.5f, 0.5f), a - b);
			Assert::AreEqual(XColor(2.0f, 0.4f, 0.8f), c * 2);
			Assert::AreEqual(XColor(0.9f, 0.2f, 0.04f), c * d);
		}
	};
}
