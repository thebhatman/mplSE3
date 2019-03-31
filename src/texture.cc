#include "texture.hpp"

namespace sim {

Texture2D::Texture2D() {
    height = 0;
    width  = 0;

    internal_format = GL_RGB;
    image_format = GL_RGB;

    wrap_s = GL_REPEAT;
    wrap_t = GL_REPEAT;

    filter_min = GL_LINEAR;
    filter_max = GL_LINEAR;

    glGenTextures(1, &this->id);
}

void Texture2D::generate(GLuint width, GLuint height, unsigned char *data) {
    this->width  = width;
    this->height = height;

    glBindTexture(GL_TEXTURE_2D, this->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->wrap_s);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->wrap_t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->filter_min);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->filter_max);

    glTexImage2D(GL_TEXTURE_2D, 0, internal_format, width, height, 0, image_format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const {
    glBindTexture(GL_TEXTURE_2D, this->id);
}

} // namespace sim
