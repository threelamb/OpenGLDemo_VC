#pragma once
#include "0.BaseDemo2.h"
class Rectangle_Texture :
	public BaseDemo2
{
public:
	Rectangle_Texture();
	~Rectangle_Texture();
protected:
	void PrePareShader();
	void PrePareVAO();
	void PrePareTexture();
	void Draw();
};

