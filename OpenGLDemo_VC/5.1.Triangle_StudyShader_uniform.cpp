#include "stdafx.h"
#include "5.1.Triangle_StudyShader_uniform.h"


Triangle_StudyShader_uniform::Triangle_StudyShader_uniform()
{
}


Triangle_StudyShader_uniform::~Triangle_StudyShader_uniform()
{
}

void Triangle_StudyShader_uniform::PrePareShader()
{
	//1.������ɫ��
	GLuint vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//2.Ƭ����ɫ��
	GLuint fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//3.��ɫ���������
	shaderProgram = glCreateProgram();

	//����ɫ�����ӵ���ɫ���������
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}

	//ɾ����ɫ������
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Triangle_StudyShader_uniform::Draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat timeValue = glfwGetTime();
	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
	//������ɫ������
	glUseProgram(shaderProgram);
	//��shader����ȫ�ֱ���ֵ������uniform��ɫ
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	//����������
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
