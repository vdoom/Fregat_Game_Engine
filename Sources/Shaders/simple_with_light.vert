#version 330 core

// матрица преобразования координат, получаемая из программы
//uniform mat4 modelViewProjectionMatrix;
uniform mat4 model;
uniform mat4 viewProjectionMatrix;
uniform mat4 view;
//uniform mat4 projection;

// входящие вершинные атрибуты
in vec4 in_Position;
in vec2 in_Texcoord;
in vec3 in_Normals;

// исходящие параметры, которые будут переданы в фрагментный шейдер
out vec2 fragTexcoord;
out vec3 normals;
out vec3 fragPos;

void main(void)
{
	// перевод позиции вершины из локальных координат в однородные
	gl_Position = (viewProjectionMatrix* view * model) * in_Position;//vec4(in_Position, 1.0);
	fragPos = vec3(model * vec4(vec3(in_Position), 1.0f));
	// передадим текстурные координаты в фрагментный шейдер
	fragTexcoord = in_Texcoord;
	//normals = in_Normals;
	normals = mat3(transpose(inverse(model))) * in_Normals; 
}
