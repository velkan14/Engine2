#pragma once

#ifndef SHADER_MANAGER
#define SHADER_MANAGER

#include <string>
#include <fstream>
#include <streambuf>
#include <sstream> 

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "ErrorManager.h"
#include "Constant.h"

namespace Engine2
{
	class ShaderManager
	{

	private:
		static const GLuint UBO_BP = 0;
		GLuint VertexShaderId, FragmentShaderId, ProgramId;
		GLint ModelMatrix_UId, ViewMatrix_UId, ProjectionMatrix_UId, Color_UId;

		const std::string textFileRead(const std::string & fileName);
		const GLuint checkCompilation(const GLuint shader_id, const std::string & filename);
		void checkLinkage(const GLuint program_id);
		const GLuint addShader(const GLuint program_id, const GLenum shader_type, const std::string & filename);

	public:
		ShaderManager();
		void createShaderProgram(std::string& vs_file, std::string& fs_file);
		void destroyShaderProgram();
		GLint getProgramId();
		GLint getVertexShaderId();
		GLint getFragmentShaderId();
		GLint getModelMatrixId();
		GLint getViewMatrixId();
		GLint getProjectionMatrixId();
		GLint getColorId();
	};
}
#endif