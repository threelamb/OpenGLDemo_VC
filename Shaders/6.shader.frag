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
	//将片段的颜色设置为与顶点位置相等
	color = ourPosition;
}