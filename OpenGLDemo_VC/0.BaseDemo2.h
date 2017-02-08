#pragma once
#define GLEW_STATIC
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h" //从文本文件中加载Shader
#include <SOIL\SOIL.h> //从图片文件中加载纹理

class BaseDemo2
{
public:
	BaseDemo2();
	~BaseDemo2();
	int Display();
	void Dispose();
protected:
	virtual void PrePareShader();
	virtual void PrePareVAO();
	virtual void PrePareTexture();
	virtual void Draw();
	virtual void AfterDraw();
	Shader* shader;
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	GLuint texture;
	GLuint* textures;
	// Function prototypes
	// 类中的回调函数需要定义成 static。
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
private:
	// Window dimensions
	const GLuint WIDTH = 800, HEIGHT = 600;
};

static GLfloat mixValue = 0.5f;
