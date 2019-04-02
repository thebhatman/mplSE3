#version 330 core

layout (lines) in;
layout (line_strip, max_vertices = 2) out;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform vec3 point1;
uniform vec3 point2;

void main() {
    gl_Position = projection * view * model * vec4(point1, 1.0f);
    EmitVertex();

    gl_Position = projection * view * model * vec4(point2, 1.0f);
    EmitVertex();

    EndPrimitive();
}
