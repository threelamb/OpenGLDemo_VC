#pragma once
#define GLEW_STATIC
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "Shader.h" //���ı��ļ��м���Shader
#include <SOIL\SOIL.h> //��ͼƬ�ļ��м�������

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
	// ���еĻص�������Ҫ����� static��
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
private:
	// Window dimensions
	const GLuint WIDTH = 800, HEIGHT = 600;
};

static GLfloat mixValue = 0.5f;
