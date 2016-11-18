#pragma once
#ifndef CAMERA_MANAGER
#define CAMERA_MANAGER

#include "GL\glew.h"
#include "GL\freeglut.h"
#include "Camera.h"
#include "ShaderManager.h"
#include "Constant.h"

namespace Engine2
{

	class CameraManager
	{
		
	private:
		const vec3 X_AXIS = vec3(1.0f, 0.0f, 0.0f);
		const vec3 Y_AXIS = vec3(0.0f, 1.0f, 0.0f);

		Camera * camera;
		ShaderManager * _shaderManager;

		GLuint _VaoId;
		bool ortho, gimbal;
		float screenWidth, screenHeight;
		mat4 r;
		qtrn q;
		
		int LastMousePositionX, LastMousePositionY;
		float RotationAngleX = 0.0f;
		float RotationAngleY = 0.0f;
		const float DistanceStep = 1.5f;
		float Distance = 20.0f;

	public:
		CameraManager();
		void init(ShaderManager * shaderManager, GLuint VaoId);
		void computeMatrix();
		void changeCamera();
		void changeRotation();
		void update();
		void mouse(int button, int state, int xx, int yy);
		void mouseMotion(int xx, int yy);
		void mouseWheel(int wheel, int direction, int x, int y);
		void reshape(int w, int h);
		
	};
}
#endif