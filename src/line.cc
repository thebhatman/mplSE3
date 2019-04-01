#include "line.hpp"

namespace sim {

Line::Line()
   : _name(""), _position_s(0.0f, 0.0f, 0.0f),
     _position_e(1.0f, 0.0f, 0.0f),
     _size(1.0f), _color(1.0f, 1.0f, 1.0f) {}

Line::Line(std::string name, glm::vec3 position_s,
           glm::vec3 position_e, glm::vec3 color) :
   _name(name), _position_s(position_s), _position_e(position_e),
   _color(color) {}

void Line::render(SLine &line) {
    line.render(_position,
                 _size,
                 _color);
}

} // namespace sim
