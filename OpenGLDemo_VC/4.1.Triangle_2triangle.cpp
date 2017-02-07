#include "stdafx.h"
#include "4.1.Triangle_2triangle.h"


Triangle_2triangle::Triangle_2triangle()
{
}


Triangle_2triangle::~Triangle_2triangle()
{
}

void Triangle_2triangle::PrePareVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLfloat vertices[] = {
		//first triangle
		0.0f, 0.5f, 0.0f, //left
		0.5f, 0.5f, 0.0f, //right
		0.5f, -0.5f, 0.0f, //bottom
		//seconde trigangle
		-0.5f, -0.5f, 0.0f, //left
		0.0f, -0.5f, 0.0f, //right
		-0.5f, 0.5f, 0.0f, //top
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), (void*)vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Triangle_2triangle::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}
