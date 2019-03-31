#include "object.hpp"

namespace sim {

Object::Object()
   : _name(""), _position(0.0f), _size(1.0f), 
     _color(1.0f, 1.0f, 1.0f), _velocity(0.0f), _texture() {}

Object::Object(std::string name, glm::vec3 position,
               glm::vec3 size, glm::vec3 color,
               glm::vec3 velocity,
               Texture2D texture) :
   _name(name), _position(position), _size(size), _color(color),
   _velocity(velocity), _texture(texture) {}

void Object::render(Sprite &sprite) {
   sprite.render(_position,
                 _size,
                 _color,
                 _velocity,
                 _texture);
}

} // namespace sim
