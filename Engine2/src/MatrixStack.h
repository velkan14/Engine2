#pragma once
#ifndef MATRIX_STACK
#define MATRIX_STACK
#include <vector>
#include "MatFactory.h"

namespace Engine2
{
	class MatrixStack
	{
		std::vector<mat4> stack;
	public:
		void loadIdentity();
		void pushMatrix();
		void popMatrix();

		void translate(const vec3 & v);
		void translate(const float x, const float y, const float z);
		void scale(const vec3 & v);
		void scale(const float x, const float y, const float z);
		
		void rotate(vec3 axis, float angle);
		void rotate(float angle, vec3 axis);
		void rotate(qtrn q);

		mat4 getCurrentMatrix();
	};
}
#endif // !MATRIX_STACK
