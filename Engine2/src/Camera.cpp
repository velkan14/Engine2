#include "Camera.h"

namespace Engine2
{

	Camera::Camera(ShaderManager * shaderManager)
	{
		_shaderManager = shaderManager;
	}

	void Camera::setViewMatrix(mat4 viewMatrix)
	{
		_viewMatrix = viewMatrix;
		GLfloat * m = MatFactory::createGLMatrixFromMat4(viewMatrix);
		glUniformMatrix4fv(_shaderManager->getViewMatrixId(), 1, GL_FALSE, m);
		delete m;
	}

	void Camera::setProjectionMatrix(mat4 projectionMatrix)
	{
		_projectionMatrix = projectionMatrix;
		GLfloat * m = MatFactory::createGLMatrixFromMat4(projectionMatrix);
		glUniformMatrix4fv(_shaderManager->getProjectionMatrixId(), 1, GL_FALSE, m);
		delete m;
	}

	mat4 Camera::getProjectionMatrix()
	{
		return _projectionMatrix;
	}

	mat4 Camera::getViewMatrix()
	{
		return _viewMatrix;
	}
}