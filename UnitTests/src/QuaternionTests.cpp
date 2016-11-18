#include "stdafx.h"
#include "CppUnitTest.h"
#include "qtrn.h"
#include "MatFactory.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Engine2;

namespace UnitTests
{
	TEST_CLASS(QuaternionTests)
	{
	public:

		TEST_METHOD(qtrnTest1)
		{
			vec4 axis = vec4(0.0f, 1.0f, 0.0f, 1.0f);
			qtrn q = qtrn(90.0f, axis);

			qtrn vi =  qtrn(0.0f, 7.0f, 0.0f, 0.0f);

			qtrn qe = qtrn(0.0f, 0.0f, 0.0f, -7.0f);

			qtrn qinv = q.inverse();
			//qinv.clean();

			qtrn qf = (q * vi) * qinv;

			Assert::IsTrue(qf == qe);
		}

		TEST_METHOD(qtrnTest2)
		{
			vec4 axis = vec4(0.0f, 1.0f, 0.0f, 1.0f);
			qtrn q = qtrn(90.0f, axis);

			vec4 vi = vec4(7.0f, 0.0f, 0.0f, 1.0f);
			std::cout << "vi = " << vi << std::endl;

			vec4 ve = vec4(0.0f, 0.0f, -7.0f, 1.0f);

			mat4 m = MatFactory::createMat4FromQuaternion(q);

			vec4 vf = m * vi;
			vf.clean();
			std::cout << "vf = " << vf << std::endl;
			
		}

		TEST_METHOD(qtrnTest3)
		{
			vec4 axis_x = vec4( 1.0f, 0.0f, 0.0f, 1.0f );
			vec4 axis_y = vec4(0.0f, 1.0f, 0.0f, 1.0f );
			vec4 axis_z = vec4( 0.0f, 0.0f, 1.0f, 1.0f );

			qtrn qyaw180 = qtrn(900.0f, axis_y);

			qtrn qroll180 = qtrn(180.0f, axis_x);

			qtrn qpitch180 = qtrn(180.0f, axis_z);

			qtrn qrp = qpitch180 * qroll180;

			qtrn qpr = qroll180 * qpitch180;

			qtrn qi = qtrn( 0.0f, 1.0f, 0.0f, 0.0f ); // x-axis

			qtrn qe = qtrn( 0.0f, -1.0f, 0.0f, 0.0f );

			qtrn qrpinv = qrp.inverse();
			qtrn qfrp = (qrp * qi) * qrpinv;

			qtrn qprinv = qpr.inverse();
			qtrn qfpr = (qpr * qi) * qprinv;

			Assert::IsTrue(qe == qfrp);
			Assert::IsTrue(qe == qfpr);

		}

		TEST_METHOD(qtrnTest4)
		{
			const float qThreshold = (float)1.0e-5;

			float thetai = 45.0f;
			vec4 axis_i = vec4( 0.0f, 1.0f, 0.0f, 1.0f );
			qtrn q = qtrn(thetai, axis_i);

			float thetaf;
			vec4 axis_f;
			q.toAngleAxis(thetaf, axis_f);

			Assert::IsTrue(fabs(thetai - thetaf) < qThreshold && axis_i == axis_f);
		}

		TEST_METHOD(qtrnTest5)
		{
			vec4 axis = vec4( 0.0f, 1.0f, 0.0f, 1.0f );
			qtrn q0 = qtrn(0.0f, axis);

			qtrn q1 = qtrn(90.0f, axis);

			qtrn qe = qtrn(30.0f, axis);

			qtrn qLerp0 = lerp(q0, q1, 0.0f);
			
			Assert::IsTrue(qLerp0 == q0);

			qtrn qLerp1 = lerp(q0, q1, 1.0f);
			Assert::IsTrue(qLerp1 ==  q1);

			qtrn qlerp = lerp(q0, q1, 1 / 3.0f);

			Assert::IsTrue(qlerp != qe);
		}

		TEST_METHOD(qtrnTest6)
		{
			vec4 axis = vec4(0.0f, 1.0f, 0.0f, 1.0f);
			qtrn q0 = qtrn(0.0f, axis);

			qtrn q1 = qtrn(90.0f, axis);

			qtrn qe = qtrn(30.0f, axis);

			qtrn qSlerp0 = slerp(q0, q1, 0.0f);
			Assert::IsTrue(qSlerp0 == q0);

			qtrn qSlerp1 = slerp(q0, q1, 1.0f);
			Assert::IsTrue(qSlerp1 == q1);

			qtrn qslerp = slerp(q0, q1, 1 / 3.0f);

			Assert::IsTrue(qslerp == qe);
		}
	};
}