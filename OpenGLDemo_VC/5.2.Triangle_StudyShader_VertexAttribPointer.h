#pragma once
#include "3.Triangle.h"
class Triangle_StudyShader_VertexAttribPointer :
	public Triangle
{
public:
	Triangle_StudyShader_VertexAttribPointer();
	~Triangle_StudyShader_VertexAttribPointer();
protected:
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"layout(location = 1) in vec3 color;\n"
		"out vec3 ourColor;\n" //向片段着色器输出一个颜色
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0f);\n"
		"ourColor = color;\n"
		"}\n\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"in vec3 ourColor;\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(ourColor, 1.0f);\n"
		"}\n\0";
	void PrePareShader();
	void PrePareVAO();
};

