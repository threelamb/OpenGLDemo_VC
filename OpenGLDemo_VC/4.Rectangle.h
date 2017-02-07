#pragma once
#include "3.Triangle.h"
class Rectangle :
	public Triangle
{
public:
	Rectangle();
	~Rectangle();
	int Display();
protected:
	void PrePareVAO();
	void Draw();
};

