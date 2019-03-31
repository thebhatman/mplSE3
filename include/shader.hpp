#ifndef _SHADER_HPP_
#define _SHADER_HPP_

#include "gl3w/gl3w.h"
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

namespace sim {

class Shader {
public:
    unsigned int _id;

    Shader() {}
    Shader(const char *v_code, const char *f_code);

    Shader* use();

    void seti(const char *name, const int val) const;
    void setf(const char *name, const float val) const;
    void setmat4(const char *name, const glm::mat4 val) const;
    void setvec2(const char *name, const glm::vec2 val) const;
    void setvec3(const char *name, const glm::vec3 val) const;
    void setuniform(const char *name, const int binding_point) const;
};

} // namespace sim

#endif
