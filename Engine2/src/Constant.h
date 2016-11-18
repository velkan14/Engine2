#pragma once
#ifndef CONSTANT
#define CONSTANT

#define DEGREES_TO_RADIANS 0.01745329251994329547f
#define RADIANS_TO_DEGREES 57.29577951308232185913f

#define VALUE_100 1.0f
#define VALUE_90 230.0f / 255.0f
#define VALUE_80 204.0f / 255.0f
#define VALUE_70 179.0f / 255.0f
#define VALUE_60 153.0f / 255.0f
#define VALUE_50 128.0f / 255.0f
#define VALUE_40 102.0f / 255.0f
#define VALUE_30 77.0f / 255.0f
#define VALUE_20 51.0f / 255.0f
#define VALUE_10 26.0f / 255.0f
#define VALUE_0 0.0f

#define M_PI 3.14159265358979323846f
#define M_SQRT2 1.41421356237309504880f
#define M_UNITE 0.07071067811865475244f

namespace Engine2
{
	struct Constant {
		/*const float VALUE_100 = 1.0f;
		const float VALUE_90 = 230.0f / 255.0f;
		const float VALUE_80 = 204.0f / 255.0f;
		const float VALUE_70 = 179.0f / 255.0f;
		const float VALUE_60 = 153.0f / 255.0f;
		const float VALUE_50 = 128.0f / 255.0f;
		const float VALUE_40 = 102.0f / 255.0f;
		const float VALUE_30 = 77.0f / 255.0f;
		const float VALUE_20 = 51.0f / 255.0f;
		const float VALUE_10 = 26.0f / 255.0f;
		const float VALUE_0 = 0.0f;*/

		static const int VERTICES = 0, TEXCOORDS = 1, NORMALS = 2, COLORS = 3;
	};
}


#endif // !CONSTANTS
