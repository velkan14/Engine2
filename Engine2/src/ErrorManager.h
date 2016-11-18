#pragma once

#ifndef ERROR_MANAGER
#define ERROR_MANAGER

#include <iostream>
#include <string>
#include "GL\glew.h"
#include "GL\freeglut.h"


namespace Engine2 
{
	class ErrorManager
	{
	public:
		static bool isOpenGLError();
		static void checkOpenGLError(std::string error);
	};
}
#endif