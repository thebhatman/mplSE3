#include "plane.hpp"

namespace sim {

Plane::Plane()
   : _name(""), _position(0.0f), _size(1.0f), 
     _color(1.0f, 1.0f, 1.0f), _texture(), _angle(0.0f),
     _vector(1.0f, 0.0f, 0.0f) {}

Plane::Plane(std::string name, glm::vec3 position,
               glm::vec3 size, glm::vec3 color,
               Texture2D texture,
               float angle,
               glm::vec3 vector) :
   _name(name), _position(position), _size(size),
   _color(color), _texture(texture), _angle(angle),
   _vector(vector) {}

void Plane::render(SPlane &splane) {
   splane.render(_texture,
                 _position,
                 _size,
                 _color,
                 _angle,
                 _vector);
}

} // namespace sim
