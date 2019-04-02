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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);    
}

void SLine::render(glm::vec3 position_s,
                   glm::vec3 position_e,
                   glm::vec3 color) {

    /*
        1. Rotate about x-axis
        2. Translate to the first point
        3. Scale
    */
    glEnable(GL_LINE_WIDTH);
    glLineWidth(10);
    glm::mat4 model = glm::mat4(1,0,0,0,
                                0,1,0,0,
                                0,0,1,0,
                                0,0,0,1);
    _shader.use();
    _shader.setmat4("model", model);
    _shader.setvec3("color", color);
    _shader.setvec3("point1", glm::vec3(0.0f, 0.0f, 0.0f));
    _shader.setvec3("point2", glm::vec3(100.0f, 0.0f, 0.0f));

    glBindVertexArray(_VAO);
    glDrawArrays(GL_LINES, 0, 2);
    glBindVertexArray(0);
    glDisable(GL_LINE_WIDTH);
}

} // namespace sim
