#include "sprite/sprite.hpp"

namespace sim {

Sprite::Sprite(Shader &shader)
    : _shader(shader) {
}

Sprite::~Sprite() {}

void Sprite::init() {}

} // namespace sim
