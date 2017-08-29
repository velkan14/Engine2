#pragma once

#ifndef _DIRECTIONAL_LIGHT_
#define _DIRECTIONAL_LIGHT_

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace Engine2 {

	struct vec3;

	class DirectionalLight
	{
	public:

		DirectionalLight(vec3 * direction, vec3 * color, GLuint ubo_bp);
		~DirectionalLight();

	private:

		vec3 * lightDirection;
		vec3 * lightColor;

		GLuint bufferId;
	};
}
#endif
