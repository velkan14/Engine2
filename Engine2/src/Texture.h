#pragma once
#ifndef TEXTURE
#define TEXTURE

#include <string>

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace Engine2
{
	class ShaderProgram;
	class Texture
	{
	public:

		Texture(const std::string & filename);
		~Texture();

		void bind();
		void unbind();

		GLuint getTextureID();

		void loadToShader(ShaderProgram* shader);
		void unloadFromShader(ShaderProgram* shader);

	private:

		GLuint id;
		int channels;
		int width;
		int height;
		unsigned char *data;

		void load(const std::string & filename);
	};
}

#endif