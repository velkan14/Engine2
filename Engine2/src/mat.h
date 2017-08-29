#pragma once

#ifndef MAT
#define MAT

#include <iostream>
#include <sstream>

namespace Engine2 {

	struct vec2; 
	struct vec3;
	struct vec4;

	struct mat2{
		float data[4];
		mat2();
		~mat2();
		mat2(const float k);
		mat2(const float a, const float b, const float c, const float d);
		mat2(const mat2 & m);
		void clean();
		mat2 & operator=(const mat2 & m1);
		float determinante() const;
		friend mat2 transpose(const mat2 & m);
		friend mat2 inverse(const mat2 & m);
		friend const mat2 operator+(const mat2 & m1, const mat2 & m2);
		friend const mat2 operator-(const mat2 & m1, const mat2 & m2);
		friend const vec2 operator*(const mat2 & m, const vec2 & v);
		friend const mat2 operator*(const mat2 & m, const float k);
		friend const mat2 operator*(const float k, const mat2 & m);
		friend const mat2 operator*(const mat2 & m1, const mat2 & m2);
		friend const bool operator==(const mat2 & m1, const mat2 & m2);
		friend const bool operator!=(const mat2 & m1, const mat2 & m2); 
		friend std::ostream & operator<< (std::ostream & os, const mat2 & m);
	};

	struct mat3 {
		float data[9];
		mat3();
		~mat3();
		mat3(const float k);
		mat3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i);
		mat3(const mat3 & m);
		void clean();
		mat3 & operator=(const mat3 & m1);
		float determinante() const;
		friend mat3 transpose(const mat3 & m);
		friend mat3 inverse(const mat3 & m);
		friend const mat3 operator+(const mat3 & m1, const mat3 & m2);
		friend const mat3 operator-(const mat3 & m1, const mat3 & m2);
		friend const vec3 operator*(const mat3 & m, const vec3 & v);
		friend const mat3 operator*(const mat3 & m, const float k);
		friend const mat3 operator*(const float k, const mat3 & m);
		friend const mat3 operator*(const mat3 & m1, const mat3 & m2);
		friend const bool operator==(const mat3 & m1, const mat3 & m2);
		friend const bool operator!=(const mat3 & m1, const mat3 & m2);
		friend std::ostream & operator<< (std::ostream & os, const mat3 & m);
	};

	struct mat4 {
		float data[16];
		mat4();
		~mat4();
		mat4(const float k);
		mat4(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i, const float j, const float k, const float l, const float m, const float n, const float o, const float p);
		mat4(const mat4 & m);
		void clean();
		mat4 & operator=(const mat4 & m1);
		float determinante() const;
		friend mat4 transpose(const mat4 & m);
		friend mat4 inverse(const mat4 & m);
		friend const mat4 operator+(const mat4 & m1, const mat4 & m2);
		friend const mat4 operator-(const mat4 & m1, const mat4 & m2);
		friend const vec4 operator*(const mat4 & m, const vec4 & v);
		friend const mat4 operator*(const mat4 & m, const float k);
		friend const mat4 operator*(const float k, const mat4 & m);
		friend const mat4 operator*(const mat4 & m1, const mat4 & m2);
		friend const bool operator==(const mat4 & m1, const mat4 & m2);
		friend const bool operator!=(const mat4 & m1, const mat4 & m2);
		friend std::ostream & operator<< (std::ostream & os, const mat4 & m);
	};
}
#endif