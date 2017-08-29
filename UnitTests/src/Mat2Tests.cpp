#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"
#include "mat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(Mat2Tests)
	{
	public:

		TEST_METHOD(mat2Constructor1)
		{
			mat2 m = mat2();
			Assert::AreEqual(0.0f, m.data[0]);
			Assert::AreEqual(0.0f, m.data[1]);
			Assert::AreEqual(0.0f, m.data[2]);
			Assert::AreEqual(0.0f, m.data[3]);
		}

		TEST_METHOD(mat2Constructor2)
		{
			mat2 m = mat2(3.5f);
			Assert::AreEqual(m.data[0], 3.5f);
			Assert::AreEqual(m.data[1], 3.5f);
			Assert::AreEqual(m.data[2], 3.5f);
			Assert::AreEqual(m.data[3], 3.5f);
		}

		TEST_METHOD(mat2Constructor3)
		{
			mat2 m = mat2(1.0f, 2.0f, 3.0f, 4.0f);
			Assert::AreEqual(m.data[0], 1.0f);
			Assert::AreEqual(m.data[1], 2.0f);
			Assert::AreEqual(m.data[2], 3.0f);
			Assert::AreEqual(m.data[3], 4.0f);
		}

		TEST_METHOD(mat2Constructor4)
		{
			mat2 m1 = mat2(1.0f, 2.0f, 3.0f, 4.0f);
			mat2 m2 = mat2(m1);
			Assert::AreEqual(m2.data[0], 1.0f);
			Assert::AreEqual(m2.data[1], 2.0f);
			Assert::AreEqual(m2.data[2], 3.0f);
			Assert::AreEqual(m2.data[3], 4.0f);
		}

		TEST_METHOD(mat2Equal1)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1
				);
			mat2 m2 = mat2(
				1, 2,
				0, 1
				);
			Assert::IsTrue(m1 == m2);
			Assert::IsTrue(m2 == m1);
		}

		TEST_METHOD(mat2Equal2)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1
				);
			mat2 m2 = mat2(
				1, 2,
				0, 3
				);
			Assert::IsFalse(m1 == m2);
			Assert::IsFalse(m2 == m1);
		}

		TEST_METHOD(mat2Different1)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 2);
			mat2 m2 = mat2(
				1, 2,
				0, 1);
			Assert::IsTrue(m1 != m2);
			Assert::IsTrue(m2 != m1);
		}

		TEST_METHOD(mat2Different2)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1);
			mat2 m2 = mat2(
				1, 2,
				0, 1);
			Assert::IsFalse(m1 != m2);
			Assert::IsFalse(m2 != m1);
		}

		TEST_METHOD(mat2Assign)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1);
			mat2 m2 = mat2();

			mat2 e = mat2();

			m1 = m2;

			Assert::IsTrue(e == m1);
		}

		TEST_METHOD(mat2Determinante)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1);

			float r = m1.determinante();

			Assert::AreEqual(1.0f, r);
		}

		TEST_METHOD(mat2Transpose)
		{
			mat2 m1 = mat2(
				1, 2,
				0, 1);

			mat2 r = transpose(m1);
			mat2 e = mat2(1, 0, 2, 1);
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2Inverse)
		{
			mat2 m = mat2(
				1, 3,
				3, 2);

			mat2 e = (1.0f/7.0f) * mat2(-2.0f, 3.0f, 3.0f, -1.0f);
			e.clean();
			mat2 i = inverse(m);
			Assert::IsTrue(e == i);
		}

		TEST_METHOD(mat2Addition)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);

			mat2 m2 = mat2(
				2, 4,
				6, 4);

			mat2 e = mat2(
				3, 6,
				9, 6);

			mat2 r = m2 + m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2Subtraction)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);

			mat2 m2 = mat2(
				2, 4,
				6, 4);

			mat2 e = mat2(
				1, 2,
				3, 2);

			mat2 r = m2 - m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2MultiplicationMatVec)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);

			vec2 v = vec2(2, 3);

			vec2 e = vec2(8, 12);

			vec2 r = m1 * v;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2MultiplicationMatK)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);

			mat2 e = mat2(
				5, 10,
				15, 10);

			mat2 r = m1 * 5.0f;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2MultiplicationKMat)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);

			mat2 e = mat2(
				5, 10,
				15, 10);

			mat2 r = 5.0f * m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat2MultiplicationMatMat)
		{
			mat2 m1 = mat2(
				1, 2,
				3, 2);
			mat2 m2 = mat2(
				4, 5,
				6, 5);

			mat2 i = m1 * m2;
			Assert::AreEqual(16.0f, i.data[0]);
			Assert::AreEqual(15.0f, i.data[1]);
			Assert::AreEqual(24.0f, i.data[2]);
			Assert::AreEqual(25.0f, i.data[3]);
		}
	};

}