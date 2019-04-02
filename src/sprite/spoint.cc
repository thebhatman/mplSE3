#include "sprite/spoint.hpp"

namespace sim {

SPoint::SPoint(Shader &shader) : Sprite(shader) {
   init();
}

void SPoint::init() {
    float vertices[] = {
        // positions
        0.0f, 0.0f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);    
}

void SPoint::render(glm::vec3 position,
                    float size,
                    glm::vec3 color) {

    glm::mat4 model = glm::mat4(1,0,0,0,
                                0,1,0,0,
                                0,0,1,0,
                                0,0,0,1);
    model = glm::translate(model, position);

    _shader.use();
    _shader.setmat4("model", model);
    _shader.setvec3("color", color);
    _shader.setf("size", size);

    glBindVertexArray(_VAO);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
}

} // namespace sim
