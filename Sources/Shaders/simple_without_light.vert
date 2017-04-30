#version 330 core

uniform mat4 model;
uniform mat4 viewProjectionMatrix;

in vec4 in_Position;
in vec2 in_Texcoord;
in vec3 in_Normals;

out vec2 fragTexcoord;
out vec3 normals;
//out vec3 fragPos;

void main(void)
{
	gl_Position = (viewProjectionMatrix*model) * in_Position;//vec4(in_Position, 1.0);
	//fragPos = vec3(model * vec4(in_Position, 1.0f));
	fragTexcoord = in_Texcoord;
	normals = in_Normals;
}
