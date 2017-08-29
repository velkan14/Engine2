#include "CameraManager.h"

#include "mat.h"
#include "qtrn.h"
#include "MatFactory.h"
#include "Camera.h"
#include "Constant.h"

namespace Engine2 {

	CameraManager::CameraManager()
	{
	
	}

	void CameraManager::init(GLuint Ubo)
	{
		camera = new Camera(Ubo);
		ortho = false;
		gimbal = true;
		screenWidth = 640; screenHeight = 480;
		r = MatFactory::IdentityMat4();
		q = qtrn(1.0f,0.0f,0.0f,0.0f);
		Distance = -5.0f;
	}

	void CameraManager::computeMatrix()
	{
		mat4 t = MatFactory::TranslationMat4(0.0f, 0.0f, Distance);

		//glBindVertexArray(_VaoId);
		//glUseProgram(_shaderManager->getProgramId()); FIXME

		if (gimbal)
		{
			camera->setViewMatrix(transpose(t*r));
		}
		else
		{
			camera->setViewMatrix(transpose(t*MatFactory::Mat4FromQuaternion(q)));
		}
		
		
		if (ortho) {
			camera->setProjectionMatrix(MatFactory::OrthographicProjectionMatrix(-2.0f, 2.0f, -2.0f, 2.0f,1.0f, 100.0f));
		}
		else
		{
			camera->setProjectionMatrix(MatFactory::PerspectiveProjectionMatrix(30.0f * (float)DEGREES_TO_RADIANS, screenWidth / screenHeight, 1.0f, 100.0f));
		}

		//glUseProgram(0);
		//glBindVertexArray(0);
	}

	void CameraManager::changeCamera()
	{
		ortho = !ortho;
	}

	void CameraManager::changeRotation()
	{
		if (gimbal)
		{
			gimbal = false;
			q = MatFactory::QuaternionFromMat4(transpose(r));
		}
		else
		{
			gimbal = true;
			r = MatFactory::Mat4FromQuaternion(q);
		}

	}
	
	void CameraManager::update()
	{
		q = q * qtrn(-RotationAngleX * (float)DEGREES_TO_RADIANS, X_AXIS) * 
				qtrn(-RotationAngleY * (float)DEGREES_TO_RADIANS, Y_AXIS);

		r = r * MatFactory::RotationMat4(Y_AXIS, RotationAngleY * (float)DEGREES_TO_RADIANS) *
			MatFactory::RotationMat4(X_AXIS, RotationAngleX * (float)DEGREES_TO_RADIANS);

		RotationAngleX = RotationAngleY = 0.0f;
	}

	void CameraManager::mouse(int button, int state, int x, int y)
	{
		LastMousePositionX = x;
		LastMousePositionY = y;
		if (state == GLUT_UP)
			RotationAngleX = RotationAngleY = 0.0f;
	}

	void CameraManager::mouseMotion(int x, int y)
	{
		RotationAngleX = (float)(y - LastMousePositionY);
		LastMousePositionY = y;
		RotationAngleY = (float)(x - LastMousePositionX);
		LastMousePositionX = x;
	}

	void CameraManager::mouseWheel(int button, int dir, int x, int y)
	{
		if (dir > 0) {
			Distance -= DistanceStep;
		}
		else {
			Distance += DistanceStep;
		}
	}

	void CameraManager::reshape(int w, int h)
	{
		screenWidth = w;
		screenHeight = h;
	}

	Camera * CameraManager::getCamera() {
		return camera;
	}

}