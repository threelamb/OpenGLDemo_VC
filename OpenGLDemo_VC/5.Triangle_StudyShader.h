#pragma once
#include "3.Triangle.h"
class Triangle_StudyShader :
	public Triangle
{
public:
	Triangle_StudyShader();
	~Triangle_StudyShader();
protected:
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"out vec4 vertexColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position, 1.0);\n"
		"vertexColor = vec4(0.5f,0.0f,0.0f,1.0f);\n"
		"}\n\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"in vec4 vertexColor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vertexColor;\n"
		"}\n\0";
	void PrePareShader();
};

