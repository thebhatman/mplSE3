#ifndef _SPRITE_POINT_HPP_
#define _SPRITE_POINT_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "texture.hpp"
#include "shader.hpp"
#include "sprite/sprite.hpp"

namespace sim {

class SPoint : public Sprite {
public:
    SPoint(Shader &shader);
    ~SPoint();

    virtual void init() override;
    virtual void render(glm::vec3 position = glm::vec3(0.0f),
                        glm::vec3 size = glm::vec3(1.0f),
                        glm::vec3 color = glm::vec3(1.0f));
};

} // namespace sim

#endif
