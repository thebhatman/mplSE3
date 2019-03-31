#ifndef _SPRITE_HPP_
#define _SPRITE_HPP_

#include "shader.hpp"

namespace sim {

class Sprite {
private:
   Shader _shader;
   GLuint _VAO;

   void init();

public:
   Sprite(Shader &shader);
   ~Sprite();

   void render(glm::vec3 position,
               glm::vec3 size,
               glm::vec3 color,
               glm::vec3 velocity);
};

} // namespace sim

#endif
