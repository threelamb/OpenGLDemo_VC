#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 color;

out vec3 ourColor;
//使用out关键字把顶点位置输出到片段着色器，并将片段的颜色设置为与顶点位置相等
out vec4 ourPosition;

uniform float xOffset;

/*
void main()
{
	//修改顶点着色器让三角形上下颠倒
	//使用uniform定义一个水平偏移量，在顶点着色器中使用这个偏移量把三角形移动到屏幕右侧
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
