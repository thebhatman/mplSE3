#ifndef _LINE_HPP_
#define _LINE_HPP_

#include "gl3w/gl3w.h"
#include "GLFW/glfw3.h"

#include "sprite/sline.hpp"

namespace sim {

class Line {
private:
   std::string _name;
   glm::vec3 _position_s;
   glm::vec3 _position_e;
   glm::vec3 _color;

public:
   inline glm::vec3 position_s() const { return _position_s; }
   inline glm::vec3 position_e() const { return _position_e; }
   inline glm::vec3 color()    const { return _color;    }

   Line();
   Line(std::string _name, glm::vec3 _position_s,
        glm::vec3 _position_e, glm::vec3 _color);

   void render(SLine &line);
};

} // namespace sim

#endif
