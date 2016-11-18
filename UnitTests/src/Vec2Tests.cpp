#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{		
	TEST_CLASS(Vec2Tests)
	{
	public:
		
		TEST_METHOD(Vec2Constructor1)
		{
			vec2 v = vec2();
			Assert::AreEqual(v.x, 0.0f);
			Assert::AreEqual(v.y, 0.0f);
		}

		TEST_METHOD(Vec2Constructor2)
		{
			vec2 v = vec2(3.0f, 9.0f);
			Assert::AreEqual(v.x, 3.0f);
			Assert::AreEqual(v.y, 9.0f);
		}

		TEST_METHOD(Vec2Assign)
		{
			vec2 v1 = vec2();
			vec2 v2 = vec2(3.0f, 9.0f);
			v1 = v2;
			Assert::AreEqual(v2.x, v1.x);
			Assert::AreEqual(v2.y, v1.y);
		}

		TEST_METHOD(Vec2Equal1)
		{
			vec2 v1 = vec2(4.0f, 7.0f);
			vec2 v2 = vec2(4.0f, 7.0f);
			
			Assert::IsTrue(v1 == v2);
		}

		TEST_METHOD(Vec2Equal2)
		{
			vec2 v1 = vec2(4.0f, 7.0f);
			vec2 v2 = vec2(3.0f, 7.0f);

			Assert::IsFalse(v1 == v2);
		}


		TEST_METHOD(Vec2Differente1)
		{
			vec2 v1 = vec2(4.0f, 7.0f);
			vec2 v2 = vec2(3.0f, 7.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(Vec2Differente2)
		{
			vec2 v1 = vec2(4.0f, 7.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(Vec2Addition1) 
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			vec2 result = v1 + v2;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 10.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2Addition2)
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			vec2 result = v2 + v1;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 10.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2Difference1)
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			vec2 result = v1 - v2;
			Assert::AreEqual(result.x, -4.0f);
			Assert::AreEqual(result.y, -6.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2Difference2)
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			vec2 result = v2 - v1;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 6.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2Multiplication1)
		{
			vec2 v1 = vec2();

			vec2 result = v1 * 3.0f;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 0.0f);
		}

		TEST_METHOD(Vec2Multiplication2)
		{
			vec2 v2 = vec2(4.0f, 8.0f);

			vec2 result = v2 * 3.0f;
			Assert::AreEqual(result.x, 12.0f);
			Assert::AreEqual(result.y, 24.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2AssignAddition)
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			v1 += v2;
			Assert::AreEqual(v1.x, 4.0f);
			Assert::AreEqual(v1.y, 10.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2AssignDifference)
		{
			vec2 v1 = vec2(0.0f, 2.0f);
			vec2 v2 = vec2(4.0f, 8.0f);

			v1 -= v2;
			Assert::AreEqual(v1.x, -4.0f);
			Assert::AreEqual(v1.y, -6.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
		}

		TEST_METHOD(Vec2AssignMultiplication)
		{
			vec2 v1 = vec2(0.0f, 2.0f);

			v1 *= 3.0;
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 6.0f);
		}

		TEST_METHOD(Vec2Quadrance)
		{
			vec2 v1 = vec2(2.0f, 4.0f);
			float result = v1.quadrance();

			Assert::AreEqual(result, 20.0f);
		}

		TEST_METHOD(Vec2Norm)
		{
			vec2 v1 = vec2(0.0f, 5.0f);

			float result = v1.norm();

			Assert::AreEqual(result, 5.0f);
		}

		TEST_METHOD(Vec2normalize)
		{
			vec2 v1 = vec2(2.0f, 4.0f);

			vec2 result = v1.normalize();

			Assert::AreEqual(1.0f / sqrt(5.0f), result.x);
			Assert::AreEqual(2.0f / sqrt(5.0f), result.y);
		}

		TEST_METHOD(Vec2Dot1)
		{
			vec2 v1 = vec2(2.0f, 4.0f);
			vec2 v2 = vec2(8.0f, 16.0f);

			float result = v1.dot(v2);

			Assert::AreEqual(result, 80.0f);
		}

		TEST_METHOD(Vec2Dot2)
		{
			vec2 v1 = vec2(2.0f, 4.0f);
			vec2 v2 = vec2(8.0f, 16.0f);

			float result1 = v1.dot(v2);
			float result2 = v2.dot(v1);

			Assert::AreEqual(result1, result2);
		}

	};
}