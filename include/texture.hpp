#ifndef _TEXTURE_HPP_
#define _TEXTURE_HPP_

#include "stb_image.h"
#include "gl3w/gl3w.h"
#include <GLFW/glfw3.h>


namespace sim {

class Texture2D {
public:
    GLuint id;
    GLuint width, height;
    
    GLuint internal_format;
    GLuint image_format;

    GLuint wrap_s;
    GLuint wrap_t;

    GLuint filter_min;
    GLuint filter_max;

    Texture2D();

    void generate(GLuint width, GLuint height, unsigned char *data);

    void bind() const;
};

} // namespace sim

#endif
