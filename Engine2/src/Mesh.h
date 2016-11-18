#pragma once
#ifndef MESH
#define MESH


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "GL/glew.h"
#include "GL/freeglut.h"

#include "MatFactory.h"
#include "ErrorManager.h"
#include "MatrixStack.h"
#include "ShaderManager.h"
#include "Constant.h"

namespace Engine2
{
	class Mesh
	{

	private:

		std::vector <vec2> Texcoords, texcoordData;
		std::vector <vec3> Vertices, vertexData, Normals, normalData;
		std::vector <unsigned int> vertexIdx, texcoordIdx, normalIdx;

		GLuint VboVertices, VboTexcoords, VboNormals;

		MatrixStack * _matrixStack;
		ShaderManager * _shaderManager;

		bool TexcoordsLoaded, NormalsLoaded;		

		void parseVertex(std::stringstream & sin);
		void parseTexcoord(std::stringstream & sin);
		void parseNormal(std::stringstream & sin);
		void parseFace(std::stringstream & sin);
		void parseLine(std::stringstream & sin);

		void loadMeshData(std::string & filename);
		void processMeshData();

		void freeMeshData();
		

	public:
		
		GLuint VaoId;
		Mesh(ShaderManager * shaderManager, MatrixStack * matrixStack);
		const void createMesh(std::string & filename);
		void createBufferObjects();
		void destroyBufferObjects();
		void draw(const float r, const float g, const float b);
		~Mesh();
	};
	

}

#endif