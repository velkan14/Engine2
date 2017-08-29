#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"
#include "mat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(Mat3Tests)
	{
	public:

		TEST_METHOD(Mat3Constructor1)
		{
			mat3 m = mat3();
			Assert::AreEqual(0.0f, m.data[0]);
			Assert::AreEqual(0.0f, m.data[1]);
			Assert::AreEqual(0.0f, m.data[2]);
			Assert::AreEqual(0.0f, m.data[3]);
			Assert::AreEqual(0.0f, m.data[4]);
			Assert::AreEqual(0.0f, m.data[5]);
			Assert::AreEqual(0.0f, m.data[6]);
			Assert::AreEqual(0.0f, m.data[7]);
			Assert::AreEqual(0.0f, m.data[8]);
		}

		TEST_METHOD(Mat3Constructor2)
		{
			mat3 m = mat3(3.5f);
			Assert::AreEqual(m.data[0], 3.5f);
			Assert::AreEqual(m.data[1], 3.5f);
			Assert::AreEqual(m.data[2], 3.5f);
			Assert::AreEqual(m.data[3], 3.5f);
			Assert::AreEqual(m.data[4], 3.5f);
			Assert::AreEqual(m.data[5], 3.5f);
			Assert::AreEqual(m.data[6], 3.5f);
			Assert::AreEqual(m.data[7], 3.5f);
			Assert::AreEqual(m.data[8], 3.5f);
		}

		TEST_METHOD(Mat3Constructor3)
		{
			mat3 m = mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			Assert::AreEqual(m.data[0], 1.0f);
			Assert::AreEqual(m.data[1], 2.0f);
			Assert::AreEqual(m.data[2], 3.0f);
			Assert::AreEqual(m.data[3], 4.0f);
			Assert::AreEqual(m.data[4], 5.0f);
			Assert::AreEqual(m.data[5], 6.0f);
			Assert::AreEqual(m.data[6], 7.0f);
			Assert::AreEqual(m.data[7], 8.0f);
			Assert::AreEqual(m.data[8], 9.0f);
		}

		TEST_METHOD(Mat3Constructor4)
		{
			mat3 m1 = mat3(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
			mat3 m2 = mat3(m1);
			Assert::AreEqual(m2.data[0], 1.0f);
			Assert::AreEqual(m2.data[1], 2.0f);
			Assert::AreEqual(m2.data[2], 3.0f);
			Assert::AreEqual(m2.data[3], 4.0f);
			Assert::AreEqual(m2.data[4], 5.0f);
			Assert::AreEqual(m2.data[5], 6.0f);
			Assert::AreEqual(m2.data[6], 7.0f);
			Assert::AreEqual(m2.data[7], 8.0f);
			Assert::AreEqual(m2.data[8], 9.0f);
		}

		TEST_METHOD(Mat3Equal1)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			mat3 m2 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			Assert::IsTrue(m1 == m2);
			Assert::IsTrue(m2 == m1);
		}

		TEST_METHOD(Mat3Equal2)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			mat3 m2 = mat3(
				1, 2, 3,
				0, 3, 4,
				5, 6, 0);
			Assert::IsFalse(m1 == m2);
			Assert::IsFalse(m2 == m1);
		}

		TEST_METHOD(Mat3Different1)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 2, 4,
				5, 6, 0);
			mat3 m2 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			Assert::IsTrue(m1 != m2);
			Assert::IsTrue(m2 != m1);
		}

		TEST_METHOD(Mat3Different2)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			mat3 m2 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			Assert::IsFalse(m1 != m2);
			Assert::IsFalse(m2 != m1);
		}

		TEST_METHOD(Mat3Assign)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
			mat3 m2 = mat3();

			mat3 e = mat3();

			m1 = m2;

			Assert::IsTrue(e == m1);
		}

		TEST_METHOD(Mat3Determinante)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);
	
			float r = m1.determinante();

			Assert::AreEqual(1.0f, r);
		}

		TEST_METHOD(Mat3Transpose)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				0, 1, 4,
				5, 6, 0);

			mat3 r = transpose(m1);
			mat3 e = mat3(1, 0, 5, 2, 1, 6, 3, 4, 0);
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3Inverse)
		{
			mat3 m = mat3(
				1, 2, 3, 
				0, 1, 4, 
				5, 6, 0);

			mat3 e = mat3(-24.0f, 18.0f, 5.0f, 20.0f, -15.0f, -4.0f, -5.0f, 4.0f, 1.0f);
			mat3 i = inverse(m);
			Assert::IsTrue(e == i);
		}

		TEST_METHOD(Mat3Addition)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			mat3 m2 = mat3(
				2, 4, 6,
				6, 4, 2,
				4, 2, 6);

			mat3 e = mat3(
				3, 6, 9,
				9, 6, 3,
				6, 3, 9);

			mat3 r = m2 + m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3Subtraction)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			mat3 m2 = mat3(
				2, 4, 6,
				6, 4, 2,
				4, 2, 6);

			mat3 e = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			mat3 r = m2 - m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3MultiplicationMatVec)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			vec3 v = vec3(2, 3, 5);

			vec3 e = vec3(23, 17, 22);

			vec3 r = m1 * v;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3MultiplicationMatK)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			mat3 e = mat3(
				5, 10, 15,
				15, 10, 5,
				10, 5, 15);

			mat3 r = m1 * 5.0f;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3MultiplicationKMat)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);

			mat3 e = mat3(
				5, 10, 15,
				15, 10, 5,
				10, 5, 15);

			mat3 r = 5.0f * m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(Mat3MultiplicationMatMat)
		{
			mat3 m1 = mat3(
				1, 2, 3,
				3, 2, 1,
				2, 1, 3);
			mat3 m2 = mat3(
				4, 5, 6,
				6, 5, 4,
				4, 6, 5);

			mat3 i = m1 * m2;
			Assert::AreEqual(28.0f, i.data[0]);
			Assert::AreEqual(33.0f, i.data[1]);
			Assert::AreEqual(29.0f, i.data[2]);
			Assert::AreEqual(28.0f, i.data[3]);
			Assert::AreEqual(31.0f, i.data[4]);
			Assert::AreEqual(31.0f, i.data[5]);
			Assert::AreEqual(26.0f, i.data[6]);
			Assert::AreEqual(33.0f, i.data[7]);
			Assert::AreEqual(31.0f, i.data[8]);
		}
	};
	
}