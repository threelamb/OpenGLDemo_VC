#version 330 core
in vec3 ourColor;
in vec2 ourTexCoord;

out vec4 color;

//纹理采样器
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
//改变两个纹理可见度
uniform float mixValue;

void main()
{
	//GLSL内建的mix函数需要接受两个值作为参数，
	//并对它们根据第三个参数进行线性插值。
	//如果第三个值是0.0，它会返回第一个输入；
	//如果是1.0，会返回第二个输入值。
	//0.2会返回80%的第一个输入颜色和20%的第二个输入颜色，即返回两个纹理的混合色。
	
	//color = mix(texture(ourTexture1, ourTexCoord),texture(ourTexture2, ourTexCoord),0.2);

	//让纹理2的笑脸往右看
	color = mix(texture(ourTexture1, ourTexCoord),texture(ourTexture2, vec2(1.0f - ourTexCoord.x, ourTexCoord.y)),mixValue);

	//纹理颜色与顶点颜色相乘得到混合颜色
	//color = vec4(color * vec4(ourColor, 1.0f));
}