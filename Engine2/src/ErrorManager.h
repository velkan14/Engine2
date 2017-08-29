#pragma once

#ifndef ERROR_MANAGER
#define ERROR_MANAGER

#include <string>

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