#include "Camera.h"

#include "MatFactory.h"

namespace Engine2
{

	Camera::Camera(GLuint ubo_bp)
	{
		glGenBuffers(1, &_bufferId);
		glBindBuffer(GL_UNIFORM_BUFFER, _bufferId);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(float) * 32, 0, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, ubo_bp, _bufferId);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	Camera::~Camera()
	{
	}

	void Camera::setViewMatrix(mat4 viewMatrix)
	{
		_viewMatrix = viewMatrix;
	}

	void Camera::setProjectionMatrix(mat4 projectionMatrix)
	{
		_projectionMatrix = projectionMatrix;
	}

	void Camera::loadMatrices()
	{
		GLfloat * mView = MatFactory::GLMatrixFromMat4(_viewMatrix);
		GLfloat * mProjection = MatFactory::GLMatrixFromMat4(_projectionMatrix);

		glBindBuffer(GL_UNIFORM_BUFFER, _bufferId);

		glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(float) * 16, mView);
		glBufferSubData(GL_UNIFORM_BUFFER, sizeof(float) * 16, sizeof(float) * 16, mProjection);

		glBindBuffer(GL_UNIFORM_BUFFER, 0);
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