#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform mat4 in_Model;
uniform mat4 in_View;
uniform mat4 in_Projection;

void main()
{
    TexCoords = aTexCoords;    
    gl_Position = in_Projection * in_View * in_Model *vec4(aPos, 1.0);
}

