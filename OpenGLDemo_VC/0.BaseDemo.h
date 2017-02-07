#pragma once
//GLEW
#define GLEW_STATIC
#include <GLEW\glew.h>
//GLFW
#include <GLFW\glfw3.h>

class BaseDemo
{
private:
	virtual void PrePareShader();
	virtual void PrePareVAO();
	virtual void Draw();
	virtual void AfterDraw();
protected:
	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	GLuint* VAOs;
	GLuint* VBOs;
	GLuint shaderProgram;
	const GLchar* vertexShaderSource = "#version 330 core\n"
		"layout(location = 0) in vec3 position;\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
		"}\n\0";

	const GLchar* fragmentShaderSource = "#version 330 core\n"
		"out vec4 color;\n"
		"void main()\n"
		"{\n"
		"color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
		"}\n\0";
	// Window dimensions
	const GLuint WIDTH = 800, HEIGHT = 600;
	// Function prototypes
	// ���еĻص�������Ҫ����� static��
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
public:
	BaseDemo();
	~BaseDemo();
	void Dispose();
	int Display();
};

// Is called whenever a key is pressed/released via GLFW
// Ҫ���̺߳�������Ҫ�õ����Ա�����ݣ����ߴӲ������롣���������Ϊȫ�ֺ���
void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mode);

