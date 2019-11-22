#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "XMath.h"
#include "XVector.h"
#include "XCanvas.h"
#include "XImageManager.h"

using VMath3 = XVectorMath<XVec3>;
using VMath4 = XVectorMath<XVec4>;

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> std::wstring ToString<XVec4>(const XVec4& t) {
				std::stringstream ss;
				ss << "Vector4: " << t.X << ", " << t.Y << ", " << t.Z << ", " << t.W;
				RETURN_WIDE_STRING(ss.str().c_str());
			}
			template<> std::wstring ToString<XVec3>(const XVec3& t) {
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
			const XVec3 a(3.0F, 4.0F, 5.0F);
			const XVec3 b(7.0F, 1.0F, 0.0F);
			Assert::IsTrue(XMath::IsEqual(sqrtf(50), VMath3::Magnitude(a)));
			Assert::IsTrue(XMath::IsEqual(VMath3::Magnitude(a), VMath3::Magnitude(b)));
		}
		TEST_METHOD(Vec3Normalize) {
			const XVec3 a(3.0F, 4.0F, 0.0F);
			Assert::AreEqual(VMath3::Normalize(a), XVec3(0.6F, 0.8F, 0.0F));
			Assert::IsTrue(XMath::IsEqual(VMath3::Magnitude(VMath3::Normalize(a)), 1.0F));
		}

		TEST_METHOD(Vec3DotProduct) {
			const XVec3 a(3.0F, 4.0F, 5.0F);
			const XVec3 b(2.0F, 1.0F, 8.0F);
			Assert::IsTrue(XMath::IsEqual(VMath3::DotProduct(a, b), 50.0F));
		}

		TEST_METHOD(Vec3CrossProduct) {
			const XVec3 a(1.0F, 2.0F, 3.0F);
			const XVec3 b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(VMath3::CrossProduct(a, b), XVec3(-1.0F, 2.0F, -1.0F));
			Assert::AreEqual(VMath3::CrossProduct(b, a), XVec3(1.0F, -2.0F, 1.0F));
		}

		TEST_METHOD(Vec3ElementWiseMultiplication) {
			const XVec3 a(1.0F, 2.0F, 3.0F);
			const XVec3 b(2.0F, 3.0F, 4.0F);
			Assert::AreEqual(a * b, XVec3(2.0F, 6.0F, 12.0F));
		}
	};

	TEST_CLASS(Vector4UnitTest) {
public:
	TEST_METHOD(Vec4IsPoint) {
		const XVec4 pointVector(0.0F, 0.0F, 0.0F, 1.0F);
		Assert::IsTrue(pointVector.IsPoint());
	}

	TEST_METHOD(Vec4IsVector) {
		const XVec4 vectorVector(0.0F, 0.0F, 0.0F, 0.0F);
		Assert::IsFalse(vectorVector.IsPoint());
	}

	TEST_METHOD(Vec4Addition) {
		const XVec4 a(3.0F, -2.0F, 5.0F, 1.0f);
		const XVec4 b(-2.0F, 3.0F, 1.0F, 0.0F);
		Assert::IsTrue(a + b == XVec4(1.0F, 1.0F, 6.0F, 1.0F));
	}

	TEST_METHOD(Vec4Subtraction) {
		const XVec4 a(3.0F, -2.0F, 5.0F, 1.0f);
		const XVec4 b(-2.0F, 3.0F, 1.0F, 0.0F);
		Assert::AreEqual(a - b, XVec4(5.0F, -5.0F, 4.0F, 1.0F));
	}

	TEST_METHOD(Vec4Negation) {
		const XVec4 a(3.0F, -3.0F, 2.0F, 1.0F);
		const XVec4 b(-3.0F, 3.0F, -2.0F, -1.0F);
		Assert::AreEqual(a, -b);
	}

	TEST_METHOD(Vec4ScalarMultiplication) {
		const XVec4 a(3.0F, -3.0F, 6.0F, 3.0F);
		const auto scale = 3.0F;
		const auto fraction = .5F;
		Assert::AreEqual(a * scale, XVec4(9.0F, -9.0F, 18.0F, 9.0F));
		Assert::AreEqual(a * fraction, XVec4(1.5F, -1.5F, 3.0F, 1.5F));
	}

	TEST_METHOD(Vec4ScalarDivision) {
		const XVec4 a(3.0F, -3.0F, 6.0F, 3.0F);
		const auto scale = 3.0F;
		Assert::AreEqual(a / scale, XVec4(1.0F, -1.0F, 2.0F, 1.0F));
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
			const XVec3 red(255.0F, 0.0F, 0.0F);
			canvas.WritePixel(2, 3, red);
			Assert::AreEqual(canvas.GetPixel(2, 3), red);
		}

		TEST_METHOD(SaveCanvasAsPpm) {
			XCanvas canvas(3, 3);
			canvas.WritePixel(0, 0, XVec3(255.0F, 0.0F, 0.0F));
			canvas.WritePixel(1, 1, XVec3(0.0F, 255.0F, 255.0F));
			canvas.WritePixel(2, 2, XVec3(0.0F, 0.0F, 255.0F));

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