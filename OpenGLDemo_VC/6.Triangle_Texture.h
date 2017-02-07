#pragma once
#include "0.BaseDemo2.h"
class Triangle_Texture :
	public BaseDemo2
{
public:
	Triangle_Texture();
	~Triangle_Texture();
protected:
	void PrePareShader();
	void PrePareVAO();
	void Draw();
};

