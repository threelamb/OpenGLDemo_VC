#include "stdafx.h"
#include "6.Triangle_Texture.h"


Triangle_Texture::Triangle_Texture()
{
}


Triangle_Texture::~Triangle_Texture()
{
}

void Triangle_Texture::PrePareShader()
{
	shader = new Shader("../Shaders/6.shader.vs", "../Shaders/6.shader.frag");
}

void Triangle_Texture::PrePareVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLfloat vertices[] = {
		// 位置              // 颜色
		0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
		0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
	};

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Triangle_Texture::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shader->Use();
	glUniform1f(glGetUniformLocation(shader->Program, "xOffset"), 0.3f);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
