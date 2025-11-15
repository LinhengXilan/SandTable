#type vertex
#version 330 core

layout(location = 0) in vec3 a_position;
layout(location = 1) in vec4 a_color;

uniform mat4 u_ViewProjection;

out vec4 v_Position;

void main()
{
	v_Position = a_color;
	gl_Position = u_ViewProjection * vec4(a_position, 1.0f);
}


#type pixel
#version 330 core

layout(location = 0) out vec4 color;

in vec4 v_Position;

void main()
{
	color = v_Position;
}