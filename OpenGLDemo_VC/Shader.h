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
	//��ɫ������ID
	GLuint Program;
	Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
	//ʹ�ó���
	void Use();
};

#endif // !1


