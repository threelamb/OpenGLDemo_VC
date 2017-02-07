#include "stdafx.h"
#include "4.2.Triangle_2VAO_2VBO.h"


Triangle_2VAO_2VBO::Triangle_2VAO_2VBO()
{
}


Triangle_2VAO_2VBO::~Triangle_2VAO_2VBO()
{
}

void Triangle_2VAO_2VBO::PrePareVAO()
{
	// Set up vertex data (and buffer(s)) and attribute pointers
	// We add a new set of vertices to form a second triangle (a total of 6 vertices); the vertex attribute configuration remains the same (still one 3-float position vector per vertex)
	GLfloat firstTriangle[] = {
		-0.9f, -0.5f, 0.0f,  // Left 
		-0.0f, -0.5f, 0.0f,  // Right
		-0.45f, 0.5f, 0.0f,  // Top 
	};
	GLfloat secondTriangle[] = {
		0.0f, -0.5f, 0.0f,  // Left
		0.9f, -0.5f, 0.0f,  // Right
		0.45f, 0.5f, 0.0f   // Top 
	};
	VAOs = new GLuint[2];
	VBOs = new GLuint[2],
		glGenVertexArrays(2, VAOs); // We can also generate multiple VAOs or buffers at the same time
	glGenBuffers(2, VBOs);
	// ================================
	// First Triangle setup
	// ===============================
	glBindVertexArray(VAOs[0]);
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);	// Vertex attributes stay the same
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	// ================================
	// Second Triangle setup
	// ===============================
	glBindVertexArray(VAOs[1]);	// Note that we bind to a different VAO now
	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	// And a different VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0); // Because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out.
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}

void Triangle_2VAO_2VBO::Draw()
{
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(shaderProgram);
	glBindVertexArray(VAOs[0]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
	glBindVertexArray(VAOs[1]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Triangle_2VAO_2VBO::AfterDraw()
{
	glDeleteVertexArrays(2, VAOs);
	glDeleteBuffers(2, VBOs);
	delete VAOs;
	VAOs = NULL;
	delete VBOs;
	VBOs = NULL;
}
