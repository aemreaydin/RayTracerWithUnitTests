#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "../RayTracer/Vector.h"


namespace RayTracerUnitTest
{
	TEST_CLASS(Vector4UnitTest)
	{
	public:
		TEST_METHOD(Vec4IsPoint) {
			Vec4 pointVector(0.0F, 0.0F, 0.0F, 1.0F);
			Assert::IsTrue(pointVector.IsPoint());
		}
		TEST_METHOD(Vec4IsVector) {
			Vec4 vectorVector(0.0F, 0.0F, 0.0F, 0.0F);
			Assert::IsFalse(vectorVector.IsPoint());
		}

		TEST_METHOD(VecAddition) {
			Vec4 a(3.0F, -2.0F, 5.0F, 1.0f);
			Vec4 b(-2.0F, 3.0F, 1.0F, 0.0F);
			Vec4 sum(1.0F, 1.0F, 6.0F, 1.0F);
			Vec4 c(1.0F, 1.0F, 6.0F, 1.0F);
			Assert::IsTrue(sum == c);
		}
	};


	TEST_CLASS(MathUnitTest)
	{
	public:

	};
}
