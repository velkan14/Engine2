#include "MatrixStack.h"

namespace Engine2
{
	void MatrixStack::loadIdentity() 
	{
		stack.clear();
		stack.push_back(MatFactory::createIdentityMat4());
	}
	void MatrixStack::pushMatrix() 
	{
		mat4 m = stack.back();
		stack.push_back(m);
	}

	void MatrixStack::popMatrix()
	{
		stack.pop_back();
	}

	void MatrixStack::translate(const vec3 & v)
	{
		translate(v.x, v.y, v.z);
	}
	void MatrixStack::translate(const float x, const float y, const float z)
	{
		mat4 m =  stack.back() * MatFactory::createTranslationMat4(x, y, z);
		stack.pop_back();
		stack.push_back(m);
	}
	void MatrixStack::scale(const vec3 & v)
	{
		scale(v.x, v.y, v.z);
	}
	void MatrixStack::scale(const float x, const float y, const float z)
	{
		mat4 m = stack.back() * MatFactory::createScaleMat4(x, y, z);
		stack.pop_back();
		stack.push_back(m);
	}

	void MatrixStack::rotate(vec3 axis, float angle)
	{
		rotate(angle, axis);
	}

	void MatrixStack::rotate(float angle, vec3 axis)
	{
		rotate(qtrn(angle, axis));
		/*mat4 m = stack.back() * MatFactory::createRotationMat4(axis, angle);
		mat4 m = stack.back() * MatFactory::createMat4FromQuaternion(q);
		stack.pop_back();
		stack.push_back(m);*/
	}
	void MatrixStack::rotate(qtrn q)
	{
		mat4 m = stack.back() * MatFactory::createMat4FromQuaternion(q);
		stack.pop_back();
		stack.push_back(m);
	}

	mat4 MatrixStack::getCurrentMatrix()
	{
		return stack.back();
	}
}