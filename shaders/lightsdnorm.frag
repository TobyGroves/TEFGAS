uniform sampler2D in_Texture;

uniform sampler2D in_NormalMap;



uniform mat4 in_Model;
uniform vec3 in_LightPos;
uniform vec3 in_LightColor;
uniform float in_shine;
uniform mat4 in_View;

uniform vec3 in_Ambient;

varying vec2 ex_TexCoord;
varying vec3 ex_FragPos;
varying vec3 ex_Normal;

void main()
{
   // ambient
    vec3 ambient = in_Ambient * in_LightColor;
  	
    // diffuse 
    vec3 norm = normalize(ex_Normal);
    vec3 lightDir = normalize(in_LightPos - ex_FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * in_LightColor;
    
    // specular
	vec4 viewPos = inverse(in_View) * vec4(0,0,0,1);
    float specularStrength = in_shine;
    vec3 viewDir = normalize(viewPos - ex_FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * in_LightColor;  
        
    vec3 result = (ambient + diffuse + specular) * texture2D(in_Texture, ex_TexCoord);
	gl_FragColor = vec4(result, 1.0);
}