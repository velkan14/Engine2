#include "ShaderManager.h"

#include <fstream>
#include <iostream>

#include "Constant.h"
#include "ErrorManager.h"

using namespace Engine2;

ShaderManager::ShaderManager() {
	ProgramId = 0;
}

void ShaderManager::createShaderProgram(std::string& vs_file, std::string& fs_file)
{
	bool TexcoordsLoaded = false, NormalsLoaded = true; //FIXME
	ProgramId = glCreateProgram();

	VertexShaderId = addShader(ProgramId, GL_VERTEX_SHADER, vs_file);
	FragmentShaderId = addShader(ProgramId, GL_FRAGMENT_SHADER, fs_file);

	glBindAttribLocation(ProgramId, Constant::VERTICES, "inPosition");
	if (TexcoordsLoaded)
		glBindAttribLocation(ProgramId, Constant::TEXCOORDS, "inTexcoord");
	if (NormalsLoaded)
		glBindAttribLocation(ProgramId, Constant::NORMALS, "inNormal");

	glLinkProgram(ProgramId);
	checkLinkage(ProgramId);

	Color_UId = glGetUniformLocation(ProgramId, "Color");
	ModelMatrix_UId = glGetUniformLocation(ProgramId, "ModelMatrix");
	ViewMatrix_UId = glGetUniformLocation(ProgramId, "ViewMatrix");
	ProjectionMatrix_UId = glGetUniformLocation(ProgramId, "ProjectionMatrix");

	ErrorManager::checkOpenGLError("ERROR: Could not create shaders.");
}

void ShaderManager::destroyShaderProgram()
{
	glUseProgram(0);
	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);

	glDeleteShader(FragmentShaderId);
	glDeleteShader(VertexShaderId);
	glDeleteProgram(ProgramId);

	ErrorManager::checkOpenGLError("ERROR: Could not destroy shaders.");
}

const std::string ShaderManager::textFileRead(const std::string & fileName) 
{
	std::ifstream ifile(fileName);
	std::string shader_string;
	while (ifile.good()) {
		std::string line;
		std::getline(ifile, line);
		shader_string += line + "\n";
	}
	return shader_string;
}

GLint ShaderManager::getProgramId() {
	return ProgramId;
}

GLint ShaderManager::getVertexShaderId() {
	return VertexShaderId;
}
GLint ShaderManager::getFragmentShaderId() {
	return FragmentShaderId;
}

GLint ShaderManager::getModelMatrixId()
{
	return ModelMatrix_UId;
}
GLint ShaderManager::getViewMatrixId()
{
	return ViewMatrix_UId;
}
GLint ShaderManager::getProjectionMatrixId()
{
	return ProjectionMatrix_UId;
}

GLint ShaderManager::getColorId()
{
	return Color_UId;
}
const GLuint ShaderManager::checkCompilation(const GLuint shader_id, const std::string& filename)
{
	GLint compiled;
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compiled);
	if (compiled == GL_FALSE) {
		GLint length;
		glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &length);
		GLchar* const log = new char[length];
		glGetShaderInfoLog(shader_id, length, &length, log);
		std::cerr << "[" << filename << "] " << std::endl << log;
		delete log;
	}
	return compiled;
}

void ShaderManager::checkLinkage(const GLuint program_id) {
	GLint linked;
	glGetProgramiv(program_id, GL_LINK_STATUS, &linked);
	if (linked == GL_FALSE) {
		GLint length;
		glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &length);
		GLchar* const log = new char[length];
		glGetProgramInfoLog(program_id, length, &length, log);
		std::cerr << "[LINK] " << std::endl << log << std::endl;
		delete log;
	}
}

const GLuint ShaderManager::addShader(const GLuint program_id, const GLenum shader_type, const std::string& filename)
{
	const GLuint shader_id = glCreateShader(shader_type);
	const std::string scode = textFileRead(filename);
	const GLchar* code = scode.c_str();
	glShaderSource(shader_id, 1, &code, 0);
	glCompileShader(shader_id);
	checkCompilation(shader_id, filename);
	glAttachShader(program_id, shader_id);
	return shader_id;
}