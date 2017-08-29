#include "Mesh.h"

#include <fstream>

#include "vec.h"
#include "mat.h"
#include "Constant.h"
#include "ErrorManager.h"
#include "MatFactory.h"
#include "MatrixStack.h"
#include "ShaderProgram.h"

namespace Engine2
{
	Mesh::Mesh(const std::string& filename)
	{
		TexcoordsLoaded = false;
		NormalsLoaded = false;

		loadMeshData(filename);
	}

	Mesh::~Mesh()
	{
		Vertices.clear();
		Texcoords.clear();
		Normals.clear();
	}

	void Mesh::parseVertex(std::stringstream& sin)
	{
		vec3 v;
		sin >> v;
		vertexData.push_back(v);
	}

	void Mesh::parseTexcoord(std::stringstream& sin)
	{
		vec2 t;
		sin >> t;
		texcoordData.push_back(t);
	}

	void Mesh::parseNormal(std::stringstream& sin)
	{
		vec3 n;
		sin >> n;
		normalData.push_back(n);
	}

	void Mesh::parseFace(std::stringstream& sin)
	{
		std::string token;
		for (int i = 0; i < 3; i++) {
			std::getline(sin, token, '/');
			if (token.size() > 0) vertexIdx.push_back(std::stoi(token));
			std::getline(sin, token, '/');
			if (token.size() > 0) texcoordIdx.push_back(std::stoi(token));
			std::getline(sin, token, ' ');
			if (token.size() > 0) normalIdx.push_back(std::stoi(token));
		}
	}

	void Mesh::parseLine(std::stringstream& sin)
	{
		std::string s;
		sin >> s;
		if (s.compare("v") == 0) parseVertex(sin);
		else if (s.compare("vt") == 0) parseTexcoord(sin);
		else if (s.compare("vn") == 0) parseNormal(sin);
		else if (s.compare("f") == 0) parseFace(sin);
	}

	void Mesh::loadMeshData(const std::string& filename)
	{
		std::ifstream ifile(filename);
		while (ifile.good()) {
			std::string line;
			std::getline(ifile, line);
			parseLine(std::stringstream(line));
		}
		TexcoordsLoaded = (texcoordIdx.size() > 0);
		NormalsLoaded = (normalIdx.size() > 0);
	}

	void Mesh::processMeshData()
	{
		for (unsigned int i = 0; i < vertexIdx.size(); i++) {
			unsigned int vi = vertexIdx[i];
			vec3 v = vertexData[vi - 1];
			Vertices.push_back(v);
			if (TexcoordsLoaded) {
				unsigned int ti = texcoordIdx[i];
				vec2 t = texcoordData[ti - 1];
				Texcoords.push_back(t);
			}
			if (NormalsLoaded) {
				unsigned int ni = normalIdx[i];
				vec3 n = normalData[ni - 1];
				Normals.push_back(n);
			}
		}
	}

	void Mesh::freeMeshData()
	{
		vertexData.clear();
		texcoordData.clear();
		normalData.clear();
		vertexIdx.clear();
		texcoordIdx.clear();
		normalIdx.clear();
	}

	const void Mesh::create()
	{
		processMeshData();
		freeMeshData();
		createBufferObjects();
	}

	void Mesh::createBufferObjects()
	{
		glGenVertexArrays(1, &VaoId);
		glBindVertexArray(VaoId);
		{
			glGenBuffers(1, &VboVertices);
			glBindBuffer(GL_ARRAY_BUFFER, VboVertices);
			glBufferData(GL_ARRAY_BUFFER, Vertices.size() * sizeof(GLfloat) * 3, &Vertices[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(Constant::VERTICES);
			glVertexAttribPointer(Constant::VERTICES, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, 0);
		}
		if (TexcoordsLoaded)
		{
			glGenBuffers(1, &VboTexcoords);
			glBindBuffer(GL_ARRAY_BUFFER, VboTexcoords);
			glBufferData(GL_ARRAY_BUFFER, Texcoords.size() * sizeof(GLfloat) * 2, &Texcoords[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(Constant::TEXCOORDS);
			glVertexAttribPointer(Constant::TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 2, 0);
		}
		if (NormalsLoaded)
		{
			glGenBuffers(1, &VboNormals);
			glBindBuffer(GL_ARRAY_BUFFER, VboNormals);
			glBufferData(GL_ARRAY_BUFFER, Normals.size() * sizeof(GLfloat) * 3, &Normals[0], GL_STATIC_DRAW);
			glEnableVertexAttribArray(Constant::NORMALS);
			glVertexAttribPointer(Constant::NORMALS, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, 0);
		}
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	void Mesh::destroyBufferObjects()
	{
		glBindVertexArray(VaoId);
		glDisableVertexAttribArray(Constant::VERTICES);
		glDisableVertexAttribArray(Constant::TEXCOORDS);
		glDisableVertexAttribArray(Constant::NORMALS);
		glDeleteBuffers(1, &VboVertices);
		glDeleteBuffers(1, &VboTexcoords);
		glDeleteBuffers(1, &VboNormals);
		glDeleteVertexArrays(1, &VaoId);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

	}

	//FIXME: REMOVE
	void Mesh::draw(ShaderProgram * shader, mat4 transform, const float r, const float g, const float b)
	{
		glBindVertexArray(VaoId);

		GLfloat v[3] = { r, g, b };
		glUniform3fv(shader->getUniform("Color"), 1, &v[0]);

		GLfloat * m = MatFactory::GLMatrixFromMat4(_matrixStack->getCurrentMatrix());
		glUniformMatrix4fv(shader->getUniform("ModelMatrix"), 1, GL_TRUE, m);
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)Vertices.size());
		delete m;
		glUseProgram(0);
		glBindVertexArray(0);

		ErrorManager::checkOpenGLError("ERROR: Could not draw scene.");
	}

	void Mesh::draw(ShaderProgram * shader, mat4 transform)
	{
		glBindVertexArray(VaoId);

		/*GLfloat v[3] = { 0.5, 0.5, 0.5 };
		glUniform3fv(shader->getUniform("Color"), 1, &v[0]); //FIXME*/

		GLint ModelMatrix_UId = shader->getUniform("ModelMatrix");

		GLfloat * m = MatFactory::GLMatrixFromMat4(transform);
		glUniformMatrix4fv(ModelMatrix_UId, 1, GL_TRUE, m);

		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)Vertices.size());
		glBindVertexArray(0);
	}

}