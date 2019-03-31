#include "sprite.hpp"

namespace sim {

Sprite::Sprite(Shader &shader) : _shader(shader) {
   init();
}

void Sprite::init() {
    float vertices[] = {
      -0.5, -0.5, 0.0,
       0.5, -0.5, 0.0,
       0.0,  0.5, 0.0
    };
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::render(glm::vec3 position,
                    glm::vec3 size,
                    glm::vec3 color,
                    glm::vec3 velocity) {

    // TODO: Handle the above variables
    _shader.use();

    glm::mat4 model = glm::mat4(1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1);
    model = glm::translate(model, position);
    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.5f * size.z));
    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z));
    model = glm::scale(model, size);
    _shader.setmat4("model", model);

    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

} // namespace sim
