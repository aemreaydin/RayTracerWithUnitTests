#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "XMath.h"
#include "XVector.h"
#include "XMatrix.h"
#include "XCanvas.h"
#include "XImageManager.h"

using VMath3 = XVectorMath<XVector>;
using VMath4 = XVectorMath<XVector4>;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> std::wstring ToString<XVector4>(const XVector4& t) {
				std::stringstream ss;
				ss << "Vector4: " << t.X << ", " << t.Y << ", " << t.Z << ", " << t.W;
				RETURN_WIDE_STRING(ss.str().c_str());
			}
			template<> std::wstring ToString<XVector>(const XVector& t) {
				std::stringstream ss;
				ss << "Vector4: " << t.X << ", " << t.Y << ", " << t.Z;
				RETURN_WIDE_STRING(ss.str().c_str());
			}
		}
	}
}

namespace RayTracerUnitTest {
	TEST_CLASS(Vector3UnitTest) {
		// TODO Same tests from Vec4
		TEST_METHOD(Vec3Magnitude) {
			const XVector a(3.0F, 4.0F, 5.0F);
			const XVector b(7.0F, 1.0F, 0.0F);
			Assert::IsTrue(XMath::IsEqual(sqrtf(50), VMath3::Magnitude(a)));
			Assert::IsTrue(XMath::IsEqual(VMath3::Magnitude(a), VMath3::Magnitude(b)));
		}
		TEST_METHOD(Vec3Normalize) {
			const XVector a(3.0F, 4.0F, 0.0F);
			Assert::AreEqual(VMath3::Normalize(a), XVector(0.6F, 0.8F, 0.0F));
			Assert::IsTrue(XMath::IsEqual(VMath3::Magnitude(VMath3::Normalize(a)), 1.0F));
		}

		TEST_METHOD(Vec3DotProduct) {
			const XVector a(3.0F, 4.0F, 5.0F);
			const XVector b(2.0F, 1.0F, 8.0F);
			Assert::IsTrue(XMath::IsEqual(VMath3::DotProduct(a, b), 50.0F));
		}

		TEST_METHOD(Vec3CrossProduct) {
			const XVector a(1.0F, 2.0F, 3.0F);
			const XVector b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(VMath3::CrossProduct(a, b), XVector(-1.0F, 2.0F, -1.0F));
			Assert::AreEqual(VMath3::CrossProduct(b, a), XVector(1.0F, -2.0F, 1.0F));
		}

		TEST_METHOD(Vec3ElementWiseMultiplication) {
			const XVector a(1.0F, 2.0F, 3.0F);
			const XVector b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(a * b, XVector(2.0F, 6.0F, 12.0F));
		}
	};

	TEST_CLASS(Vector4UnitTest) {
public:
	TEST_METHOD(Vec4IsPoint) {
		const XVector4 pointVector(0.0F, 0.0F, 0.0F, 1.0F);
		Assert::IsTrue(pointVector.IsPoint());
	}

	TEST_METHOD(Vec4IsVector) {
		const XVector4 vectorVector(0.0F, 0.0F, 0.0F, 0.0F);
		Assert::IsFalse(vectorVector.IsPoint());
	}

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
			XMat4x4 a{1.0F, 2.0F, 3.0F, 4.0F,
					  5.5F, 6.5F, 7.5F, 8.5F,
					  9.0F, 10.0F, 11.0F, 12.0F,
					  13.5F, 14.5F, 15.5F, 16.5f};
			XMat4x4 b{{XVector4(1.0F, 2.0F, 3.0F, 4.0F)},
					 {XVector4(5.5F, 6.5F, 7.5F, 8.5F)},
					 {XVector4(9.0F, 10.0F, 11.0F, 12.0F)},
					 {XVector4(13.5F, 14.5F, 15.5F, 16.5f)}};

			Assert::IsTrue(XMath::IsEqual(a.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(0,3), 4.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(1,0), 5.5F));
			Assert::IsTrue(XMath::IsEqual(a.At(1,2), 7.5F));
			Assert::IsTrue(XMath::IsEqual(a.At(2,2), 11.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(2,3), 12.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(3,0), 13.5F));
			Assert::IsTrue(XMath::IsEqual(a.At(3,2), 15.5F));

			Assert::IsTrue(XMath::IsEqual(b.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsEqual(b.At(0,3), 4.0F));
			Assert::IsTrue(XMath::IsEqual(b.At(1,0), 5.5F));
			Assert::IsTrue(XMath::IsEqual(b.At(1,2), 7.5F));
			Assert::IsTrue(XMath::IsEqual(b.At(2,2), 11.0F));
			Assert::IsTrue(XMath::IsEqual(b.At(2,3), 12.0F));
			Assert::IsTrue(XMath::IsEqual(b.At(3,0), 13.5F));
			Assert::IsTrue(XMath::IsEqual(b.At(3,2), 15.5F));
		}
		TEST_METHOD(Mat3X3Constructor) {
			XMat3x3 a{1.0F, 2.0F, 3.0F,
					  4.0F, 5.5F, 6.5F,
					  7.5F, 8.5F, 9.0F};
			Assert::IsTrue(XMath::IsEqual(a.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(0,2), 3.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(1,1), 5.5F));
			Assert::IsTrue(XMath::IsEqual(a.At(2,2), 9.0F));
		}
		TEST_METHOD(Mat2X2Constructor) {
			XMat2x2 a{1.0F, 2.0F,
					  3.0F, 4.0F};
			Assert::IsTrue(XMath::IsEqual(a.At(0,0), 1.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(0,1), 2.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(1,0), 3.0F));
			Assert::IsTrue(XMath::IsEqual(a.At(1,1), 4.0F));
		}

		TEST_METHOD(Mat4X4Comparison) {
			XMat4x4 a{1.0F, 2.0F, 3.0F, 4.0F,
					  5.5F, 6.5F, 7.5F, 8.5F,
					  9.0F, 10.0F, 11.0F, 12.0F,
					  13.5F, 14.5F, 15.5F, 16.5f};
			XMat4x4 b{1.0F, 2.0F, 3.0F, 4.0F,
					  5.5F, 6.5F, 7.5F, 8.5F,
					  9.0F, 10.0F, 11.0F, 12.0F,
					  13.5F, 14.5F, 15.5F, 16.5f};
			XMat4x4 c{2.0F, 2.0F, 3.0F, 4.0F,
					  5.5F, 6.5F, 7.5F, 8.5F,
					  9.0F, 10.0F, 11.0F, 12.0F,
					  13.5F, 14.5F, 15.5F, 16.5f};

			Assert::IsTrue(a == b);
			Assert::IsFalse(a == c);
		}
	};

	TEST_CLASS(MathUnitTest) {
public:
		TEST_METHOD(MathClamp) {
			const auto fa = -5.0F;
			const auto fb = 280.0F;
			auto fClamped = XMath::Clamp(fa, 0.0F, 255.0F);
			Assert::IsTrue(XMath::IsEqual(fClamped, 0.0F));
			fClamped = XMath::Clamp(fb, 0.0F, 255.0F);
			Assert::IsTrue(XMath::IsEqual(fClamped, 255.0F));
		}
	};

	TEST_CLASS(CanvasUnitTest) {
public:
		TEST_METHOD(CreateCanvas) {
			const XCanvas canvas(256, 256);
			Assert::AreEqual(canvas.GetWidth(), 256);
			Assert::AreEqual(canvas.GetHeight(), 256);
		}

		TEST_METHOD(WritePixel) {
			XCanvas canvas(256, 256);
			const XVector red(255.0F, 0.0F, 0.0F);
			canvas.WritePixel(2, 3, red);
			Assert::AreEqual(canvas.GetPixel(2, 3), red);
		}

		TEST_METHOD(SaveCanvasAsPpm) {
			XCanvas canvas(3, 3);
			canvas.WritePixel(0, 0, XVector(255.0F, 0.0F, 0.0F));
			canvas.WritePixel(1, 1, XVector(0.0F, 255.0F, 255.0F));
			canvas.WritePixel(2, 2, XVector(0.0F, 0.0F, 255.0F));

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