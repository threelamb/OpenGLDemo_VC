#pragma once
#include "0.BaseDemo2.h"
class Triangle_ShaderInFile :
	public BaseDemo2
{
public:
	Triangle_ShaderInFile();
	~Triangle_ShaderInFile();
protected:
	void PrePareShader();
	void PrePareVAO();
	void Draw();
};

