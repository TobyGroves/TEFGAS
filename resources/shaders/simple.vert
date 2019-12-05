#version 120
uniform mat4 in_Projection;
uniform mat4 in_Model;
uniform mat4 in_Position;
uniform mat4 in_View;

attribute vec4 in_Color;
attribute vec2 in_TexCoord;
attribute vec3 in_Normal;

varying vec4 ex_Color;
varying vec2 ex_TexCoord;
varying vec3 ex_FragPos;
varying vec3 ex_Normal;

void main()
{
  gl_Position = in_Projection * in_View * in_Model * vec4(in_Position, 1.0);
  ex_TexCoord = in_TexCoord;


  ex_Normal = mat3(in_Model) * in_Normal;
  ex_FragPos = vec3(in_Model * vec4(in_Position,1.0));
}
