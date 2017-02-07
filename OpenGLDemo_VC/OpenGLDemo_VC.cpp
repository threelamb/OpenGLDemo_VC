#include "stdafx.h"
#include "OpenGLDemo_VC.h"
#include "1.HelloWindow.h"
#include "2.Triangle_OldAPI.h"
#include "3.Triangle.h"
#include "TestDemo.h"
#include "4.Rectangle.h"
#include "4.1.Triangle_2triangle.h"
#include "4.2.Triangle_2VAO_2VBO.h"
#include "4.3.Triangle_2ShaderProgram.h"
#include "5.Triangle_StudyShader.h"
#include "5.1.Triangle_StudyShader_uniform.h"
#include "5.2.Triangle_StudyShader_VertexAttribPointer.h"
#include "5.3.Triangle_ShaderInFile.h";
#include "6.Triangle_Texture.h"

void Display_HelloWindow();
void Display_Triangle_OldAPI();
void Display_Triangle();
void Display_TestDemo();
void Display_Rectangle();
void Display_Triangle_2triangle();
void Display_Triangle_2VAO_2VBO();
void Display_Triangle_2ShaderProgram();
void Display_Triangle_StudyShader();
void Display_Triangle_StudyShader_uniform();
void Display_Triangle_StudyShader_VertexAttribPointer();
void Display_Triangle_ShaderInFile();
void Display_Triangle_Texture();
// The MAIN function, from here we start the application and run the game loop
int main()
{
	Display_Triangle_Texture();
	return 0;
}

void Display_HelloWindow()
{
	HelloWindow* obj = new HelloWindow();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_OldAPI()
{
	Triangle_OldAPI* obj = new Triangle_OldAPI();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle()
{
	Triangle* obj = new Triangle();
	obj->Display();
	obj->Dispose();
}

void Display_TestDemo()
{
	TestDemo* obj = new TestDemo();
	obj->Display();
	obj->Dispose();
}

void Display_Rectangle()
{
	Rectangle* obj = new Rectangle();
	((BaseDemo*)obj)->Display();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_2triangle()
{
	Triangle_2triangle* obj = new Triangle_2triangle();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_2VAO_2VBO()
{
	Triangle_2VAO_2VBO* obj = new Triangle_2VAO_2VBO();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_2ShaderProgram()
{
	Triangle_2ShaderProgram* obj = new Triangle_2ShaderProgram();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_StudyShader()
{
	Triangle_StudyShader* obj = new Triangle_StudyShader();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_StudyShader_uniform()
{
	Triangle_StudyShader_uniform* obj = new Triangle_StudyShader_uniform();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_StudyShader_VertexAttribPointer()
{
	Triangle_StudyShader_VertexAttribPointer* obj = new Triangle_StudyShader_VertexAttribPointer();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_ShaderInFile()
{
	Triangle_ShaderInFile* obj = new Triangle_ShaderInFile();
	obj->Display();
	obj->Dispose();
}

void Display_Triangle_Texture()
{
	Triangle_Texture* obj = new Triangle_Texture();
	obj->Display();
	obj->Dispose();
}

