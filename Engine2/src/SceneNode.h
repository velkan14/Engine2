#pragma once

#pragma once

#ifndef _SCENE_NODE_
#define _SCENE_NODE_

#include <vector>

#include "mat.h"

namespace Engine2
{
	class ShaderProgram;
	class Mesh;
	class Material;
	class Texture;

	class SceneNode
	{
	public:
		SceneNode();
		~SceneNode();

		void setParent(SceneNode * parent);

		void setMesh(Mesh* mesh);
		void setTexture(Texture* texture);
		void setMaterial(Material* material);

		void setMatrix(mat4 transform);
		//For independent scaling, if a scaling node propagation is desired, insert it into modelMatrix transform
		void setScale(mat4 scale);

		void setShaderProgram(ShaderProgram * shader);

		void setVisible(bool flag);
		bool isVisible();
		void setUI();

		SceneNode * createNode();
		SceneNode * copyNode();
		void addNode(SceneNode* child);
		void applyLTransform(mat4 transform);
		void applyRTransform(mat4 transform);

		virtual void draw();
		virtual void draw(mat4 parentTransform);

		void destroy();

	protected:
		SceneNode * parentNode;
		std::vector<SceneNode*> childrenNodes;

		Mesh* _mesh;
		Material* _material;
		Texture* _texture;

		mat4 modelMatrix;
		mat4 scaleMatrix;

		ShaderProgram * shaderProgram;

		bool isUI;
		bool visible;
	};
}
#endif
