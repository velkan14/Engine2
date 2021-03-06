#pragma once
#ifndef CONSTANT
#define CONSTANT

#define DEGREES_TO_RADIANS 0.01745329251994329547
#define RADIANS_TO_DEGREES 57.29577951308232185913
#define M_UNITE 0.7071067811865475244f
#define M_PI 3.14159265358979323846f
#define M_SQRT2 1.41421356237309504880f

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

namespace Engine2
{
	struct Constant {
		static const int VERTICES = 0, TEXCOORDS = 1, NORMALS = 2, COLORS = 3;
	};
}


#endif // !CONSTANTS
