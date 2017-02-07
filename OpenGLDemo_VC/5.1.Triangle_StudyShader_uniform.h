#pragma once
#include "3.Triangle.h"
class Triangle_StudyShader_uniform :
	public Triangle
{
public:
	Triangle_StudyShader_uniform();
	~Triangle_StudyShader_uniform();
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
		"out vec4 color;\n"
		"uniform vec4 ourColor;" //在OpenGL程序中设置这个变量
		"void main()\n"
		"{\n"
		"color = ourColor;\n"
		"}\n\0";
	void PrePareShader();
	void Draw();
};

