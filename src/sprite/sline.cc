#include "sprite/sline.hpp"

namespace sim {

SLine::SLine(Shader &shader) : Sprite(shader) {
   init();
}

void SLine::init() {
    GLfloat vertices[] = {
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
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

void SLine::render(glm::vec3 position_s,
                   glm::vec3 position_e,
                   glm::vec3 size,
                   glm::vec3 color) {

    // // TODO: Handle rotation about an axis
    // glm::mat4 model = glm::mat4(1,0,0,0,
    //                             0,1,0,0,
    //                             0,0,1,0,
    //                             0,0,0,1);
    // model = glm::translate(model, position);
    // model = glm::translate(model, glm::vec3( 0.5f * size.x,  0.5f * size.y,  0.5f * size.z));
    // model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, -0.5f * size.z));
    // model = glm::scale(model, size);

    // _shader.use();
    // _shader.setmat4("model", model);
    // _shader.setvec3("color", color);

    // glBindVertexArray(_VAO);
    // glDrawArrays(GL_LINES, 0, 2);
    // glBindVertexArray(0);
}

} // namespace sim
