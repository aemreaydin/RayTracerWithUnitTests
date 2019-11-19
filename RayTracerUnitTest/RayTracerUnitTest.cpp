#include "pch.h"
#include "CppUnitTest.h"
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "XVector.h"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template<> std::wstring ToString<XVec4>(const XVec4& t) {
				std::stringstream ss;
				ss << "Vector4: " << t.X << ", " << t.Y << ", " << t.Z << ", " << t.W;				
				RETURN_WIDE_STRING(ss.str().c_str());
			}
		}
	}
}


namespace RayTracerUnitTest {
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
	};


	TEST_CLASS(MathUnitTest) {
	public:
	};
}
