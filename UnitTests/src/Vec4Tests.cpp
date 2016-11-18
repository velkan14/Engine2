#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(vec4Tests)
	{
	public:

		TEST_METHOD(vec4Constructor1)
		{
			vec4 v = vec4();
			Assert::AreEqual(v.x, 0.0f);
			Assert::AreEqual(v.y, 0.0f);
			Assert::AreEqual(v.z, 0.0f);
			Assert::AreEqual(v.w, 0.0f);
		}

		TEST_METHOD(vec4Constructor2)
		{
			vec4 v = vec4(3.0f, 9.0f, 16.0f, 4.0f);
			Assert::AreEqual(3.0f, v.x);
			Assert::AreEqual(9.0f, v.y);
			Assert::AreEqual(16.0f, v.z);
			Assert::AreEqual(4.0f, v.w);
		}

		TEST_METHOD(vec4Assign)
		{
			vec4 v1 = vec4();
			vec4 v2 = vec4(3.0f, 9.0f, 16.0f, 4.0f);
			v1 = v2;
			Assert::AreEqual(v2.x, v1.x);
			Assert::AreEqual(v2.y, v1.y);
			Assert::AreEqual(v2.z, v1.z);
			Assert::AreEqual(v2.w, v1.w);
		}

		TEST_METHOD(vec4Equal1)
		{
			vec4 v1 = vec4(4.0f, 7.0f, 3.0f, 9.0f);
			vec4 v2 = vec4(4.0f, 7.0f, 3.0f, 9.0f);

			Assert::IsTrue(v1 == v2);
			Assert::IsTrue(v2 == v1);
		}

		TEST_METHOD(vec4Equal2)
		{
			vec4 v1 = vec4(4.0f, 7.0f, 5.0f, 2.0f);
			vec4 v2 = vec4(4.0f, 7.0f, 5.0f, 3.0f);

			Assert::IsFalse(v1 == v2);
			Assert::IsFalse(v2 == v1);
		}


		TEST_METHOD(vec4Differente1)
		{
			vec4 v1 = vec4(3.0f, 7.0f, 5.0f, 4.0f);
			vec4 v2 = vec4(3.0f, 7.0f, 5.0f, 3.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(vec4Differente2)
		{
			vec4 v1 = vec4(4.0f, 7.0f, 5.0f, 2.0f);
			vec4 v2 = vec4(4.0f, 7.0f, 5.0f, 2.0f);

			Assert::IsFalse(v1 != v2);
		}

		TEST_METHOD(vec4Differente3)
		{
			vec4 v1 = vec4(4.0f, 7.0f, 6.0f, 3.0f);
			vec4 v2 = vec4(4.0f, 7.0f, 6.0f, 14.0f);

			Assert::IsTrue(v1 != v2);
		}

		TEST_METHOD(vec4Addition1)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 9.0f, 3.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 1.0f, 3.0f);

			vec4 result = v1 + v2;
			Assert::AreEqual(4.0f, result.x);
			Assert::AreEqual(10.0f, result.y);
			Assert::AreEqual(10.0f, result.z);
			Assert::AreEqual(6.0f, result.w);
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(2.0f, v1.y);
			Assert::AreEqual(9.0f, v1.z);
			Assert::AreEqual(3.0f, v1.w);
			Assert::AreEqual(4.0f, v2.x);
			Assert::AreEqual(8.0f, v2.y);
			Assert::AreEqual(1.0f, v2.z);
			Assert::AreEqual(3.0f, v2.w);
		}

		TEST_METHOD(vec4Addition2)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 9.0f, 3.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 1.0f, 3.0f);

			vec4 result = v2 + v1;
			Assert::AreEqual(4.0f, result.x);
			Assert::AreEqual(10.0f, result.y);
			Assert::AreEqual(10.0f, result.z);
			Assert::AreEqual(6.0f, result.w);
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(2.0f, v1.y);
			Assert::AreEqual(9.0f, v1.z);
			Assert::AreEqual(3.0f, v1.w);
			Assert::AreEqual(4.0f, v2.x);
			Assert::AreEqual(8.0f, v2.y);
			Assert::AreEqual(1.0f, v2.z);
			Assert::AreEqual(3.0f, v2.w);
		}

		TEST_METHOD(vec4Difference1)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 1.0f, 3.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 1.0f, 2.0f);

			vec4 result = v1 - v2;
			Assert::AreEqual(result.x, -4.0f);
			Assert::AreEqual(result.y, -6.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(result.w, 1.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 1.0f);
			Assert::AreEqual(v1.w, 3.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 1.0f);
			Assert::AreEqual(v2.w, 2.0f);
		}

		TEST_METHOD(vec4Difference2)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 1.0f, 3.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 1.0f, 2.0f);

			vec4 result = v2 - v1;
			Assert::AreEqual(result.x, 4.0f);
			Assert::AreEqual(result.y, 6.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(result.w, -1.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 2.0f);
			Assert::AreEqual(v1.z, 1.0f);
			Assert::AreEqual(v1.w, 3.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 1.0f);
			Assert::AreEqual(v2.w, 2.0f);
		}

		TEST_METHOD(vec4Multiplication1)
		{
			vec4 v1 = vec4();

			vec4 result = v1 * 3.0f;

			Assert::AreEqual(result.x, 0.0f);
			Assert::AreEqual(result.y, 0.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(result.z, 0.0f);
			Assert::AreEqual(v1.x, 0.0f);
			Assert::AreEqual(v1.y, 0.0f);
			Assert::AreEqual(v1.z, 0.0f);
			Assert::AreEqual(v1.z, 0.0f);
		}

		TEST_METHOD(vec4Multiplication2)
		{
			vec4 v2 = vec4(4.0f, 8.0f, 2.0f, 1.0f);

			vec4 result = v2 * 3.0f;
			Assert::AreEqual(result.x, 12.0f);
			Assert::AreEqual(result.y, 24.0f);
			Assert::AreEqual(result.z, 6.0f);
			Assert::AreEqual(result.w, 3.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 2.0f);
			Assert::AreEqual(v2.w, 1.0f);
		}

		TEST_METHOD(vec4AssignAddition)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 3.0f, 5.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 5.0f, 5.0f);

			v1 += v2;
			Assert::AreEqual(v1.x, 4.0f);
			Assert::AreEqual(v1.y, 10.0f);
			Assert::AreEqual(v1.z, 8.0f);
			Assert::AreEqual(v1.w, 10.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 5.0f);
			Assert::AreEqual(v2.w, 5.0f);
		}

		TEST_METHOD(vec4AssignDifference)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 3.0f, 5.0f);
			vec4 v2 = vec4(4.0f, 8.0f, 5.0f, 5.0f);

			v1 -= v2;
			Assert::AreEqual(v1.x, -4.0f);
			Assert::AreEqual(v1.y, -6.0f);
			Assert::AreEqual(v1.z, -2.0f);
			Assert::AreEqual(v1.w, 0.0f);
			Assert::AreEqual(v2.x, 4.0f);
			Assert::AreEqual(v2.y, 8.0f);
			Assert::AreEqual(v2.z, 5.0f);
			Assert::AreEqual(v2.z, 5.0f);
		}

		TEST_METHOD(vec4AssignMultiplication)
		{
			vec4 v1 = vec4(0.0f, 2.0f, 4.0f, 7.0f);

			v1 *= 3.0;
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(6.0f, v1.y);
			Assert::AreEqual(12.0f, v1.z);
			Assert::AreEqual(21.0f, v1.w);
		}

		/*TEST_METHOD(vec4Quadrance)
		{
			vec4 v1 = vec4(2.0f, 4.0f, 8.0f);
			float result = v1.quadrance();

			Assert::AreEqual(result, 84.0f);
		}*/

		TEST_METHOD(vec4Norm)
		{
			//FIXME: Em principio o que está mal é o teste
			vec4 v1 = vec4(0.0f, 5.0f, 7.0f, 4.0f);

			float result = v1.norm();
			Assert::AreEqual(sqrt(90.0f), result);
		} 

		TEST_METHOD(vec4normalize)
		{
			//FIXME: Em principio o que está mal é o teste
			vec4 v1 = vec4(2.0f, 4.0f, 8.0f, 16.0f);

			vec4 result = v1.normalize();

			Assert::AreEqual(1.0f / sqrt(85.0f), result.x);
			Assert::AreEqual(2.0f / sqrt(85.0f), result.y);
			Assert::AreEqual(4.0f / sqrt(85.0f), result.z);
			Assert::AreEqual(8.0f / sqrt(85.0f), result.w); 
		}

		TEST_METHOD(vec4Dot1)
		{
			vec4 v1 = vec4(2.0f, 4.0f, 8.0f, 16.0f);
			vec4 v2 = vec4(32.0f, 64.0f, 128.0f, 256.0f);

			float result = v1.dot(v2);

			Assert::AreEqual(result, 5440.0f);
		}

		TEST_METHOD(vec4Dot2)
		{
			vec4 v1 = vec4(2.0f, 4.0f, 8.0f, 16.0f);
			vec4 v2 = vec4(32.0f, 64.0f, 128.0f, 256.0f);

			float result1 = v1.dot(v2);
			float result2 = v2.dot(v1);

			Assert::AreEqual(result1, result2);
		}

	};
}