#include "CameraManager.h"

namespace Engine2 {

	CameraManager::CameraManager()
	{
	
	}

	void CameraManager::init(ShaderManager * shaderManager, GLuint VaoId)
	{
		_shaderManager = shaderManager;
		_VaoId = VaoId;

		camera = new Camera(shaderManager);
		ortho = false;
		gimbal = true;
		screenWidth = 640; screenHeight = 480;
		r = MatFactory::createIdentityMat4();
		q = qtrn(1.0f,0.0f,0.0f,0.0f);
		Distance = -5.0f;
	}

	void CameraManager::computeMatrix()
	{
		mat4 t = MatFactory::createTranslationMat4(0.0f, 0.0f, Distance);

		glBindVertexArray(_VaoId);
		glUseProgram(_shaderManager->getProgramId());

		if (gimbal)
		{
			camera->setViewMatrix(transpose(t*r));
		}
		else
		{
			camera->setViewMatrix(transpose(t*MatFactory::createMat4FromQuaternion(q)));
		}
		
		
		if (ortho) {
			camera->setProjectionMatrix(MatFactory::createOrthographicProjectionMatrix(-2.0f, 2.0f, -2.0f, 2.0f,1.0f, 20.0f));
		}
		else
		{
			camera->setProjectionMatrix(MatFactory::createPerspectiveProjectionMatrix(30.0f * (float)DEGREES_TO_RADIANS, screenWidth / screenHeight, 1.0f, 20.0f));
		}

		glUseProgram(0);
		glBindVertexArray(0);
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
			q = MatFactory::createQuaternionFromMat4(transpose(r));
		}
		else
		{
			gimbal = true;
			r = MatFactory::createMat4FromQuaternion(q);
		}

	}
	
	void CameraManager::update()
	{
		q = q * qtrn(-RotationAngleX * (float)DEGREES_TO_RADIANS, X_AXIS) * 
				qtrn(-RotationAngleY * (float)DEGREES_TO_RADIANS, Y_AXIS);

		r = r * MatFactory::createRotationMat4(Y_AXIS, RotationAngleY * (float)DEGREES_TO_RADIANS) *
			MatFactory::createRotationMat4(X_AXIS, RotationAngleX * (float)DEGREES_TO_RADIANS);

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

}