#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec3 ourColor;
//ʹ��out�ؼ��ְѶ���λ�������Ƭ����ɫ��������Ƭ�ε���ɫ����Ϊ�붥��λ�����
out vec4 ourPosition;

uniform float xOffset;

/*
void main()
{
	//�޸Ķ�����ɫ�������������µߵ�
	//ʹ��uniform����һ��ˮƽƫ�������ڶ�����ɫ����ʹ�����ƫ�������������ƶ�����Ļ�Ҳ�
	gl_Position = vec4(position.x + xOffset, -position.y, position.z, 1.0f);
	ourColor = color;
}
*/

void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0f);
	ourColor = color;
	ourPosition = gl_Position;
}
