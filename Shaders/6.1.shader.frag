#version 330 core
in vec3 ourColor;
in vec2 ourTexCoord;

out vec4 color;

//���������
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
//�ı���������ɼ���
uniform float mixValue;

void main()
{
	//GLSL�ڽ���mix������Ҫ��������ֵ��Ϊ������
	//�������Ǹ��ݵ����������������Բ�ֵ��
	//���������ֵ��0.0�����᷵�ص�һ�����룻
	//�����1.0���᷵�صڶ�������ֵ��
	//0.2�᷵��80%�ĵ�һ��������ɫ��20%�ĵڶ���������ɫ����������������Ļ��ɫ��
	
	//color = mix(texture(ourTexture1, ourTexCoord),texture(ourTexture2, ourTexCoord),0.2);

	//������2��Ц�����ҿ�
	color = mix(texture(ourTexture1, ourTexCoord),texture(ourTexture2, vec2(1.0f - ourTexCoord.x, ourTexCoord.y)),mixValue);

	//������ɫ�붥����ɫ��˵õ������ɫ
	//color = vec4(color * vec4(ourColor, 1.0f));
}