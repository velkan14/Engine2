#pragma once

#ifndef VEC
#define VEC

#include <iostream>
#include <sstream>

namespace Engine2 {

	static bool equalFloats(const float a, const float b) {
		if (a > 0.0f && b < 0.0f || a < 0.0f && b > 0.0f) return false;
		return trunc(1000.0f * a) == trunc(1000.0f * b);
	}

	struct vec2 {
		float x, y;

		vec2();
		~vec2();
		vec2(const float a, const float b);
		vec2(const vec2 & v);
		void clean();
		vec2 & operator= (const vec2 & v);
		friend const vec2 operator+ (const vec2 & v1, const vec2 & v2);
		friend const vec2 operator- (const vec2 & v1, const vec2 & v2);
		friend const vec2 operator* (const vec2 & v, const float k);
		friend const vec2 operator* (const float k, const vec2 & v);

		friend void operator+= (vec2 & v1, const vec2 & v2);
		friend void operator-= (vec2 & v1, const vec2 & v2);
		friend void operator*= (vec2 & v, const float k);

		friend const bool operator== (const vec2 & v1, const vec2 & v2);
		friend const bool operator!= (const vec2 & v1, const vec2 & v2);

		friend std::ostream & operator<< (std::ostream & os, const vec2 & other);
		friend std::istream & operator>> (std::istream & is, vec2 & other);
		friend std::stringstream & operator>> (std::stringstream & is, vec2 & other);

		float quadrance() const;
		float norm() const;
		const vec2 normalize() const;
		float dot(const vec2 & other) const;
	};

	struct vec3 {
		float x, y, z;

		vec3();
		~vec3();
		vec3(const float a, const float b, const float c);
		vec3(const vec3 & v);
		void clean();
		vec3 & operator= (const vec3 & v);
		friend const vec3 operator+ (const vec3 & v1, const vec3 & v2);
		friend const vec3 operator- (const vec3 & v1, const vec3 & v2);
		friend const vec3 operator* (const vec3 & v, const float k);
		friend const vec3 operator* (const float k, const vec3 & v);

		friend void operator+= (vec3 & v1, const vec3 & v2);
		friend void operator-= (vec3 & v1, const vec3 & v2);
		friend void operator*= (vec3 & v, const float k);

		friend const bool operator== (const vec3 & v1, const vec3 & v2);
		friend const bool operator!= (const vec3 & v1, const vec3 & v2);

		friend std::ostream & operator<< (std::ostream & os, const vec3 & other);
		friend std::istream & operator>> (std::istream & is, vec3 & other);
		friend std::stringstream & operator>> (std::stringstream & is, vec3 & other);

		friend const vec3 lerp(const vec3 & v0, const vec3 & v1, const float k);
		friend const vec3 slerp(const vec3 & v0, const vec3 & v1, const float k);

		float quadrance() const;
		float norm() const;
		const vec3 normalize() const;
		float dot(const vec3 & other) const;
		const vec3 cross(const vec3 & other) const;
	};

	struct vec4 {
		float x, y, z, w;

		vec4();
		~vec4();
		vec4(const float a, const float b, const float c, const float d);
		vec4(const vec4 & v);
		void clean();
		vec4 & operator= (const vec4 & v);
		friend const vec4 operator+ (const vec4 & v1, const vec4 & v2);
		friend const vec4 operator- (const vec4 & v1, const vec4 & v2);
		friend const vec4 operator* (const vec4 & v, const float k);
		friend const vec4 operator* (const float k, const vec4 & v);

		friend void operator+= (vec4 & v1, const vec4 & v2);
		friend void operator-= (vec4 & v1, const vec4 & v2);
		friend void operator*= (vec4 & v, const float k);

		friend const bool operator== (const vec4 & v1, const vec4 & v2);
		friend const bool operator!= (const vec4 & v1, const vec4 & v2);

		friend std::ostream & operator<< (std::ostream & os, const vec4 & other);
		friend std::istream & operator>> (std::istream & is, vec4 & other);
		friend std::stringstream & operator>> (std::stringstream & is, vec4 & other);

		float quadrance() const;
		float norm() const;
		const vec4 normalize() const;
		float dot(const vec4 & other) const;
		//vec4 cross(const vec4 & other);
	};

}

#endif