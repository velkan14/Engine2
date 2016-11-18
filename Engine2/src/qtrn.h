#pragma once
#ifndef QUATERNION
#define QUATERNION

#include "vec.h"

namespace Engine2 {

	struct qtrn{
		float t, x, y, z;

		const float threshold = (float)1.0e-5;

		qtrn();
		~qtrn();
		qtrn(const float t, const float x, const float y, const float z);
		qtrn(const vec3 & axis, const float theta);
		qtrn(const float theta, const vec3 & axis);
		qtrn(const float theta, const vec4 & axis);
		qtrn(const qtrn & q);
		void clean();

		qtrn & operator= (const qtrn & q);
		const void toAngleAxis(float & theta, vec4 & axis);

		const float quadrance() const;
		const float norm() const;
		const qtrn normalize() const;
		const qtrn conjugate() const;
		const qtrn inverse() const;

		friend const qtrn operator+ (const qtrn & q0, const qtrn & q1);
		friend const qtrn operator- (const qtrn & q0, const qtrn & q1);

		friend const qtrn operator* (const qtrn & q, const float s);
		friend const qtrn operator* (const float s, const qtrn & q);
		friend const qtrn operator* (const qtrn & q0, const qtrn & q1);

		friend const bool operator== (const qtrn & q0, const qtrn & q1);
		friend const bool operator!= (const qtrn & q0, const qtrn & q1);

		friend const qtrn lerp(const qtrn & q0, const qtrn & q1, const float k);
		friend const qtrn slerp(const qtrn & q0, const qtrn & q1, const float k);

		friend std::ostream & operator<< (std::ostream & os, const qtrn & other);
	};
}

#endif
