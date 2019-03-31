#include "utils.hpp"

namespace sim {

namespace utils {

Texture2D load_texture_from_file(const char *path) {
    Texture2D texture;

    int width, height, n_channels;
    unsigned char *data = stbi_load(path, 
                                    &width,
                                    &height,
                                    &n_channels,
                                    0);
    if (data) {
        GLuint format;
        if (n_channels == 1)
            format = GL_RED;
        else if (n_channels == 3)
            format = GL_RGB;
        else if (n_channels == 4)
            format = GL_RGBA;

        texture.internal_format = format;
        texture.image_format = format;
    } else {
        std::cout << "Couldn't load the texture image: "
                  << path << std::endl;
        exit(-1);
    }

    texture.generate(width, height, data);
    stbi_image_free(data);
    return texture;    
}

} // namespace utils

} // namespace sim
