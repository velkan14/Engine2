#include "stdafx.h"
#include "CppUnitTest.h"
#include "MatFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	/*static const mat4 createScaleMat4(const vec3 & v);
	static const mat4 createRotationMat4(const vec3 & axis, const float angle);
	static const mat4 createTranslationMat4(const vec3 & v);*/

	TEST_CLASS(MatFactoryTests)
	{
	public:

		TEST_METHOD(MatFactoryCreateZeroMat3)
		{
			mat3 m = MatFactory::createZeroMat3();

			mat3 e = mat3(
				0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateIdentityMat3)
		{
			mat3 m = MatFactory::createIdentityMat3();

			mat3 e = mat3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 1.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateDualMat3)
		{
			vec3 v = vec3(1.0f, 2.0f, 3.0f);
			mat3 m = MatFactory::createDualMat3(v);

			mat3 e = mat3(
				0.0f, -3.0f, 2.0f,
				3.0f, 0.0f, -1.0f,
				-2.0f, 1.0f, 0.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateZeroMat4)
		{
			mat4 m = MatFactory::createZeroMat4();

			mat4 e = mat4(
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateIdentityMat4)
		{
			mat4 m = MatFactory::createIdentityMat4();

			mat4 e = mat4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateMat4FromMat3)
		{
			mat3 m3 = mat3(
				0.0f, -3.0f, 2.0f,
				3.0f, 0.0f, -1.0f,
				-2.0f, 1.0f, 0.0f);

			mat4 m = MatFactory::createMat4FromMat3(m3);

			mat4 e = mat4(
				0.0f, -3.0f, 2.0f, 0.0f,
				3.0f, 0.0f, -1.0f, 0.0f,
				-2.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactoryCreateMat3FromMat4)
		{
			mat4 m4 = mat4(
				0.0f, -3.0f, 2.0f, 0.0f,
				3.0f, 0.0f, -1.0f, 0.0f,
				-2.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat3 e = mat3(
				0.0f, -3.0f, 2.0f,
				3.0f, 0.0f, -1.0f,
				-2.0f, 1.0f, 0.0f);

			mat3 m = MatFactory::createMat3FromMat4(m4);

			
			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactorycreateScaleMat4)
		{
			mat4 e = mat4(
				10.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 9.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 8.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat4 m = MatFactory::createScaleMat4(vec3(10.0f, 9.0f, 8.0f));

			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactorycreateTranslationMat4)
		{
			mat4 e = mat4(
				1.0f, 0.0f, 0.0f, 10.0f,
				0.0f, 1.0f, 0.0f, 9.0f,
				0.0f, 0.0f, 1.0f, 8.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat4 m = MatFactory::createTranslationMat4(vec3(10.0f, 9.0f, 8.0f));

			Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactorycreateViewMatrix)
		{
			//It doesnt work because of rounding of the expected result
			mat4 e = mat4(
				-0.7f, 0.0f, 0.7f, 0.0f,
				-0.41f, 0.82f, -0.41f, 0.0f,
				-0.58f, -0.58f, -0.58f, -8.7f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat4 m = MatFactory::createViewMatrix(vec3(-5.0f, -5.0f, -5.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

			
			/*Assert::AreEqual(e.data[0], m.data[0]);
			Assert::AreEqual(e.data[1], m.data[1]);
			Assert::AreEqual(e.data[2], m.data[2]);
			Assert::AreEqual(e.data[3], m.data[3]);
			Assert::AreEqual(e.data[4], m.data[4]);
			Assert::AreEqual(e.data[5], m.data[5]);
			Assert::AreEqual(e.data[6], m.data[6]);
			Assert::AreEqual(e.data[7], m.data[7]);
			Assert::AreEqual(e.data[8], m.data[8]);
			Assert::AreEqual(e.data[9], m.data[9]);
			Assert::AreEqual(e.data[10], m.data[10]);
			Assert::AreEqual(e.data[11], m.data[11]);
			Assert::AreEqual(e.data[12], m.data[12]);
			Assert::AreEqual(e.data[13], m.data[13]);
			Assert::AreEqual(e.data[14], m.data[14]);
			Assert::AreEqual(e.data[15], m.data[15]);*/
			Assert::IsTrue(e == m); 
		}

		TEST_METHOD(MatFactorycreateOrthographicMatrix)
		{
			//It doesnt work because of rounding of the expected result
			mat4 e = mat4(
				0.5f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.5f, 0.0f, 0.0f,
				0.0f, 0.0f, -0.22f, -1.22f,
				0.0f, 0.0f, 0.0f, 1.0f);

			mat4 m = MatFactory::createOrthographicProjectionMatrix(-2.0f, 2.0f, -2.0f, 2.0f, 1.0f, 10.0f);

			Assert::AreEqual(e.data[0], m.data[0]);
			Assert::AreEqual(e.data[1], m.data[1]);
			Assert::AreEqual(e.data[2], m.data[2]);
			Assert::AreEqual(e.data[3], m.data[3]);
			Assert::AreEqual(e.data[4], m.data[4]);
			Assert::AreEqual(e.data[5], m.data[5]);
			Assert::AreEqual(e.data[6], m.data[6]);
			Assert::AreEqual(e.data[7], m.data[7]);
			Assert::AreEqual(e.data[8], m.data[8]);
			Assert::AreEqual(e.data[9], m.data[9]);
			Assert::AreEqual(e.data[10], m.data[10]);
			Assert::AreEqual(e.data[11], m.data[11]);
			Assert::AreEqual(e.data[12], m.data[12]);
			Assert::AreEqual(e.data[13], m.data[13]);
			Assert::AreEqual(e.data[14], m.data[14]);
			Assert::AreEqual(e.data[15], m.data[15]);
			//Assert::IsTrue(e == m);
		}

		TEST_METHOD(MatFactorycreatePerspectiveMatrix)
		{
			//It doesnt work because of rounding of the expected result
			mat4 e = mat4(
				2.79f, 0.0f, 0.0f, 0.0f,
				0.0f, 3.73f, 0.0f, 0.0f,
				0.0f, 0.0f, -1.22f, -2.22f,
				0.0f, 0.0f, -1.0f, 0.0f);

			mat4 m = MatFactory::createPerspectiveProjectionMatrix(0.524f /*30 degrees*/, 640.0f / 480.0f, 1.0f, 10.0f);

			Assert::AreEqual(e.data[0], m.data[0]);
			Assert::AreEqual(e.data[1], m.data[1]);
			Assert::AreEqual(e.data[2], m.data[2]);
			Assert::AreEqual(e.data[3], m.data[3]);
			Assert::AreEqual(e.data[4], m.data[4]);
			Assert::AreEqual(e.data[5], m.data[5]);
			Assert::AreEqual(e.data[6], m.data[6]);
			Assert::AreEqual(e.data[7], m.data[7]);
			Assert::AreEqual(e.data[8], m.data[8]);
			Assert::AreEqual(e.data[9], m.data[9]);
			Assert::AreEqual(e.data[10], m.data[10]);
			Assert::AreEqual(e.data[11], m.data[11]);
			Assert::AreEqual(e.data[12], m.data[12]);
			Assert::AreEqual(e.data[13], m.data[13]);
			Assert::AreEqual(e.data[14], m.data[14]);
			Assert::AreEqual(e.data[15], m.data[15]);
			//Assert::IsTrue(e == m);
		}
	};
}