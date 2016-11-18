#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(Vec3Tests)
	{
	public:

		TEST_METHOD(Vec3Constructor1)
		{
			vec3 v = vec3();
			Assert::AreEqual(v.x, 0.0f);
			Assert::AreEqual(v.y, 0.0f);
			Assert::AreEqual(v.z, 0.0f);
		}

		TEST_METHOD(Vec3Constructor2)
		{
			vec3 v = vec3(3.0f, 9.0f, 16.0f);
			Assert::AreEqual(v.x, 3.0f);
			Assert::AreEqual(v.y, 9.0f);
			Assert::AreEqual(v.z, 16.0f);
		}

		TEST_METHOD(Vec3Assign)
		{
			vec3 v1 = vec3();
			vec3 v2 = vec3(3.0f, 9.0f, 16.0f);
			v1 = v2;
			Assert::AreEqual(v2.x, v1.x);
			Assert::AreEqual(v2.y, v1.y);
			Assert::AreEqual(v2.z, v1.z);
		}

		TEST_METHOD(Vec3Equal1)
		{
			vec3 v1 = vec3(4.0f, 7.0002f, 3.0f);
			vec3 v2 = vec3(4.0f, 7.0f, 3.0f);

			Assert::IsTrue(v1 == v2);
		}

		TEST_METHOD(Vec3Equal2)
		{
			vec3 v1 = vec3(4.0f, 7.0f, 3.0f);
			vec3 v2 = vec3(4.0f, 7.0f, 5.0f);

			Assert::IsFalse(v1 == v2);
		}


		TEST_METHOD(Vec3Differente1)
		{
			vec3 v1 = vec3(4.0f, 7.0f, 5.0f);
			vec3 v2 = vec3(3.0f, 7.0f, 5.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(Vec3Differente2)
		{
			vec3 v1 = vec3(4.0f, 7.0f, 5.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 5.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(Vec3Differente3)
		{
			vec3 v1 = vec3(4.0f, 7.0f, 5.0f);
			vec3 v2 = vec3(4.0f, 7.0f, 6.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(Vec3Addition1)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 9.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 1.0f);

			vec3 result = v1 + v2;
			Assert::AreEqual(4.0f, result.x);
			Assert::AreEqual(10.0f, result.y);
			Assert::AreEqual(10.0f, result.z);
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(2.0f, v1.y);
			Assert::AreEqual(9.0f, v1.z);
			Assert::AreEqual(4.0f, v2.x);
			Assert::AreEqual(8.0f, v2.y);
			Assert::AreEqual(1.0f, v2.z);
		}

		TEST_METHOD(Vec3Addition2)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 9.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 1.0f);

			vec3 result = v2 + v1;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 10.0f);
			Assert::AreEqual(result.z, 10.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 9.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 1.0f);
		}

		TEST_METHOD(Vec3Difference1)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 1.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 1.0f);

			vec3 result = v1 - v2;
			Assert::AreEqual(result.x, -4.0f);
			Assert::AreEqual(result.y, -6.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 1.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 1.0f);
		}

		TEST_METHOD(Vec3Difference2)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 1.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 1.0f);

			vec3 result = v2 - v1;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 6.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 1.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 1.0f);
		}

		TEST_METHOD(Vec3Multiplication1)
		{
			vec3 v1 = vec3();

			vec3 result = v1 * 3.0f;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 0.0f);
			Assert::AreEqual(v1.z, 0.0f);
		}

		TEST_METHOD(Vec3Multiplication2)
		{
			vec3 v2 = vec3(4.0f, 8.0f, 2.0f);

			vec3 result = v2 * 3.0f;
			Assert::AreEqual(result.x, 12.0f);
			Assert::AreEqual(result.y, 24.0f);
			Assert::AreEqual(result.z, 6.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 2.0f);
		}

		TEST_METHOD(Vec3AssignAddition)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 3.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 5.0f);

			v1 += v2;
			Assert::AreEqual(v1.x, 4.0f);
			Assert::AreEqual(v1.y, 10.0f);
			Assert::AreEqual(v1.z, 8.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 5.0f);
		}

		TEST_METHOD(Vec3AssignDifference)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 3.0f);
			vec3 v2 = vec3(4.0f, 8.0f, 5.0f);

			v1 -= v2;
			Assert::AreEqual(v1.x, -4.0f);
			Assert::AreEqual(v1.y, -6.0f);
			Assert::AreEqual(v1.z, -2.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 5.0f);
		}

		TEST_METHOD(Vec3AssignMultiplication)
		{
			vec3 v1 = vec3(0.0f, 2.0f, 4.0f);

			v1 *= 3.0;
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(6.0f, v1.y);
			Assert::AreEqual(12.0f, v1.z);
		}

		TEST_METHOD(Vec3Quadrance)
		{
			vec3 v1 = vec3(2.0f, 4.0f, 8.0f);
			float result = v1.quadrance();

			Assert::AreEqual(result, 84.0f);
		}

		TEST_METHOD(Vec3Norm)
		{
			vec3 v1 = vec3(0.0f, 5.0f, 7.0f);

			float result = v1.norm();

			Assert::AreEqual(result, sqrt(74.0f));
		}

		TEST_METHOD(Vec3normalize)
		{
			vec3 v1 = vec3(2.0f, 4.0f, 8.0f);

			vec3 result = v1.normalize();

			Assert::AreEqual(1.0f / sqrt(21.0f), result.x);
			Assert::AreEqual(2.0f / sqrt(21.0f), result.y);
			Assert::AreEqual(4.0f / sqrt(21.0f), result.z);
		}

		TEST_METHOD(Vec3Dot1)
		{
			vec3 v1 = vec3(2.0f, 4.0f, 8.0f);
			vec3 v2 = vec3(16.0f, 32.0f, 64.0f);

			float result = v1.dot(v2);

			Assert::AreEqual(result, 672.0f);
		}

		TEST_METHOD(Vec3Dot2)
		{
			vec3 v1 = vec3(2.0f, 4.0f, 10.0f);
			vec3 v2 = vec3(8.0f, 16.0f, 10.0f);

			float result1 = v1.dot(v2);
			float result2 = v2.dot(v1);

			Assert::AreEqual(result1, result2);
		}

		TEST_METHOD(Vec3Cross1)
		{
			vec3 v1 = vec3(2.0f, 4.0f, 8.0f);
			vec3 v2 = vec3(16.0f, 32.0f, 64.0f);

			vec3 result = v1.cross(v2);

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
			Assert::AreEqual(result.z, 0.0f);
		}

		TEST_METHOD(Vec3Cross2)
		{
			vec3 v1 = vec3(2.0f, 2.0f, 2.0f);
			vec3 v2 = vec3(16.0f, 10.0f, 64.0f);

			vec3 result = v1.cross(v2);

			Assert::AreEqual(result.x, 108.0f);
			Assert::AreEqual(result.y, -96.0f);
			Assert::AreEqual(result.z, -12.0f);
		}
	};
}