#version 330 core

in vec3 exPosition;
in vec2 exTexcoord;
in vec3 exNormal;
in vec3 exColor;

out vec4 FragmentColor;

void main(void)
{
	//vec3 color = vec3(1.0);
	//vec3 color = (exPosition + vec3(1.0)) * 0.5;
	//vec3 color = vec3(exTexcoord, 0.0);
	//vec3 color = (exNormal + vec3(1.0)) * 0.5;
	vec3 color = exColor + exNormal;
	//FragmentColor = vec4(color,1.0);

	vec3 N = normalize(exNormal);
	vec3 direction = vec3(1.0, 0.5, 0.25);
	float intensity = max(dot(direction, N), 0.0);
	if (intensity == 0) intensity = 0.1; 
	FragmentColor = vec4(vec3(intensity) * color, 1.0);
}

//vec3 N = normalize(exNormal);
//vec3 direction = vec3(1.0, 0.5, 0.25);
//float intensity = max(dot(direction, N), 0.0);
//FragmentColor = vec4(vec3(intensity), 1.0);
