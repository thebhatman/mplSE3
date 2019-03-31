#include "plane.hpp"

namespace sim {

Plane::Plane()
   : _name(""), _position(0.0f), _size(1.0f), 
     _color(1.0f, 1.0f, 1.0f), _texture() {}

Plane::Plane(std::string name, glm::vec3 position,
               glm::vec3 size, glm::vec3 color,
               Texture2D texture) :
   _name(name), _position(position), _size(size),
   _color(color), _texture(texture) {}

void Plane::render(SPlane &splane) {
   splane.render(_position,
                 _size,
                 _color,
                 _texture);
}

} // namespace sim
