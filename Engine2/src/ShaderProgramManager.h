#pragma once
#ifndef _SHADER_MANAGER_
#define _SHADER_MANAGER_

#include <string>
#include <map>

namespace Engine2
{
	class ShaderProgram;

	class ShaderProgramManager
	{
	private:
		static ShaderProgramManager* m_instance;

		std::map<std::string, ShaderProgram*> shaders;

		ShaderProgramManager();
		~ShaderProgramManager();

	public:
		static ShaderProgramManager* instance();
		void add(const std::string& name, ShaderProgram* shader);
		ShaderProgram* get(const std::string& name);

		void destroy();
	};
}


#endif