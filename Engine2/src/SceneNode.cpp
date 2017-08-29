#include "SceneNode.h"

#include "MatFactory.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "Texture.h"
#include "Material.h"

using namespace Engine2;

SceneNode::SceneNode()
{
	modelMatrix = MatFactory::IdentityMat4();
	scaleMatrix = modelMatrix;
	visible = true;
	isUI = false;
}

SceneNode::~SceneNode()
{

}

void SceneNode::setParent(SceneNode * parent)
{
	parentNode = parent;
}

void SceneNode::setMesh(Mesh * mesh)
{
	_mesh = mesh;
}

void SceneNode::setTexture(Texture * texture)
{
	_texture = texture;
}

void SceneNode::setMaterial(Material * material)
{
	_material = material;
}

void SceneNode::setMatrix(mat4 transform)
{
	modelMatrix = transform;
}

void SceneNode::setScale(mat4 scale)
{
	scaleMatrix = scale;
}

void SceneNode::setShaderProgram(ShaderProgram * shader)
{
	shaderProgram = shader;
}

void SceneNode::setVisible(bool flag)
{
	visible = flag;
}

bool SceneNode::isVisible()
{
	return visible;
}

void SceneNode::setUI()
{
	isUI = true;
}

SceneNode * SceneNode::createNode()
{
	SceneNode* child = new SceneNode();
	child->setParent(this);
	child->setShaderProgram(shaderProgram);
	childrenNodes.push_back(child);
	return child;
}

SceneNode * SceneNode::copyNode()
{
	SceneNode* copy = new SceneNode();
	copy->setMesh(this->_mesh); 
	copy->setMaterial(this->_material); 
	copy->setShaderProgram(this->shaderProgram);
	copy->setTexture(this->_texture);  
	copy->setMatrix(this->modelMatrix);
	copy->setScale(this->scaleMatrix);
	return copy;
}

void SceneNode::addNode(SceneNode * child)
{
	child->setParent(this);
	childrenNodes.push_back(child);
}

void SceneNode::applyLTransform(mat4 transform)
{
	modelMatrix = transform * modelMatrix;
}

void SceneNode::applyRTransform(mat4 transform)
{
	modelMatrix = modelMatrix * transform;
}

void SceneNode::draw() 
{
	draw(MatFactory::IdentityMat4());
}

void SceneNode::draw(mat4 parentTransform)
{
	mat4 finalMatrix = parentTransform * modelMatrix;
	//TODO:
	if (visible && _mesh) {

		/*if (!isUI) {
			// Draw Silhouette
			glCullFace(GL_FRONT);
			silhouetteShader->BeginShader();
			meshObj->draw(silhouetteShader, finalMatrix * scaleMatrix); // Draw Mesh
			glCullFace(GL_BACK);
		}*/

		// Draw Object
		shaderProgram->BeginShader();

		if (_material) {
			_material->loadToShader(shaderProgram); // Load Material
			GLint NormalMatrix_UId = shaderProgram->getUniform("NormalMatrix");
			mat3 normalMatrix = transpose(inverse(MatFactory::Mat3FromMat4(finalMatrix)));

			GLfloat * m = MatFactory::GLMatrixFromMat3(normalMatrix);
			glUniformMatrix3fv(NormalMatrix_UId, 1, GL_TRUE, m);
		}

		if (_texture) {
			_texture->loadToShader(shaderProgram); // Load Texture
			_mesh->draw(shaderProgram, finalMatrix * scaleMatrix); // Draw Mesh
			_texture->unloadFromShader(shaderProgram); // Unload Texture
		}
		else {
			_mesh->draw(shaderProgram, finalMatrix * scaleMatrix); // Draw Mesh
		}

		shaderProgram->EndShader();
	}

	for (auto it = childrenNodes.begin(); it != childrenNodes.end(); ++it)
	{
		(*it)->draw(finalMatrix);
	}
}

void SceneNode::destroy()
{
	//FIXME
	for (auto it = childrenNodes.begin(); it < childrenNodes.end(); ++it)
	{
		(*it)->destroy();
	}
	childrenNodes.clear();
	_mesh = nullptr;
	shaderProgram = nullptr;
	parentNode = nullptr;
}

