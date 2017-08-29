#include "MatFactory.h"

#include <vector>

#include "vec.h"
#include "mat.h"
#include "qtrn.h"


namespace Engine2 {
	
		const mat3 MatFactory::ZeroMat3() {
			return mat3();
		}
		const mat3 MatFactory::IdentityMat3() {
			return mat3(
				1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 1.0f);
		}
		const mat3 MatFactory::DualMat3(const vec3 & v) {
			return mat3(
				0.0f, -v.z, v.y,
				v.z, 0.0f, -v.x,
				-v.y, v.x, 0.0f);
		}

		const mat4 MatFactory::ZeroMat4() {
			return mat4();
		}
		const mat4 MatFactory::IdentityMat4()
		{
			return mat4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		const mat4 MatFactory::Mat4FromMat3(const mat3 & m)
		{
			return mat4(
				m.data[0], m.data[1], m.data[2], 0.0f,
				m.data[3], m.data[4], m.data[5], 0.0f,
				m.data[6], m.data[7], m.data[8], 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		const mat3 MatFactory::Mat3FromMat4(const mat4 & m)
		{
			return mat3(
				m.data[0], m.data[1], m.data[2],
				m.data[4], m.data[5], m.data[6],
				m.data[8], m.data[9], m.data[10]);
		}


		GLfloat * MatFactory::GLMatrixFromMat4(const mat4 & m)
		{
			/*std::vector<float> matrix(16);

			for (int i = 0; i < 16; i++) 
			{
				matrix[i] = m.data[i];
			}
			return &matrix[0];*/

			GLfloat * matrix = new GLfloat[16];

			for (int i = 0; i < 16; i++)
			{
				matrix[i] = m.data[i];
			}
			return matrix;
			//FIXME: Memory leak.
		}

		GLfloat * MatFactory::GLMatrixFromMat3(const mat3 & m)
		{

			GLfloat * matrix = new GLfloat[9];

			for (int i = 0; i < 9; i++)
			{
				matrix[i] = m.data[i];
			}
			return matrix;
			//FIXME: Memory leak.
		}

		const mat4 MatFactory::ScaleMat4(const float x, const float y, const float z)
		{
			return mat4(
				x, 0.0f, 0.0f, 0.0f,
				0.0f, y, 0.0f, 0.0f,
				0.0f, 0.0f, z, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		const mat4 MatFactory::ScaleMat4(const vec3 & v)
		{
			return ScaleMat4(v.x, v.y, v.z);
		}

		const mat4 MatFactory::RotationMat4(const vec3 & axis, const float angle)
		{
			//Provavelmente o axis tem que ser unitario...
			vec3 a = axis.normalize();
			mat3 dualMatrix = MatFactory::DualMat3(a);

			mat3 m3 =  IdentityMat3() + sin(angle) * dualMatrix + (1 - cos(angle)) * dualMatrix * dualMatrix;

			return Mat4FromMat3(m3);
		}

		const mat4 MatFactory::TranslationMat4(const vec3 & v)
		{
			return TranslationMat4(v.x, v.y, v.z);
		}
	
		const mat4 MatFactory::TranslationMat4(const float x, const float y, const float z)
		{
			return mat4(
				1.0f, 0.0f, 0.0f, x,
				0.0f, 1.0f, 0.0f, y,
				0.0f, 0.0f, 1.0f, z,
				0.0f, 0.0f, 0.0f, 1.0f);
		}

		const mat4 MatFactory::ViewMatrix(const vec3 eye, const vec3 center, const vec3 up)
		{
			vec3 view = center - eye;
			vec3 v = view	* (1.0f / view.norm());

			vec3 side = v.cross(up);
			vec3 s = side * (1.0f / side.norm());

			vec3 u = s.cross(v);

			return transpose(mat4(
				s.x, s.y, s.z, -s.dot(eye),
				u.x, u.y, u.z, -u.dot(eye),
				-v.x, -v.y, -v.z, v.dot(eye),
				0.0f, 0.0f, 0.0f, 1.0f));
		}

		const mat4 MatFactory::OrthographicProjectionMatrix(const float left, const float right, const float bottom, const float top, const float nnear, const float ffar)
		{
			return transpose(mat4(
				2.0f / (right - left), 0.0f, 0.0f, (left + right) / (left - right),
				0.0f, 2.0f / (top - bottom), 0.0f, (bottom + top) / (bottom - top),
				0.0f, 0.0f, -2.0f / (ffar - nnear), (nnear + ffar) / (nnear - ffar),
				0.0f, 0.0f, 0.0f, 1.0f));
		}

		const mat4 MatFactory::PerspectiveProjectionMatrix(const float fovy, const float aspect, const float nearZ, const float farZ)
		{
			float teta = fovy / 2;
			float d = 1.0f / tan(teta);

			return transpose(mat4(
				d / aspect, 0.0f, 0.0f, 0.0f,
				0.0f, d, 0.0f, 0.0f,
				0.0f, 0.0f, (farZ + nearZ) / (nearZ - farZ), (2 * farZ * nearZ) / (nearZ - farZ),
				0.0f, 0.0f, -1.0f, 0.0f));
		}

		const mat4 MatFactory::Mat4FromQuaternion(const qtrn & q)
		{
			qtrn qn = q.normalize();

			float xx = qn.x * qn.x;
			float xy = qn.x * qn.y;
			float xz = qn.x * qn.z;
			float xt = qn.x * qn.t;
			float yy = qn.y * qn.y;
			float yz = qn.y * qn.z;
			float yt = qn.y * qn.t;
			float zz = qn.z * qn.z;
			float zt = qn.z * qn.t;

			mat4 m = mat4(
				1.0f - 2.0f * (yy + zz), 2.0f * (xy + zt), 2.0f * (xz - yt), 0.0f,
				2.0f * (xy - zt), 1.0f - 2.0f * (xx + zz), 2.0f * (yz + xt), 0.0f,
				2.0f * (xz + yt), 2.0f * (yz - xt), 1.0f - 2.0f * (xx + yy), 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f);

			return m;
		}

		const qtrn MatFactory::QuaternionFromMat4(const mat4 & m)
		{
			qtrn q = qtrn();
			q.t = sqrt(1.0f + m.data[0] + m.data[5] + m.data[10]) / 2.0f;
			float w4 = (4.0f * q.t);
			q.x = (m.data[9] - m.data[6]) / w4;
			q.y = (m.data[2] - m.data[8]) / w4;
			q.z = (m.data[4] - m.data[1]) / w4;
			return q;
		}
}