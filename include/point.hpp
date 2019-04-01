#ifndef _POINT_HPP_
#define _POINT_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "sprite/spoint.hpp"

namespace sim {

class Point {
private:
   std::string _name;
   glm::vec3 _position;
   float _size;
   glm::vec3 _color;

public:
   inline glm::vec3 position() const { return _position; }
   inline float size()     const { return _size;     }
   inline glm::vec3 color()    const { return _color;    }

   Point();
   Point(std::string _name, glm::vec3 _position,
         float _size, glm::vec3 _color);

   void render(SPoint &point);
};

} // namespace sim

#endif
