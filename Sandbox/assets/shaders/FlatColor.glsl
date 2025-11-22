#type vertex
#version 330 core

layout(location = 0) in vec3 a_position;

uniform mat4 u_ViewProjection;
uniform mat4 u_ModelTransform;

void main()
{
	gl_Position = u_ViewProjection * u_ModelTransform * vec4(a_position, 1.0f);
}


#type pixel
#version 330 core

layout(location = 0) out vec4 color;

uniform vec4 u_Color;

void main()
{
	color = u_Color;
}