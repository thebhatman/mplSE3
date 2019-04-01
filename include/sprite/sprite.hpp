#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "shader.hpp"
#include "texture.hpp"

namespace sim {

class Sprite {
public:
    Shader _shader;
    GLuint _VAO;
    Sprite(Shader &shader);
    ~Sprite();

    virtual void init();
};

} // namespace sim

#endif
