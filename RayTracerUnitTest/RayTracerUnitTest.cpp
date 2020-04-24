#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "XMath.h"
#include "XVector.h"
#include "XVector4.h"
#include "XMatrix.h"
#include "XCanvas.h"
#include "XImageManager.h"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> std::wstring ToString<XVector4>(const XVector4& t) {				
				RETURN_WIDE_STRING(t.ToString().c_str());
			}
			template<> std::wstring ToString<XVector>(const XVector& t) {
				RETURN_WIDE_STRING(t.ToString().c_str());
			}
		}
	}
}

namespace RayTracerUnitTest {
	TEST_CLASS(Vector3UnitTest) {
		TEST_METHOD(Vec3Magnitude) {
			const XVector a(3.0F, 4.0F, 5.0F);
			const XVector b(7.0F, 1.0F, 0.0F);
			Assert::IsTrue(XMath::IsNearlyEqual(sqrtf(50), a.Magnitude()));
			Assert::IsTrue(XMath::IsNearlyEqual(a.Magnitude(), b.Magnitude()));
		}
		TEST_METHOD(Vec3Normalize) {
			XVector a(3.0F, 4.0F, 0.0F);
			Assert::IsTrue(a.Normalize());
			Assert::AreEqual(a, XVector(0.6F, 0.8F, 0.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.Magnitude(), 1.0F));
		}

		TEST_METHOD(Vec3DotProduct) {
			const XVector a(3.0F, 4.0F, 5.0F);
			const XVector b(2.0F, 1.0F, 8.0F);
			Assert::IsTrue(XMath::IsNearlyEqual(XVector::DotProduct(a, b), 50.0F));
		}

		TEST_METHOD(Vec3CrossProduct) {
			const XVector a(1.0F, 2.0F, 3.0F);
			const XVector b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(XVector::CrossProduct(a, b), XVector(-1.0F, 2.0F, -1.0F));
			Assert::AreEqual(XVector::CrossProduct(b, a), XVector(1.0F, -2.0F, 1.0F));
		}

		TEST_METHOD(Vec3ElementWiseMultiplication) {
			const XVector a(1.0F, 2.0F, 3.0F);
			const XVector b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(a * b, XVector(2.0F, 6.0F, 12.0F));
		}
	};

	TEST_CLASS(Vector4UnitTest) {
public:
	TEST_METHOD(Vec4Addition) {
		const XVector4 a(3.0F, -2.0F, 5.0F, 1.0f);
		const XVector4 b(-2.0F, 3.0F, 1.0F, 0.0F);
		Assert::IsTrue(a + b == XVector4(1.0F, 1.0F, 6.0F, 1.0F));
	}

	TEST_METHOD(Vec4Subtraction) {
		const XVector4 a(3.0F, -2.0F, 5.0F, 1.0f);
		const XVector4 b(-2.0F, 3.0F, 1.0F, 0.0F);
		Assert::AreEqual(a - b, XVector4(5.0F, -5.0F, 4.0F, 1.0F));
	}

	TEST_METHOD(Vec4Negation) {
		const XVector4 a(3.0F, -3.0F, 2.0F, 1.0F);
		const XVector4 b(-3.0F, 3.0F, -2.0F, -1.0F);
		Assert::AreEqual(a, -b);
	}

	TEST_METHOD(Vec4ScalarMultiplication) {
		const XVector4 a(3.0F, -3.0F, 6.0F, 3.0F);
		const auto scale = 3.0F;
		const auto fraction = .5F;
		Assert::AreEqual(a * scale, XVector4(9.0F, -9.0F, 18.0F, 9.0F));
		Assert::AreEqual(a * fraction, XVector4(1.5F, -1.5F, 3.0F, 1.5F));
	}

	TEST_METHOD(Vec4ScalarDivision) {
		const XVector4 a(3.0F, -3.0F, 6.0F, 3.0F);
		const auto scale = 3.0F;
		Assert::AreEqual(a / scale, XVector4(1.0F, -1.0F, 2.0F, 1.0F));
	}
	};

	TEST_CLASS(MatrixUnitTest) {
		TEST_METHOD(Mat4X4Constructor) {
			XMatrix4 a{1.0F, 2.0F, 3.0F, 4.0F,
					  5.5F, 6.5F, 7.5F, 8.5F,
					  9.0F, 10.0F, 11.0F, 12.0F,
					  13.5F, 14.5F, 15.5F, 16.5f};
			XMatrix4 b{{XVector4(1.0F, 2.0F, 3.0F, 4.0F)},
					 {XVector4(5.5F, 6.5F, 7.5F, 8.5F)},
					 {XVector4(9.0F, 10.0F, 11.0F, 12.0F)},
					 {XVector4(13.5F, 14.5F, 15.5F, 16.5f)}};

			Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,3), 4.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,0), 5.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,2), 7.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(2,2), 11.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(2,3), 12.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(3,0), 13.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(a.At(3,2), 15.5F));

			Assert::IsTrue(XMath::IsNearlyEqual(b.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(0,3), 4.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(1,0), 5.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(1,2), 7.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(2,2), 11.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(2,3), 12.0F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(3,0), 13.5F));
			Assert::IsTrue(XMath::IsNearlyEqual(b.At(3,2), 15.5F));
		}
		//TEST_METHOD(Mat3X3Constructor) {
		//	XMatrix3 a{1.0F, 2.0F, 3.0F,
		//			  4.0F, 5.5F, 6.5F,
		//			  7.5F, 8.5F, 9.0F};
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,0), 1.0F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,2), 3.0F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,1), 5.5F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(2,2), 9.0F));
		//}
		//TEST_METHOD(Mat2X2Constructor) {
		//	XMatrix2 a{1.0F, 2.0F,
		//			  3.0F, 4.0F};
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,0), 1.0F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(0,1), 2.0F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,0), 3.0F));
		//	Assert::IsTrue(XMath::IsNearlyEqual(a.At(1,1), 4.0F));
		//}

		//TEST_METHOD(Mat4X4Comparison) {
		//	XMatrix4 a{1.0F, 2.0F, 3.0F, 4.0F,
		//			  5.5F, 6.5F, 7.5F, 8.5F,
		//			  9.0F, 10.0F, 11.0F, 12.0F,
		//			  13.5F, 14.5F, 15.5F, 16.5f};
		//	XMatrix4 b{1.0F, 2.0F, 3.0F, 4.0F,
		//			  5.5F, 6.5F, 7.5F, 8.5F,
		//			  9.0F, 10.0F, 11.0F, 12.0F,
		//			  13.5F, 14.5F, 15.5F, 16.5f};
		//	XMatrix4 c{2.0F, 2.0F, 3.0F, 4.0F,
		//			  5.5F, 6.5F, 7.5F, 8.5F,
		//			  9.0F, 10.0F, 11.0F, 12.0F,
		//			  13.5F, 14.5F, 15.5F, 16.5f};

		//	Assert::IsTrue(a == b);
		//	Assert::IsFalse(a == c);
		//}
	};

	TEST_CLASS(MathUnitTest) {
public:
		TEST_METHOD(MathClamp) {
			const auto fa = -5.0F;
			const auto fb = 280.0F;
			auto fClamped = XMath::Clamp(fa, 0.0F, 255.0F);
			Assert::IsTrue(XMath::IsNearlyEqual(fClamped, 0.0F));
			fClamped = XMath::Clamp(fb, 0.0F, 255.0F);
			Assert::IsTrue(XMath::IsNearlyEqual(fClamped, 255.0F));
		}
	};

	TEST_CLASS(CanvasUnitTest) {
public:
		TEST_METHOD(CreateCanvas) {
			const XCanvas canvas(256, 256);
			Assert::AreEqual(canvas.GetWidth(), 256);
			Assert::AreEqual(canvas.GetHeight(), 256);
		}

		TEST_METHOD(WriteToPixel) {
			XCanvas canvas(256, 256);
			const XVector red(255.0F, 0.0F, 0.0F);
			canvas.WriteToPixel(2, 3, red);
			Assert::AreEqual(canvas.GetPixel(2, 3), red);
		}

		TEST_METHOD(SaveCanvasAsPpm) {
			XCanvas canvas(3, 3);
			canvas.WriteToPixel(0, 0, XVector(255.0F, 0.0F, 0.0F));
			canvas.WriteToPixel(1, 1, XVector(0.0F, 255.0F, 255.0F));
			canvas.WriteToPixel(2, 2, XVector(0.0F, 0.0F, 255.0F));

			const auto filename = "imageOutput.ppm";
			XImageManager::SaveCanvasAsPpm(filename, canvas);

			std::ifstream readFile(filename);
			Assert::IsTrue(readFile.is_open());

			char out[256];
			readFile.getline(out, 256);
			readFile.getline(out, 256);
			readFile.getline(out, 256);
			readFile.getline(out, 256);
			Assert::AreEqual(out, "255 0 0 0 0 0 0 0 0 ");
			readFile.getline(out, 256);
			Assert::AreEqual(out, "0 0 0 0 255 255 0 0 0 ");
			readFile.getline(out, 256);
			Assert::AreEqual(out, "0 0 0 0 0 0 0 0 255 ");
		}
	};
}