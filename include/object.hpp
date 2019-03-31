#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

namespace sim {

class Object {
private:
   std::string _name;
   glm::vec3 _position;
   glm::vec3 _size;
   glm::vec3 _color;
   glm::vec3 _velocity;

public:
   inline glm::vec3 position() const { return _position; }
   inline glm::vec3 size()     const { return _size;     }
   inline glm::vec3 color()    const { return _color;    }
   inline glm::vec3 velocity() const { return _velocity; }

   Object();
   Object

};

} // namespace sim

#endif
