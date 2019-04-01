#include "point.hpp"

namespace sim {

Point::Point()
   : _name(""), _position(0.0f), _size(1.0f), 
     _color(1.0f, 1.0f, 1.0f) {}

Point::Point(std::string name, glm::vec3 position,
               float size, glm::vec3 color) :
   _name(name), _position(position), _size(size),
   _color(color) {}

void Point::render(SPoint &point) {
    point.render(_position,
                 _size,
                 _color);
}

} // namespace sim
