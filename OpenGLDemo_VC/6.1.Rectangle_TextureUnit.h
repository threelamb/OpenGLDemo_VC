#pragma once
#include "6.Rectangle_Texture.h"
class Rectangle_TextureUnit :
	public Rectangle_Texture
{
public:
	Rectangle_TextureUnit();
	~Rectangle_TextureUnit();
protected:
	void PrePareShader();
	void PrePareVAO();
	void PrePareTexture();
	void Draw();
	void AfterDraw();
};

