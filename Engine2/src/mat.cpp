#include "mat.h"

namespace Engine2 {
	/*-----------  MAT2 ------------*/

	mat2::mat2()
	{
		data[0] = 0.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
		data[3] = 0.0f;
	}

	mat2::~mat2()
	{
	}

	mat2::mat2(const float k)
	{
		data[0] = k;
		data[1] = k;
		data[2] = k;
		data[3] = k;
	}

	mat2::mat2(const float m11, const float m12, const float m21, const float m22)
	{
		data[0] = m11;
		data[1] = m12;
		data[2] = m21;
		data[3] = m22;
	}

	mat2::mat2(const mat2 & m)
	{
		data[0] = m.data[0];
		data[1] = m.data[1];
		data[2] = m.data[2];
		data[3] = m.data[3];
	}

	void mat2::clean()
	{
		if (data[0] > -1e-5 && data[0] < 1e-5) data[0] = 0;
		if (data[1] > -1e-5 && data[1] < 1e-5) data[1] = 0;
		if (data[2] > -1e-5 && data[2] < 1e-5) data[2] = 0;
		if (data[3] > -1e-5 && data[3] < 1e-5) data[3] = 0;
	}

	mat2 & mat2::operator=(const mat2 & m1)
	{
		data[0] = m1.data[0];
		data[1] = m1.data[1];
		data[2] = m1.data[2];
		data[3] = m1.data[3];
		return *this;
	}

	float mat2::determinante() const
	{
		return data[0] * data[3] - data[1] * data[2];
	}
	mat2 transpose(const mat2 & m)
	{
		mat2  m2 = mat2(
			m.data[0], m.data[2], 
			m.data[1], m.data[3]);
		return m2;
	}
	mat2 inverse(const mat2 & m)
	{
		mat2 r = mat2(m.data[3], -m.data[1], -m.data[2], m.data[0]);
		r = (1 / m.determinante()) * r;
		return r;
	}

	const mat2 operator+(const mat2 & m1, const mat2 & m2)
	{
		mat2  result = mat2(m1.data[0] + m2.data[0], m1.data[1] + m2.data[1], m1.data[2] + m2.data[2], m1.data[3] + m2.data[3]);
		return result;
	}
	const mat2 operator-(const mat2 & m1, const mat2 & m2)
	{
		mat2  result =  mat2(m1.data[0] - m2.data[0], m1.data[1] - m2.data[1], m1.data[2] - m2.data[2], m1.data[3] - m2.data[3]);
		return result;
	}

	const vec2 operator*(const mat2 & m, const vec2 & v)
	{
		vec2  result = vec2(m.data[0] * v.x + m.data[1] * v.y,
			m.data[2] * v.x + m.data[3] * v.y);
		return result;
	}

	const mat2 operator*(const mat2 & m, const float k)
	{
		return k * m;
	}

	const mat2 operator*(const float k, const mat2 & m)
	{
		mat2  result = mat2(m.data[0] * k, m.data[1] * k, m.data[2] * k, m.data[3] * k);
		return result;
	}

	const mat2 operator*(const mat2 & m1, const mat2 & m2)
	{
		mat2  result = mat2(
			m1.data[0] * m2.data[0] + m1.data[1] * m2.data[2],
			m1.data[0] * m2.data[1] + m1.data[1] * m2.data[3],
			m1.data[2] * m2.data[0] + m1.data[3] * m2.data[2],
			m1.data[2] * m2.data[1] + m1.data[3] * m2.data[3]);
		return result;
	}

	const bool operator==(const mat2 & m1, const mat2 & m2)
	{
		return equalFloats(m1.data[0], m2.data[0]) &&
			equalFloats(m1.data[1], m2.data[1]) &&
			equalFloats(m1.data[2], m2.data[2]) &&
			equalFloats(m1.data[3], m2.data[3]);

	}
	const bool operator!=(const mat2 & m1, const mat2 & m2)
	{
		return !(m1 == m2);
	}
	std::ostream & operator<< (std::ostream & os, const mat2 & m)
	{
		os << "[ " << m.data[0] << ' ' << m.data[1]  << " ]" << std::endl;
		os << "[ " << m.data[2] << ' ' << m.data[3]  << " ]" << std::endl;
		return os;
	}

	/*-----------  MAT3 ------------*/
	mat3::mat3()
	{
		data[0] = 0.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
		data[3] = 0.0f;
		data[4] = 0.0f;
		data[5] = 0.0f;
		data[6] = 0.0f;
		data[7] = 0.0f;
		data[8] = 0.0f;
	}

	mat3::~mat3()
	{
	}

	mat3::mat3(const float k)
	{
		data[0] = k;
		data[1] = k;
		data[2] = k;
		data[3] = k;
		data[4] = k;
		data[5] = k;
		data[6] = k;
		data[7] = k;
		data[8] = k;
	}

	mat3::mat3(const float m11, const float m12, const float m13, const float m21, const float m22, const float m23, const float m31, const float m32, const float m33)
	{
		data[0] = m11;
		data[1] = m12;
		data[2] = m13;
		data[3] = m21;
		data[4] = m22;
		data[5] = m23;
		data[6] = m31;
		data[7] = m32;
		data[8] = m33;
	}

	mat3::mat3(const mat3 & m)
	{
		data[0] = m.data[0];
		data[1] = m.data[1];
		data[2] = m.data[2];
		data[3] = m.data[3];
		data[4] = m.data[4];
		data[5] = m.data[5];
		data[6] = m.data[6];
		data[7] = m.data[7];
		data[8] = m.data[8];
	}

	void mat3::clean()
	{
		if (data[0] > -1e-5 && data[0] < 1e-5) data[0] = 0;
		if (data[1] > -1e-5 && data[1] < 1e-5) data[1] = 0;
		if (data[2] > -1e-5 && data[2] < 1e-5) data[2] = 0;
		if (data[3] > -1e-5 && data[3] < 1e-5) data[3] = 0;
		if (data[4] > -1e-5 && data[4] < 1e-5) data[4] = 0;
		if (data[5] > -1e-5 && data[5] < 1e-5) data[5] = 0;
		if (data[6] > -1e-5 && data[6] < 1e-5) data[6] = 0;
		if (data[7] > -1e-5 && data[7] < 1e-5) data[7] = 0;
		if (data[8] > -1e-5 && data[8] < 1e-5) data[8] = 0;
	}

	mat3 & mat3::operator=(const mat3 & m1)
	{
		data[0] = m1.data[0];
		data[1] = m1.data[1];
		data[2] = m1.data[2];
		data[3] = m1.data[3];
		data[4] = m1.data[4];
		data[5] = m1.data[5];
		data[6] = m1.data[6];
		data[7] = m1.data[7];
		data[8] = m1.data[8];
		return *this;
	}

	float mat3::determinante() const 
	{
		return data[0] * (data[4] * data[8] - data[5] * data[7])
			- data[1] * (data[3] * data[8] - data[5] * data[6])
			+ data[2] * (data[3] * data[7] - data[4] * data[6]);
	}
	mat3 transpose(const mat3 & m)
	{
		mat3  m2 = mat3(
			m.data[0], m.data[3], m.data[6],
			m.data[1], m.data[4], m.data[7],
			m.data[2], m.data[5], m.data[8]);
		return m2;
	}
	mat3 inverse(const mat3 & m)
	{
		float mm11 = m.data[4] * m.data[8] - m.data[7] * m.data[5];
		float mm12 = m.data[3] * m.data[8] - m.data[5] * m.data[6];
		float mm13 = m.data[3] * m.data[7] - m.data[4] * m.data[6];
		float mm21 = m.data[1] * m.data[8] - m.data[7] * m.data[2];
		float mm22 = m.data[0] * m.data[8] - m.data[2] * m.data[6];
		float mm23 = m.data[0] * m.data[7] - m.data[6] * m.data[1];
		float mm31 = m.data[1] * m.data[5] - m.data[4] * m.data[2];
		float mm32 = m.data[0] * m.data[5] - m.data[2] * m.data[3];
		float mm33 = m.data[0] * m.data[4] - m.data[1] * m.data[3];

		mat3 cof_mat = mat3(mm11, -mm12, mm13, -mm21, mm22, -mm23, mm31, -mm32, mm33);
		mat3 adjoint = transpose(cof_mat);
		mat3 i = (1 / m.determinante()) * adjoint;
		
		return i;
	}

	const mat3 operator+(const mat3 & m1, const mat3 & m2)
	{
		mat3 result = mat3(m1.data[0] + m2.data[0], m1.data[1] + m2.data[1], m1.data[2] + m2.data[2], m1.data[3] + m2.data[3], m1.data[4] + m2.data[4], m1.data[5] + m2.data[5], m1.data[6] + m2.data[6], m1.data[7] + m2.data[7], m1.data[8] + m2.data[8]);
		return result;
	}
	const mat3 operator-(const mat3 & m1, const mat3 & m2)
	{
		mat3 result = mat3(m1.data[0] - m2.data[0], m1.data[1] - m2.data[1], m1.data[2] - m2.data[2], m1.data[3] - m2.data[3], m1.data[4] - m2.data[4], m1.data[5] - m2.data[5], m1.data[6] - m2.data[6], m1.data[7] - m2.data[7], m1.data[8] - m2.data[8]);
		return result;
	}

	const vec3 operator*(const mat3 & m, const vec3 & v)
	{
		vec3 result =  vec3(m.data[0] * v.x + m.data[1] * v.y + m.data[2] * v.z,
			m.data[3] * v.x + m.data[4] * v.y + m.data[5] * v.z,
			m.data[6] * v.x + m.data[7] * v.y + m.data[8] * v.z);
		return result;
	}

	const mat3 operator*(const mat3 & m, const float k) 
	{
		return k * m;
	}

	const mat3 operator*(const float k, const mat3 & m)
	{
		mat3 result = mat3(m.data[0] * k, m.data[1] * k, m.data[2] * k, m.data[3] * k, m.data[4] * k, m.data[5] * k, m.data[6] * k, m.data[7] * k, m.data[8] * k);
		return result;
	}
	
	const mat3 operator*(const mat3 & m1, const mat3 & m2)
	{
		mat3 result = mat3(
			m1.data[0] * m2.data[0] + m1.data[1] * m2.data[3] + m1.data[2] * m2.data[6],
			m1.data[0] * m2.data[1] + m1.data[1] * m2.data[4] + m1.data[2] * m2.data[7], 
			m1.data[0] * m2.data[2] + m1.data[1] * m2.data[5] + m1.data[2] * m2.data[8], 
			m1.data[3] * m2.data[0] + m1.data[4] * m2.data[3] + m1.data[5] * m2.data[6], 
			m1.data[3] * m2.data[1] + m1.data[4] * m2.data[4] + m1.data[5] * m2.data[7], 
			m1.data[3] * m2.data[2] + m1.data[4] * m2.data[5] + m1.data[5] * m2.data[8],
			m1.data[6] * m2.data[0] + m1.data[7] * m2.data[3] + m1.data[8] * m2.data[6],
			m1.data[6] * m2.data[1] + m1.data[7] * m2.data[4] + m1.data[8] * m2.data[7], 
			m1.data[6] * m2.data[2] + m1.data[7] * m2.data[5] + m1.data[8] * m2.data[8]);
		return result;
	}
	
	const bool operator==(const mat3 & m1, const mat3 & m2)
	{
		return equalFloats(m1.data[0], m2.data[0]) &&
			equalFloats(m1.data[1], m2.data[1]) &&
			equalFloats(m1.data[2], m2.data[2]) &&
			equalFloats(m1.data[3], m2.data[3]) &&
			equalFloats(m1.data[4], m2.data[4]) &&
			equalFloats(m1.data[5], m2.data[5]) &&
			equalFloats(m1.data[6], m2.data[6]) &&
			equalFloats(m1.data[7], m2.data[7]) &&
			equalFloats(m1.data[8], m2.data[8]);

	}
	const bool operator!=(const mat3 & m1, const mat3 & m2)
	{
		return !(m1 == m2);
	}
	std::ostream & operator<< (std::ostream & os, const mat3 & m)
	{
		os << "[ " << m.data[0] << ' ' << m.data[1] << ' ' << m.data[2] << " ]" << std::endl;
		os << "| " << m.data[3] << ' ' << m.data[4] << ' ' << m.data[5] << " |" << std::endl;
		os << "[ " << m.data[6] << ' ' << m.data[7] << ' ' << m.data[8] << " ]" << std::endl;
		return os;
	}

	/*-----------  MAT4------------*/
	mat4::mat4()
	{
		data[0] = 0.0f;  data[1] = 0.0f;  data[2] = 0.0f;  data[3] = 0.0f;
		data[4] = 0.0f;  data[5] = 0.0f;  data[6] = 0.0f;  data[7] = 0.0f;
		data[8] = 0.0f;  data[9] = 0.0f;  data[10] = 0.0f; data[11] = 0.0f;
		data[12] = 0.0f; data[13] = 0.0f; data[14] = 0.0f; data[15] = 0.0f;
	}

	mat4::~mat4()
	{
	}

	mat4::mat4(const float k)
	{
		data[0] = k;  data[1] = k;  data[2] = k;  data[3] = k;
		data[4] = k;  data[5] = k;  data[6] = k;  data[7] = k;
		data[8] = k;  data[9] = k;  data[10] = k; data[11] = k;
		data[12] = k; data[13] = k; data[14] = k; data[15] = k;
	}

	mat4::mat4(const float m11, const float m12, const float m13, const float m14, const float m21, const float m22, const float m23, const float m24, const float m31, const float m32, const float m33, const float m34, const float m41, const float m42, const float m43, const float m44)
	{
		data[0] = m11;  data[1] = m12;  data[2] = m13;  data[3] = m14;
		data[4] = m21;  data[5] = m22;  data[6] = m23;  data[7] = m24;
		data[8] = m31;  data[9] = m32;  data[10] = m33; data[11] = m34;
		data[12] = m41; data[13] = m42; data[14] = m43; data[15] = m44;
	}

	mat4::mat4(const mat4 & m)
	{
		data[0] = m.data[0];
		data[1] = m.data[1];
		data[2] = m.data[2];
		data[3] = m.data[3];
		data[4] = m.data[4];
		data[5] = m.data[5];
		data[6] = m.data[6];
		data[7] = m.data[7];
		data[8] = m.data[8];
		data[9] = m.data[9];
		data[10] = m.data[10];
		data[11] = m.data[11];
		data[12] = m.data[12];
		data[13] = m.data[13];
		data[14] = m.data[14];
		data[15] = m.data[15];
	}

	void mat4::clean()
	{
		if (data[0] > -1e-5 && data[0] < 1e-5) data[0] = 0;
		if (data[1] > -1e-5 && data[1] < 1e-5) data[1] = 0;
		if (data[2] > -1e-5 && data[2] < 1e-5) data[2] = 0;
		if (data[3] > -1e-5 && data[3] < 1e-5) data[3] = 0;
		if (data[4] > -1e-5 && data[4] < 1e-5) data[4] = 0;
		if (data[5] > -1e-5 && data[5] < 1e-5) data[5] = 0;
		if (data[6] > -1e-5 && data[6] < 1e-5) data[6] = 0;
		if (data[7] > -1e-5 && data[7] < 1e-5) data[7] = 0;
		if (data[8] > -1e-5 && data[8] < 1e-5) data[8] = 0;
		if (data[9] > -1e-5 && data[9] < 1e-5) data[9] = 0;
		if (data[10] > -1e-5 && data[10] < 1e-5) data[10] = 0;
		if (data[11] > -1e-5 && data[11] < 1e-5) data[11] = 0;
		if (data[12] > -1e-5 && data[12] < 1e-5) data[12] = 0;
		if (data[13] > -1e-5 && data[13] < 1e-5) data[13] = 0;
		if (data[14] > -1e-5 && data[14] < 1e-5) data[14] = 0;
		if (data[15] > -1e-5 && data[15] < 1e-5) data[15] = 0;
	}

	mat4 & mat4::operator=(const mat4 & m1)
	{
		data[0] = m1.data[0];
		data[1] = m1.data[1];
		data[2] = m1.data[2];
		data[3] = m1.data[3];
		data[4] = m1.data[4];
		data[5] = m1.data[5];
		data[6] = m1.data[6];
		data[7] = m1.data[7];
		data[8] = m1.data[8];
		data[9] = m1.data[9];
		data[10] = m1.data[10];
		data[11] = m1.data[11];
		data[12] = m1.data[12];
		data[13] = m1.data[13];
		data[14] = m1.data[14];
		data[15] = m1.data[15];
		return *this;
	}

	float mat4::determinante() const
	{
		mat3 d1 = mat3(
			data[5], data[6], data[7],
			data[9], data[10], data[11],
			data[13], data[14], data[15]);

		mat3 d2 = mat3(
			data[4], data[6], data[7],
			data[8], data[10], data[11],
			data[12], data[14], data[15]);

		mat3 d3 = mat3(
			data[4], data[5], data[7],
			data[8], data[9], data[11],
			data[12], data[13], data[15]);

		mat3 d4 = mat3(
			data[4], data[5], data[6],
			data[8], data[9], data[10],
			data[12], data[13], data[14]);


		float result = data[0] * d1.determinante() - data[1] * d2.determinante() + data[2] * d3.determinante() - data[3] * d4.determinante();
		return result; 
	}
	mat4 transpose(const mat4 & m)
	{
		mat4  m2 = mat4(
			m.data[0], m.data[4], m.data[8], m.data[12],
			m.data[1], m.data[5], m.data[9], m.data[13],
			m.data[2], m.data[6], m.data[10], m.data[14],
			m.data[3], m.data[7], m.data[11], m.data[15]);
		return m2;
	}

	const mat4 operator+(const mat4 & m1, const mat4 & m2)
	{
		mat4 result = mat4(
			m1.data[0] + m2.data[0], m1.data[1] + m2.data[1], m1.data[2] + m2.data[2], m1.data[3] + m2.data[3], 
			m1.data[4] + m2.data[4], m1.data[5] + m2.data[5], m1.data[6] + m2.data[6], m1.data[7] + m2.data[7], 
			m1.data[8] + m2.data[8], m1.data[9] + m2.data[9], m1.data[10] + m2.data[10], m1.data[11] + m2.data[11],
			m1.data[12] + m2.data[12], m1.data[13] + m2.data[13], m1.data[14] + m2.data[14], m1.data[15] + m2.data[15]);
		return result;
	}
	const mat4 operator-(const mat4 & m1, const mat4 & m2)
	{
		mat4  result = mat4(
			m1.data[0] - m2.data[0], m1.data[1] - m2.data[1], m1.data[2] - m2.data[2], m1.data[3] - m2.data[3],
			m1.data[4] - m2.data[4], m1.data[5]- m2.data[5], m1.data[6] - m2.data[6], m1.data[7] - m2.data[7],
			m1.data[8] - m2.data[8], m1.data[9] - m2.data[9], m1.data[10] - m2.data[10], m1.data[11] - m2.data[11],
			m1.data[12] - m2.data[12], m1.data[13] - m2.data[13], m1.data[14] - m2.data[14], m1.data[15] - m2.data[15]);
		return result;
	}

	const vec4 operator*(const mat4 & m, const vec4 & v)
	{
		vec4 result = vec4(
			m.data[0] * v.x + m.data[1] * v.y + m.data[2] * v.z + m.data[3] * v.w,
			m.data[4] * v.x + m.data[5] * v.y + m.data[6] * v.z + m.data[7] * v.w,
			m.data[8] * v.x + m.data[9] * v.y + m.data[10] * v.z + m.data[11] * v.w,
			m.data[12] * v.x + m.data[13] * v.y + m.data[14] * v.z + m.data[15] * v.w);
		return result;
	}

	const mat4 operator*(const mat4 & m, const float k)
	{
		return k * m;
	}

	const mat4 operator*(const float k, const mat4 & m)
	{
		mat4 result = mat4(
			m.data[0] * k, m.data[1] * k, m.data[2] * k, m.data[3] * k, 
			m.data[4] * k, m.data[5] * k, m.data[6] * k, m.data[7] * k, 
			m.data[8] * k, m.data[9] * k, m.data[10] * k, m.data[11] * k,
			m.data[12] * k, m.data[13] * k, m.data[14] * k, m.data[15] * k);
		return result;
	}

	const mat4 operator*(const mat4 & m1, const mat4 & m2)
	{
		float ab11 = m1.data[0] * m2.data[0] + m1.data[1] * m2.data[4] + m1.data[2] * m2.data[8] + m1.data[3] * m2.data[12];
		float ab12 = m1.data[0] * m2.data[1] + m1.data[1] * m2.data[5] + m1.data[2] * m2.data[9] + m1.data[3] * m2.data[13];
		float ab13 = m1.data[0] * m2.data[2] + m1.data[1] * m2.data[6] + m1.data[2] * m2.data[10] + m1.data[3] * m2.data[14];
		float ab14 = m1.data[0] * m2.data[3] + m1.data[1] * m2.data[7] + m1.data[2] * m2.data[11] + m1.data[3] * m2.data[15];

		float ab21 = m1.data[4] * m2.data[0] + m1.data[5] * m2.data[4] + m1.data[6] * m2.data[8] + m1.data[7] * m2.data[12];
		float ab22 = m1.data[4] * m2.data[1] + m1.data[5] * m2.data[5] + m1.data[6] * m2.data[9] + m1.data[7] * m2.data[13];
		float ab23 = m1.data[4] * m2.data[2] + m1.data[5] * m2.data[6] + m1.data[6] * m2.data[10] + m1.data[7] * m2.data[14];
		float ab24 = m1.data[4] * m2.data[3] + m1.data[5] * m2.data[7] + m1.data[6] * m2.data[11] + m1.data[7] * m2.data[15];

		float ab31 = m1.data[8] * m2.data[0] + m1.data[9] * m2.data[4] + m1.data[10] * m2.data[8] + m1.data[11] * m2.data[12];
		float ab32 = m1.data[8] * m2.data[1] + m1.data[9] * m2.data[5] + m1.data[10] * m2.data[9] + m1.data[11] * m2.data[13];
		float ab33 = m1.data[8] * m2.data[2] + m1.data[9] * m2.data[6] + m1.data[10] * m2.data[10] + m1.data[11] * m2.data[14];
		float ab34 = m1.data[8] * m2.data[3] + m1.data[9] * m2.data[7] + m1.data[10] * m2.data[11] + m1.data[11] * m2.data[15];

		float ab41 = m1.data[12] * m2.data[0] + m1.data[13] * m2.data[4] + m1.data[14] * m2.data[8] + m1.data[15] * m2.data[12];
		float ab42 = m1.data[12] * m2.data[1] + m1.data[13] * m2.data[5] + m1.data[14] * m2.data[9] + m1.data[15] * m2.data[13];
		float ab43 = m1.data[12] * m2.data[2] + m1.data[13] * m2.data[6] + m1.data[14] * m2.data[10] + m1.data[15] * m2.data[14];
		float ab44 = m1.data[12] * m2.data[3] + m1.data[13] * m2.data[7] + m1.data[14] * m2.data[11] + m1.data[15] * m2.data[15];

		mat4 result =  mat4(
			ab11, ab12, ab13, ab14,
			ab21, ab22, ab23, ab24,
			ab31, ab32, ab33, ab34,
			ab41, ab42, ab43, ab44);

		return result; 
	}

	const bool operator==(const mat4 & m1, const mat4 & m2)
	{
		return equalFloats(m1.data[0], m2.data[0]) &&
			equalFloats(m1.data[1], m2.data[1]) &&
			equalFloats(m1.data[2], m2.data[2]) &&
			equalFloats(m1.data[3], m2.data[3]) &&
			equalFloats(m1.data[4], m2.data[4]) &&
			equalFloats(m1.data[5], m2.data[5]) &&
			equalFloats(m1.data[6], m2.data[6]) &&
			equalFloats(m1.data[7], m2.data[7]) &&
			equalFloats(m1.data[8], m2.data[8]) &&
			equalFloats(m1.data[9], m2.data[9]) &&
			equalFloats(m1.data[10], m2.data[10]) &&
			equalFloats(m1.data[11], m2.data[11]) &&
			equalFloats(m1.data[12], m2.data[12]) &&
			equalFloats(m1.data[13], m2.data[13]) &&
			equalFloats(m1.data[14], m2.data[14]) &&
			equalFloats(m1.data[15], m2.data[15]);
		/*return m1.data[0] == m2.data[0] &&
			m1.data[1] == m2.data[1] &&
			m1.data[2] == m2.data[2] &&
			m1.data[3] == m2.data[3] &&
			m1.data[4] == m2.data[4] &&
			m1.data[5] == m2.data[5] &&
			m1.data[6] == m2.data[6] &&
			m1.data[7] == m2.data[7] &&
			m1.data[8] == m2.data[8] &&
			m1.data[9] == m2.data[9] &&
			m1.data[10] == m2.data[10] &&
			m1.data[11] == m2.data[11] &&
			m1.data[12] == m2.data[12] &&
			m1.data[13] == m2.data[13] &&
			m1.data[14] == m2.data[14] && 
			m1.data[15] == m2.data[15];*/

	}
	const bool operator!=(const mat4 & m1, const mat4 & m2)
	{
		return !(m1 == m2);
	}
	std::ostream & operator<< (std::ostream & os, const mat4 & m)
	{
		os << "[ " << m.data[0] << ' ' << m.data[1] << ' ' << m.data[2] << ' ' << m.data[3] << " ]" << std::endl;
		os << "| " << m.data[4] << ' ' << m.data[5] << ' ' << m.data[6] << ' ' << m.data[7] << " |" << std::endl;
		os << "| " << m.data[8] << ' ' << m.data[9] << ' ' << m.data[10] << ' ' << m.data[11] << " |" << std::endl;
		os << "[ " << m.data[12] << ' ' << m.data[13] << ' ' << m.data[14] << ' ' << m.data[15] << " ]" << std::endl;
		return os;
	}
}

