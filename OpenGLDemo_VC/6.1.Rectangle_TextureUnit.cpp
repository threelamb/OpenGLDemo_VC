#include "stdafx.h"
#include "6.1.Rectangle_TextureUnit.h"


Rectangle_TextureUnit::Rectangle_TextureUnit()
{
}


Rectangle_TextureUnit::~Rectangle_TextureUnit()
{
}

void Rectangle_TextureUnit::PrePareShader()
{
	shader = new Shader("../Shaders/6.1.shader.vs", "../Shaders/6.1.shader.frag");
}

void Rectangle_TextureUnit::PrePareVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//�޸��������꣺�����ӵĽ������4��Ц��
	GLfloat vertices[] = {
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
		0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // ����
		0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // ����
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // ����
	};

	////�޸��������꣺�����ӵĽ������4��Ц��
	//GLfloat vertices[] = {
	//	//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
	//	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   2.0f, 2.0f,   // ����
	//	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   2.0f, 0.0f,   // ����
	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 2.0f    // ����
	//};

	////�޸��������꣺ֻ��ʾ����ͼ����м�һ����
	//GLfloat vertices[] = {
	//	//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
	//	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.6f, 0.6f,   // ����
	//	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.6f, 0.4f,   // ����
	//	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.4f, 0.4f,   // ����
	//	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.4f, 0.6f    // ����
	//};

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

void Rectangle_TextureUnit::PrePareTexture()
{
	int width, height;
	unsigned char* image;
	textures = new GLuint[2];
	glGenTextures(2, textures);
	/*--���õ�һ������--*/
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	//�����Ʒ�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//�������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//���ز���������
	image = SOIL_load_image("../Texture/container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//�Զ����ɶ༶��Զ����
	glGenerateMipmap(GL_TEXTURE_2D);
	//�ͷ�ͼ����ڴ沢����������
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);

	/*--���õڶ�������--*/
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	//�����Ʒ�ʽ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);*/

	//�������
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	//���ز���������
	image = SOIL_load_image("../Texture/awesomeface.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	//�Զ����ɶ༶��Զ����
	glGenerateMipmap(GL_TEXTURE_2D);
	//�ͷ�ͼ����ڴ沢����������
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Rectangle_TextureUnit::Draw()
{
	// Render
	// Clear the colorbuffer
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shader->Use();

	//�����һ������Ԫ
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glUniform1i(glGetUniformLocation(shader->Program, "ourTexture1"), 0);

	//����ڶ�������Ԫ
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glUniform1i(glGetUniformLocation(shader->Program, "ourTexture2"), 1);

	//��������mix�����Ŀɼ���
	glUniform1f(glGetUniformLocation(shader->Program, "mixValue"), mixValue);

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void Rectangle_TextureUnit::AfterDraw()
{
	delete textures;
	textures = NULL;
}
