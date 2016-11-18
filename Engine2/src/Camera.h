#pragma once

#ifndef CAMERA
#define CAMERA

#include "MatFactory.h"
#include "ShaderManager.h"

namespace Engine2 {
	class Camera {
	protected:
		mat4 _viewMatrix, _projectionMatrix;
		ShaderManager * _shaderManager;
	public:
		Camera(ShaderManager * shaderManager);
		void setViewMatrix(mat4 viewMatrix);
		mat4 getViewMatrix();
		void setProjectionMatrix(mat4 projection);
		mat4 getProjectionMatrix();
	};
}
#endif // !CAMERA

