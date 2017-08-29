#pragma once
#ifndef MATERIAL
#define MATERIAL

#include <string>

namespace Engine2
{
	struct vec3;
	class ShaderProgram;

	class Material
	{
	public:
		Material(const std::string & filename);
		~Material();

		std::string MaterialName();
		vec3* Ka();
		vec3* Kd();
		vec3* Ks();
		vec3* Ke();
		float Ns();

		void loadToShader(ShaderProgram* shader);

	private:
		std::string materialName;

		vec3* ambientReflectivity;
		vec3* diffuseReflectivity;
		vec3* specularReflectivity;
		vec3* emissiveReflectivity;
		float specularExponent;

		void loadMaterialData(const std::string& filename);
		void parseLine(std::stringstream& sin);
		void parseName(std::stringstream& sin);
		void parseExponent(std::stringstream& sin);
		void parseAmbient(std::stringstream& sin);
		void parseDiffuse(std::stringstream& sin);
		void parseSpecular(std::stringstream& sin);
		void parseEmissive(std::stringstream& sin);
	};
}

#endif