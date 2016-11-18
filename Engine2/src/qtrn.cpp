#include "qtrn.h"

namespace Engine2
{
	qtrn::qtrn()
	{
		t = 0.0f;
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	qtrn::~qtrn()
	{
	}

	qtrn::qtrn(const float tt, const float xx, const float yy, const float zz)
	{
		t = tt;
		x = xx;
		y = yy;
		z = zz;
	}

	qtrn::qtrn(const float theta, const vec3 & axis)
	{
		vec3 axisn = axis.normalize();
		//float a = theta * (float)DEGREES_TO_RADIANS;

		float a = theta;
		float s = sin(a / 2.0f);

		qtrn q = qtrn(cos(a / 2.0f), axisn.x * s, axisn.y * s, axisn.z * s);
		
		qtrn qn = q;

		t = qn.t;
		x = qn.x;
		y = qn.y;
		z = qn.z;
	}

	qtrn::qtrn(const vec3 & axis, const float theta)
	{
		vec3 axisn = axis.normalize();
		//float a = theta * (float)DEGREES_TO_RADIANS;

		float a = theta;
		float s = sin(a / 2.0f);

		qtrn q = qtrn(cos(a / 2.0f), axisn.x * s, axisn.y * s, axisn.z * s);

		qtrn qn = q;

		t = qn.t;
		x = qn.x;
		y = qn.y;
		z = qn.z;
	}

	qtrn::qtrn(const float theta, const vec4 & axis)
	{
		vec4 axisn = axis.normalize();
		float a = theta;
		//float a = theta * (float)DEGREES_TO_RADIANS;
		float s = sin(a / 2.0f);

		qtrn q = qtrn(cos(a / 2.0f), axisn.x * s, axisn.y * s, axisn.z * s);

		qtrn qn = q;

		t = qn.t;
		x = qn.x;
		y = qn.y;
		z = qn.z;
	}

	qtrn::qtrn(const qtrn & q)
	{
		t = q.t;
		x = q.x;
		y = q.y;
		z = q.z;
	}
	
	void qtrn::clean() {
		if (t > -1e-5 && t < 1e-5) t = 0.0f;
		if (x > -1e-5 && x < 1e-5) x = 0.0f;
		if (y > -1e-5 && y < 1e-5) y = 0.0f;
		if (z > -1e-5 && z < 1e-5) z = 0.0f;
	}

	qtrn & qtrn::operator=(const qtrn & q)
	{
		t = q.t;
		x = q.x;
		y = q.y;
		z = q.z;
		return *this;
	}

	const void qtrn::toAngleAxis(float & theta, vec4 & axis)
	{
		qtrn qn = normalize();
		theta = 2.0f * acos(qn.t);
		//theta = 2.0f * acos(qn.t) * (float)RADIANS_TO_DEGREES;
		float s = sqrt(1.0f - qn.t*qn.t);
		if (s < threshold) {
			axis.x = 1.0f;
			axis.y = 0.0f;
			axis.z = 0.0f;
			axis.w = 1.0f;
		}
		else {
			axis.x = qn.x / s;
			axis.y = qn.y / s;
			axis.z = qn.z / s;
			axis.w = 1.0f;
		}
	}

	const float qtrn::quadrance() const
	{
		return t*t + x*x + y*y + z*z;
	}
	const float qtrn::norm() const
	{
		return sqrt(quadrance());
	}
	const qtrn qtrn::normalize() const
	{
		float s = 1.0f / norm();
		return qtrn(t * s, x * s, y * s, z * s);
	}
	const qtrn qtrn::conjugate() const
	{
		return qtrn(t, -x, -y, -z );
	}
	const qtrn qtrn::inverse() const
	{
		return conjugate() * (1.0f / quadrance());
	}

	const qtrn operator+ (const qtrn & q0, const qtrn & q1)
	{
		return qtrn(
			q0.t + q1.t,
			q0.x + q1.x,
			q0.y + q1.y,
			q0.z + q1.z);
	}
	const qtrn operator- (const qtrn & q0, const qtrn & q1)
	{
		return q0 + (-1.0f * q1);
	}

	const qtrn operator* (const qtrn & q, const float s)
	{
		return qtrn(
			s * q.t,
			s * q.x,
			s * q.y,
			s * q.z);
	}

	const qtrn operator* (const float s, const qtrn & q)
	{
		return q * s;
	}

	const qtrn operator* (const qtrn & q0, const qtrn & q1)
	{
		return qtrn(
			q0.t * q1.t - q0.x * q1.x - q0.y * q1.y - q0.z * q1.z,
			q0.t * q1.x + q0.x * q1.t + q0.y * q1.z - q0.z * q1.y,
			q0.t * q1.y + q0.y * q1.t + q0.z * q1.x - q0.x * q1.z,
			q0.t * q1.z + q0.z * q1.t + q0.x * q1.y - q0.y * q1.x);
		
	}
	
	const bool operator== (const qtrn & q0, const qtrn & q1)
	{
		const float threshold = (float)1.0e-5;
		return (fabs(q0.t - q1.t) < threshold && fabs(q0.x - q1.x) < threshold &&
			fabs(q0.y - q1.y) < threshold && fabs(q0.z - q1.z) < threshold);
	}
	const bool operator!= (const qtrn & q0, const qtrn & q1)
	{
		return !(q0 == q1);
	}

	const qtrn lerp(const qtrn & q0, const qtrn & q1, const float k)
	{
		float cos_angle = q0.x*q1.x + q0.y*q1.y + q0.z*q1.z + q0.t*q1.t;
		float k0 = 1.0f - k;
		float k1 = (cos_angle > 0) ? k : -k;
		qtrn qi = q0 * k0 + q1 * k1;
		return qi.normalize();
	}
	const qtrn slerp(const qtrn & q0, const qtrn & q1, const float k)
	{
		float angle = acos(q0.x*q1.x + q0.y*q1.y + q0.z*q1.z + q0.t*q1.t);
		float k0 = sin((1 - k)*angle) / sin(angle);
		float k1 = sin(k*angle) / sin(angle);
		qtrn qi = q0 * k0 + q1 * k1;
		return qi.normalize();
	}

	std::ostream & operator<< (std::ostream & os, const qtrn & q)
	{
		os << "(" << q.t << ", " << q.x << ", " << q.y << ", " << q.z << ")";
		return os;
	}

	
}