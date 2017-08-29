#pragma once

#ifndef CAMERA
#define CAMERA


#include "GL\glew.h"
#include "GL\freeglut.h"

#include "mat.h"

namespace Engine2 {

	class Camera {
	protected:
		mat4 _viewMatrix, _projectionMatrix;

		GLint _viewMatrixId, _projectionMatrixId;
		GLuint _bufferId;

	public:
		Camera(GLuint ubo_bp);
		~Camera();

		void setViewMatrix(mat4 viewMatrix);
		mat4 getViewMatrix();
		void setProjectionMatrix(mat4 projection);
		mat4 getProjectionMatrix();

		void loadMatrices();
	};
}


#endif // !CAMERA

