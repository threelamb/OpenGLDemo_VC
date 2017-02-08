#version 330 core
in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

//���������
uniform sampler2D ourTexture;

void main()
{
	//������ɫ
	//color = texture(ourTexture, TexCoord);

	//������ɫ�붥������˵õ������ɫ
	color = vec4(texture(ourTexture, TexCoord) * vec4(ourColor, 1.0f));
}