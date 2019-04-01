#ifndef _SPRITE_LINE_HPP_
#define _SPRITE_LINE_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "shader.hpp"
#include "texture.hpp"
#include "sprite/sprite.hpp"

namespace sim {

class SLine : public Sprite {
public:
    SLine(Shader &shader);
    ~SLine();

    virtual void init() override;
    virtual void render(glm::vec3 position_s = glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3 position_e = glm::vec3(1.0f, 0.0f, 0.0f),
                        glm::vec3 size = glm::vec3(1.0f),
                        glm::vec3 color = glm::vec3(1.0f));
};

} // namespace sim

#endif
