#version 330 core

uniform sampler2D colorTexture;

uniform vec3 viewPos;

in vec2 fragTexcoord;
in vec3 normals;
in vec3 fragPos;

out vec4 color;

void main(void)
{
	vec3 lightPos = viewPos;//vec3(30,20,10);
	vec3 lightColor = vec3(1,1,1);
	// Ambient
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * lightColor;
  	
    // Diffuse 
    vec3 norm = normalize(normals);
    vec3 lightDir = normalize(lightPos - fragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    // Specular
    float specularStrength = 0.5f;
    vec3 viewDir = normalize(viewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;  
        
	vec4 objectColor = texture(colorTexture, fragTexcoord);
    vec3 result = (ambient + diffuse + specular) * vec3(objectColor);
    color = vec4(result, objectColor.w);
	
}
