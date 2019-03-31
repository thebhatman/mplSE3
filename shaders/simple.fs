#version 330 core
out vec4 frag_color;

in VS_OUT {
    vec2 tex;
} fs_in;

uniform sampler2D image;
uniform vec3 color;

void main() {
   frag_color = vec4(color, 1.0f) * texture(image, fs_in.tex);
}
