#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "sprite.hpp"
#include "texture.hpp"

namespace sim {

class Object {
private:
   std::string _name;
   glm::vec3 _position;
   glm::vec3 _size;
   glm::vec3 _color;
   glm::vec3 _velocity;

   Texture2D _texture;

public:
   inline glm::vec3 position() const { return _position; }
   inline glm::vec3 size()     const { return _size;     }
   inline glm::vec3 color()    const { return _color;    }
   inline glm::vec3 velocity() const { return _velocity; }

   Object();
   Object(std::string _name, glm::vec3 _position,
          glm::vec3 _size, glm::vec3 _color,
          glm::vec3 _velocity,
          Texture2D texture);

   void render(Sprite &sprite);
};

} // namespace sim

#endif
