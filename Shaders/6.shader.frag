#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

//纹理采样器
uniform sampler2D ourTexture;

void main()
{
	//纹理颜色
	//color = texture(ourTexture, TexCoord);

	//纹理颜色与顶点颜相乘得到混合颜色
	color = vec4(texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f));
}