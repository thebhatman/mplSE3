#ifndef _SPRITE_PLANE_HPP_
#define _SPRITE_PLANE_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "texture.hpp"
#include "shader.hpp"

namespace sim {

class SPlane {
private:
   Shader _shader;
   GLuint _VAO;

   void init();

public:
   SPlane(Shader &shader);
   ~SPlane();

   void render(glm::vec3 &position,
               glm::vec3 &size,
               glm::vec3 &color,
               Texture2D &texture);
};

} // namespace sim

#endif
