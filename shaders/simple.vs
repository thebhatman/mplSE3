#version 330 core
layout (location = 0) in vec3 ipos;

uniform mat4 model;

void main() {
   gl_Position = model * vec4(ipos, 1.0f);
}
