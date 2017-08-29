#include "Material.h"

#include <fstream>
#include "vec.h"
#include "ShaderProgram.h"

namespace Engine2 {
	Material::Material(const std::string & filename) {
		ambientReflectivity = new vec3();
		diffuseReflectivity = new vec3();
		specularReflectivity = new vec3();
		emissiveReflectivity = new vec3();

		loadMaterialData(filename);
	}

	Material::~Material()
	{
	}

	std::string Material::MaterialName()
	{
		return materialName;
	}

	vec3* Material::Ka()
	{
		return ambientReflectivity;
	}

	vec3* Material::Kd()
	{
		return diffuseReflectivity;
	}

	vec3* Material::Ks()
	{
		return specularReflectivity;
	}

	vec3* Material::Ke()
	{
		return emissiveReflectivity;
	}

	float Material::Ns()
	{
		return specularExponent;
	}

	void Material::loadToShader(ShaderProgram * shader)
	{
		GLint Diffuse_UId = shader->getUniform("DiffuseReflectivity");
		glUniform3f(Diffuse_UId, diffuseReflectivity->x, diffuseReflectivity->y, diffuseReflectivity->z);

		GLint Specular_UId = shader->getUniform("SpecularReflectivity");
		glUniform3f(Specular_UId, specularReflectivity->x, specularReflectivity->y, specularReflectivity->z);

		GLint Exponent_UId = shader->getUniform("SpecularExponent");
		glUniform1f(Exponent_UId, specularExponent);
	}

	// Parsing
	void Material::loadMaterialData(const std::string & filename)
	{
		std::ifstream ifile(filename);
		while (ifile.good()) {
			std::string line;
			std::getline(ifile, line);
			parseLine(std::stringstream(line));
		}
	}

	void Material::parseLine(std::stringstream& sin)
	{
		std::string s;
		sin >> s;
		if (s.compare("newmtl") == 0) parseName(sin);
		else if (s.compare("Ns") == 0) parseExponent(sin);
		else if (s.compare("Ka") == 0) parseAmbient(sin);
		else if (s.compare("Kd") == 0) parseDiffuse(sin);
		else if (s.compare("Ks") == 0) parseSpecular(sin);
		else if (s.compare("Ke") == 0) parseEmissive(sin);
	}

	void Material::parseName(std::stringstream & sin)
	{
		sin >> materialName;
	}

	void Material::parseExponent(std::stringstream & sin)
	{
		sin >> specularExponent;
	}

	void Material::parseAmbient(std::stringstream & sin)
	{
		sin >> ambientReflectivity->x >> ambientReflectivity->y >> ambientReflectivity->z;
	}

	void Material::parseDiffuse(std::stringstream & sin)
	{
		sin >> diffuseReflectivity->x >> diffuseReflectivity->y >> diffuseReflectivity->z;
	}

	void Material::parseSpecular(std::stringstream & sin)
	{
		sin >> specularReflectivity->x >> specularReflectivity->y >> specularReflectivity->z;
	}

	void Material::parseEmissive(std::stringstream & sin)
	{
		sin >> emissiveReflectivity->x >> emissiveReflectivity->y >> emissiveReflectivity->z;
	}


}
