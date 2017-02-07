#pragma once
#include "0.BaseDemo.h"
class Triangle_2ShaderProgram :
	public BaseDemo
{
public:
	Triangle_2ShaderProgram();
	~Triangle_2ShaderProgram();
	int Display();

protected:
	// Shaders
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\0";
	const GLchar* fragmentShader1Source = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	const GLchar* fragmentShader2Source = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 1.0f, 0.0f, 1.0f); // The color yellow \n"
		"}\n\0";
};

