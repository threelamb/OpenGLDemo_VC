#include "stdafx.h"
#include "1.HelloWindow.h"

HelloWindow::HelloWindow()
{
}


HelloWindow::~HelloWindow()
{
}

void HelloWindow::Draw()
{
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	/* Draw a triangle */
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 0.0, 0.0);    // Red
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);    // Green
	glVertex3f(-1.0, -1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);    // Blue
	glVertex3f(1.0, -1.0, 0.0);

	glEnd();
}

// Is called whenever a key is pressed/released via GLFW
// 要是线程函数不需要用到类成员的数据，或者从参数传入。则刻意声明为全局函数
void key_callback2(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

