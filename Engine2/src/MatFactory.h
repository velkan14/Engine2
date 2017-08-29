#pragma once

#ifndef MAT_FACTORY
#define MAT_FACTORY

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace Engine2 {

	struct mat3;
	struct mat4;
	struct vec3;
	struct qtrn;

	struct MatFactory {
		static const mat3 ZeroMat3();
		static const mat3 IdentityMat3();
		static const mat3 DualMat3(const vec3 & v);

		static const mat4 ZeroMat4();
		static const mat4 IdentityMat4();
		static const mat4 DualMat4();

		static const mat4 Mat4FromMat3(const mat3 & m);
		static const mat3 Mat3FromMat4(const mat4 & m);

		static mat4 Mat4FromGLMatrix(const GLfloat m[]);
		static GLfloat * GLMatrixFromMat4(const mat4 & m);
		static GLfloat * GLMatrixFromMat3(const mat3 & m);
		static const mat4 ScaleMat4(const vec3 & v);
		static const mat4 RotationMat4(const vec3 & axis, const float angle);
		static const mat4 TranslationMat4(const vec3 & v);

		static const mat4 ScaleMat4(const float x, const float y, const float z);
		static const mat4 TranslationMat4(const float x, const float y, const float z);

		static const mat4 ViewMatrix(const vec3 eye, const vec3 center, const vec3 up);
		static const mat4 OrthographicProjectionMatrix(const float left, const float right, const float bottom, const float top, const float near, const float far);
		static const mat4 PerspectiveProjectionMatrix(const float fovy, const float aspect, const float nearZ, const float farZ);

		static const mat4 Mat4FromQuaternion(const qtrn & q);
		static const qtrn QuaternionFromMat4(const mat4 & m);


	};
}

#endif