#include "stdafx.h"
#include "CppUnitTest.h"
#include "vec.h"
#include "mat.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(Mat4Tests)
	{
	public:

		TEST_METHOD(mat4Constructor1)
		{
			mat4 m = mat4();
			Assert::AreEqual(0.0f, m.data[0]);
			Assert::AreEqual(0.0f, m.data[1]);
			Assert::AreEqual(0.0f, m.data[2]);
			Assert::AreEqual(0.0f, m.data[3]);
			Assert::AreEqual(0.0f, m.data[4]);
			Assert::AreEqual(0.0f, m.data[5]);
			Assert::AreEqual(0.0f, m.data[6]);
			Assert::AreEqual(0.0f, m.data[7]);
			Assert::AreEqual(0.0f, m.data[8]);
			Assert::AreEqual(0.0f, m.data[9]);
			Assert::AreEqual(0.0f, m.data[10]);
			Assert::AreEqual(0.0f, m.data[11]);
			Assert::AreEqual(0.0f, m.data[12]);
			Assert::AreEqual(0.0f, m.data[13]);
			Assert::AreEqual(0.0f, m.data[14]);
			Assert::AreEqual(0.0f, m.data[15]);
		}

		TEST_METHOD(mat4Constructor2)
		{
			mat4 m = mat4(3.5f);
			Assert::AreEqual(m.data[0], 3.5f);
			Assert::AreEqual(m.data[1], 3.5f);
			Assert::AreEqual(m.data[2], 3.5f);
			Assert::AreEqual(m.data[3], 3.5f);
			Assert::AreEqual(m.data[4], 3.5f);
			Assert::AreEqual(m.data[5], 3.5f);
			Assert::AreEqual(m.data[6], 3.5f);
			Assert::AreEqual(m.data[7], 3.5f);
			Assert::AreEqual(m.data[8], 3.5f);
			Assert::AreEqual(m.data[9], 3.5f);
			Assert::AreEqual(m.data[10], 3.5f);
			Assert::AreEqual(m.data[11], 3.5f);
			Assert::AreEqual(m.data[12], 3.5f);
			Assert::AreEqual(m.data[13], 3.5f);
			Assert::AreEqual(m.data[14], 3.5f);
			Assert::AreEqual(m.data[15], 3.5f);
		}

		TEST_METHOD(mat4Constructor3)
		{
			mat4 m = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			Assert::AreEqual(1.0f, m.data[0]);
			Assert::AreEqual(2.0f, m.data[1]);
			Assert::AreEqual(3.0f, m.data[2]);
			Assert::AreEqual(4.0f, m.data[3]);
			Assert::AreEqual(5.0f, m.data[4]);
			Assert::AreEqual(6.0f, m.data[5]);
			Assert::AreEqual(7.0f, m.data[6]);
			Assert::AreEqual(8.0f, m.data[7]);
			Assert::AreEqual(1.0f, m.data[8]);
			Assert::AreEqual(2.0f, m.data[9]);
			Assert::AreEqual(3.0f, m.data[10]);
			Assert::AreEqual(4.0f, m.data[11]);
			Assert::AreEqual(5.0f, m.data[12]);
			Assert::AreEqual(6.0f, m.data[13]);
			Assert::AreEqual(7.0f, m.data[14]);
			Assert::AreEqual(8.0f, m.data[15]);
		}

		TEST_METHOD(mat4Constructor4)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(m1);
			Assert::AreEqual(m2.data[0], 1.0f);
			Assert::AreEqual(m2.data[1], 2.0f);
			Assert::AreEqual(m2.data[2], 3.0f);
			Assert::AreEqual(m2.data[3], 4.0f);
			Assert::AreEqual(m2.data[4], 5.0f);
			Assert::AreEqual(m2.data[5], 6.0f);
			Assert::AreEqual(m2.data[6], 7.0f);
			Assert::AreEqual(m2.data[7], 8.0f);
			Assert::AreEqual(m2.data[8], 1.0f);
			Assert::AreEqual(m2.data[9], 2.0f);
			Assert::AreEqual(m2.data[10], 3.0f);
			Assert::AreEqual(m2.data[11], 4.0f);
			Assert::AreEqual(m2.data[12], 5.0f);
			Assert::AreEqual(m2.data[13], 6.0f);
			Assert::AreEqual(m2.data[14], 7.0f);
			Assert::AreEqual(m2.data[15], 8.0f);
		}

		TEST_METHOD(mat4Equal1)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			Assert::IsTrue(m1 == m2);
			Assert::IsTrue(m2 == m1);
		}

		TEST_METHOD(mat4Equal2)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 3.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			Assert::IsFalse(m1 == m2);
			Assert::IsFalse(m2 == m1);
		}

		TEST_METHOD(mat4Different1)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f); 
			mat4 m2 = mat4(
					11.0f, 2.0f, 3.0f, 4.0f,
					5.0f, 6.0f, 7.0f, 8.0f,
					1.0f, 2.0f, 3.0f, 4.0f,
					5.0f, 6.0f, 7.0f, 8.0f);
			Assert::IsTrue(m1 != m2);
			Assert::IsTrue(m2 != m1);
		}

		TEST_METHOD(mat4Different2)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			Assert::IsFalse(m1 != m2);
			Assert::IsFalse(m2 != m1);
		}

		TEST_METHOD(mat4Assign)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4();

			mat4 e = mat4();

			m1 = m2;

			Assert::IsTrue(e == m1);
		}

		TEST_METHOD(mat4Determinante1)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			float r = m1.determinante();

			Assert::AreEqual(0.0f, r);
		}

		TEST_METHOD(mat4Determinante2)
		{
			mat4 m1 = mat4(
				2.0f, 0.0f, 0.0f, 0.0f,
				4.0f, 3.0f, 0.0f, 0.0f,
				4.0f, 3.0f, 4.0f, 0.0f,
				0.0f, 0.0f, 4.0f, 3.0f);

			float r = m1.determinante();

			Assert::AreEqual(72.0f, r);
		}

		TEST_METHOD(mat4Transpose)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 r = transpose(m1);
			mat4 e = mat4(
				1.0f, 5.0f, 1.0f, 5.0f,
				2.0f, 6.0f, 2.0f, 6.0f,
				3.0f, 7.0f, 3.0f, 7.0f,
				4.0f, 8.0f, 4.0f, 8.0f);
			Assert::IsTrue(e == r);
		}

		/*TEST_METHOD(mat4Inverse)
		{
			mat4 m = mat4(
				2.0f, 0.0f, 0.0f, 0.0f,
				4.0f, 3.0f, 0.0f, 0.0f,
				4.0f, 3.0f, 4.0f, 0.0f,
				0.0f, 0.0f, 4.0f, 3.0f);

			mat4 e = (1 / 54) * mat4(
				27.0f, 0.0f, 0.0f, 0.0f, 
				-36.0f, 18.0f, 0.0f, 0.0f, 
				12.0f, -24.0f, 18.0f, 0.0f,
				-16.0f, 32.0f, -24.0f, 18.0f);
			mat4 i = inverse(m);
			Assert::IsTrue(e == i);
		}*/

		TEST_METHOD(mat4Addition)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 e = mat4(
				2.0f, 4.0f, 6.0f, 8.0f,
				10.0f, 12.0f, 14.0f, 16.0f,
				2.0f, 4.0f, 6.0f, 8.0f,
				10.0f, 12.0f, 14.0f, 16.0f);

			mat4 r = m2 + m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat4Subtraction)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);
			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 e = mat4();

			mat4 r = m2 - m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat4MultiplicationMatVec)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			vec4 v = vec4(2.0f, 3.0f, 5.0f, 7.0f);

			vec4 e = vec4(51.0f, 119.0f, 51.0f, 119.0f);

			vec4 r = m1 * v;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat4MultiplicationMatK)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 e = mat4(
				5.0f, 10.0f, 15.0f, 20.0f,
				25.0f, 30.0f, 35.0f, 40.0f,
				5.0f, 10.0f, 15.0f, 20.0f,
				25.0f, 30.0f, 35.0f, 40.0f);

			mat4 r = m1 * 5.0f;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat4MultiplicationKMat)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 e = mat4(
				5.0f, 10.0f, 15.0f, 20.0f,
				25.0f, 30.0f, 35.0f, 40.0f,
				5.0f, 10.0f, 15.0f, 20.0f,
				25.0f, 30.0f, 35.0f, 40.0f);

			mat4 r = 5.0f * m1;
			Assert::IsTrue(e == r);
		}

		TEST_METHOD(mat4MultiplicationMatMat)
		{
			mat4 m1 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 i = m1 * m2;
			Assert::AreEqual(34.0f, i.data[0]);
			Assert::AreEqual(44.0f, i.data[1]);
			Assert::AreEqual(54.0f, i.data[2]);
			Assert::AreEqual(64.0f, i.data[3]);
			Assert::AreEqual(82.0f, i.data[4]);
			Assert::AreEqual(108.0f, i.data[5]);
			Assert::AreEqual(134.0f, i.data[6]);
			Assert::AreEqual(160.0f, i.data[7]);
			Assert::AreEqual(34.0f, i.data[8]);
			Assert::AreEqual(44.0f, i.data[9]);
			Assert::AreEqual(54.0f, i.data[10]);
			Assert::AreEqual(64.0f, i.data[11]);
			Assert::AreEqual(82.0f, i.data[12]);
			Assert::AreEqual(108.0f, i.data[13]);
			Assert::AreEqual(134.0f, i.data[14]);
			Assert::AreEqual(160.0f, i.data[15]);
		}

		TEST_METHOD(mat4MultiplicationMatMat2)
		{
			//FIXME
			mat4 m1 = mat4(
				1.0f, 0.0f, 0.0f, 0.0f,
				5.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat4 m2 = mat4(
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f,
				1.0f, 2.0f, 3.0f, 4.0f,
				5.0f, 6.0f, 7.0f, 8.0f);

			mat4 i = m1 * m2;
			Assert::AreEqual(34.0f, i.data[0]);
			Assert::AreEqual(44.0f, i.data[1]);
			Assert::AreEqual(54.0f, i.data[2]);
			Assert::AreEqual(64.0f, i.data[3]);
			Assert::AreEqual(82.0f, i.data[4]);
			Assert::AreEqual(108.0f, i.data[5]);
			Assert::AreEqual(134.0f, i.data[6]);
			Assert::AreEqual(160.0f, i.data[7]);
			Assert::AreEqual(34.0f, i.data[8]);
			Assert::AreEqual(44.0f, i.data[9]);
			Assert::AreEqual(54.0f, i.data[10]);
			Assert::AreEqual(64.0f, i.data[11]);
			Assert::AreEqual(82.0f, i.data[12]);
			Assert::AreEqual(108.0f, i.data[13]);
			Assert::AreEqual(134.0f, i.data[14]);
			Assert::AreEqual(160.0f, i.data[15]);
		}
	};

}