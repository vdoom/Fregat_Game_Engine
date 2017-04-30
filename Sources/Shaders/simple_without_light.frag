#version 330 core

uniform sampler2D colorTexture;

in vec2 fragTexcoord;
in vec3 normals;

out vec4 color;

void main(void)
{
	color = texture(colorTexture, fragTexcoord);
	//color = vec4(normals, 1);
}
