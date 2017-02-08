#include "stdafx.h"
#include "6.Rectangle_Texture.h"

Rectangle_Texture::Rectangle_Texture()
{
}


Rectangle_Texture::~Rectangle_Texture()
{
}

void Rectangle_Texture::PrePareShader()
{
	shader = new Shader("../Shaders/6.shader.vs", "../Shaders/6.shader.frag");
}

void Rectangle_Texture::PrePareVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	GLfloat vertices[] = {
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
	};
	GLuint indices[] = {  // Note that we start from 0!
		0, 1, 3,  // First Triangle
		1, 2, 3   // Second Triangle
	};
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
	glBindVertexArray(0);
}

void Rectangle_Texture::PrePareTexture()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	//加载并生成纹理
	int width, height;
	unsigned char* image = SOIL_load_image("../Texture/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	
	//自动生成多级渐远纹理
	glGenerateMipmap(GL_TEXTURE_2D);

	//释放图像的内存并解绑纹理对象
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Rectangle_Texture::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shader->Use();
	//glUniform1f(glGetUniformLocation(shader->Program, "xOffset"), 0.3f);
	glBindTexture(GL_TEXTURE_2D, texture);//纹理需要显示调用
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}
