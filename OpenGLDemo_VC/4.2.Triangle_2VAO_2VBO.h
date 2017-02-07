#pragma once
#include "3.Triangle.h"
class Triangle_2VAO_2VBO :
	public Triangle
{
public:
	Triangle_2VAO_2VBO();
	~Triangle_2VAO_2VBO();
protected:
	void PrePareVAO();
	void Draw();
	void AfterDraw();
};

