#pragma once
#include "stdafx.h"
//GLEW
#define GLEW_STATIC
#include <GLEW\glew.h>
//GLFW
#include <GLFW\glfw3.h>

#include "0.BaseDemo.h";

class HelloWindow : public BaseDemo
{
public:
	HelloWindow();
	~HelloWindow();
private:
	void Draw();
};


