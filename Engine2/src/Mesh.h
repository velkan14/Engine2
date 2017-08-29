#pragma once
#ifndef MESH
#define MESH

#include <vector>

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace Engine2
{
	struct vec2;
	struct vec3;
	struct mat4;
	class MatrixStack;
	class ShaderProgram;

	enum AttribType {
		VERTICES,
		TEXCOORDS,
		NORMALS,
		TANGENT,
		BITANGENT
	};

	class Mesh
	{

	private:
		
		bool TexcoordsLoaded, NormalsLoaded;

		std::vector <vec2> Texcoords, texcoordData;
		std::vector <vec3> Vertices, vertexData, Normals, normalData;
		std::vector <unsigned int> vertexIdx, texcoordIdx, normalIdx;

		GLuint VboVertices, VboTexcoords, VboNormals;

		MatrixStack * _matrixStack;

		void parseVertex(std::stringstream & sin);
		void parseTexcoord(std::stringstream & sin);
		void parseNormal(std::stringstream & sin);
		void parseFace(std::stringstream & sin);
		void parseLine(std::stringstream & sin);

		void loadMeshData(const std::string & filename);
		void processMeshData();

		void freeMeshData();
		

	public:
		
		GLuint VaoId;
		Mesh(const std::string& filename);
		~Mesh();
		const void create();
		void createBufferObjects();
		void destroyBufferObjects();
		void draw(ShaderProgram * shader, mat4 transform, const float r, const float g, const float b);
		void draw(ShaderProgram * shader, mat4 transform);
	};
	

}

#endif