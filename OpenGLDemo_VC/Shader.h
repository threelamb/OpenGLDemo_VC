#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define GLEW_STATIC
#include <GLEW\glew.h>
class Shader
{
public:
	Shader();
	~Shader();
	//着色器程序ID
	GLuint Program;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	//使用程序
	void Use();
};

#endif // !1


