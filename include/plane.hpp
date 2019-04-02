#ifndef _PLANES_HPP_
#define _PLANES_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "sprite/splane.hpp"
#include "texture.hpp"

namespace sim {

class Plane {
private:
   std::string _name;
   glm::vec3 _position;
   glm::vec3 _size;
   glm::vec3 _color;
   glm::vec3 _vector; // Rotate about this vector
   float _angle;      // ... by this angle (in degrees)
   Texture2D _texture;

public:
   inline glm::vec3 position() const { return _position; }
   inline glm::vec3 size()     const { return _size;     }
   inline glm::vec3 color()    const { return _color;    }

   Plane();
   Plane(std::string _name, glm::vec3 _position,
         glm::vec3 _size, glm::vec3 _color,
         Texture2D texture,
         float angle = 0.0f,
         glm::vec3 vector = glm::vec3(1.0f, 0.0f, 0.0f));

   void render(SPlane &splane);
};

} // namespace sim

#endif
