#version 330 core
in vec3 ourColor;
in vec4 ourPosition;

out vec4 color;

/*
void main()
{
    color = vec4(ourColor, 1.0f);
}
*/

void main()
{
	//��Ƭ�ε���ɫ����Ϊ�붥��λ�����
	color = ourPosition;
}