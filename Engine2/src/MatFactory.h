#pragma once

#ifndef MAT_FACTORY
#define MAT_FACTORY

#include "mat.h"
#include "qtrn.h"
#include "GL\glew.h"

namespace Engine2 {

	struct MatFactory {

		static const mat3 createZeroMat3();
		static const mat3 createIdentityMat3();
		static const mat3 createDualMat3(const vec3 & v);

		static const mat4 createZeroMat4();
		static const mat4 createIdentityMat4();
		static const mat4 createDualMat4();

		static const mat4 createMat4FromMat3(const mat3 & m);
		static const mat3 createMat3FromMat4(const mat4 & m);

		static mat4 createMat4FromGLMatrix(const GLfloat m[]);
		static GLfloat * createGLMatrixFromMat4(const mat4 & m);
		static const mat4 createScaleMat4(const vec3 & v);
		static const mat4 createRotationMat4(const vec3 & axis, const float angle);
		static const mat4 createTranslationMat4(const vec3 & v);

		static const mat4 createScaleMat4(const float x, const float y, const float z);
		static const mat4 createTranslationMat4(const float x, const float y, const float z);

		static const mat4 createViewMatrix(const vec3 eye, const vec3 center, const vec3 up);
		static const mat4 createOrthographicProjectionMatrix(const float left, const float right, const float bottom, const float top, const float near, const float far);
		static const mat4 createPerspectiveProjectionMatrix(const float fovy, const float aspect, const float nearZ, const float farZ);

		static const mat4 createMat4FromQuaternion(const qtrn & q);
		static const qtrn createQuaternionFromMat4(const mat4 & m);

	};
}

#endif