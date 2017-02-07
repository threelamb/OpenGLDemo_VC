#pragma once
#include "3.Triangle.h"
class Triangle_2triangle :
	public Triangle
{
public:
	Triangle_2triangle();
	~Triangle_2triangle();
protected:
	void PrePareVAO();
	void Draw();
};

