#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <string>

#include "shader.hpp"

namespace sim {

class Scene {
private:
    int _width, _height;
    std::string _name;

    GLFWwindow *_window;
    GLFWwindow *_shared_window;

    Shader *shader;

public:
    Scene();
    Scene(int _width, int _height, std::string _name);

    int init();
    int render();
};

} // namespace sim

#endif
