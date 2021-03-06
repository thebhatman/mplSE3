#include "sprite/splane.hpp"

namespace sim {

SPlane::SPlane(Shader &shader) : Sprite(shader) {
   init();
}

void SPlane::init() {
    float vertices[] = {
        // positions          // texture
         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,

         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
         1.0f, -1.0f, -1.0f,  1.0f, 1.0f
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

void SPlane::render(Texture2D texture,
                   glm::vec3 position,
                   glm::vec3 size,
                   glm::vec3 color,
                   float angle,
                   glm::vec3 vector) {

    glm::mat4 model = glm::mat4(1,0,0,0,
                                0,1,0,0,
                                0,0,1,0,
                                0,0,0,1);
    model = glm::translate(model, position);
    model = glm::scale(model, size);
    model = glm::rotate(model, glm::radians(angle), vector);

    _shader.use();
    _shader.setmat4("model", model);
    _shader.setvec3("color", color);

    glActiveTexture(GL_TEXTURE0);
    texture.bind();

    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

} // namespace sim
