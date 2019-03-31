#include "scene.hpp"

namespace sim {

Scene::Scene() : _width(1), _height(1), _name("") {}

Scene::Scene(int _width, int _height, std::string _name) :
    _width(_width), _height(_height), _name(_name) {

    init();
}

int Scene::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    _window = glfwCreateWindow(1, 1, "", NULL, NULL);
    if (_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);   
    glfwSwapInterval(1);
    gl3wInit();
}

int Scene::render() {
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    _shared_window = glfwCreateWindow(_width, _height, _name.c_str(), NULL, _window);
    glfwMakeContextCurrent(_shared_window);
    glfwSetWindowUserPointer(_shared_window, this);

    if (_shared_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // TODO: Move it to sprite
    // Create a simple shader
    shader = new Shader("../shaders/simple.vs",
                        "../shaders/simple.fs");

    // Sprite for rendering all objects
    sprite = new Sprite(*shader);

    // Create a simple object
    Object *obj = new Object();
    _objects.push_back(obj);

    while (!glfwWindowShouldClose(_shared_window)) {

        for (auto &obj: _objects) {
            obj->render(*sprite);
        }

        glfwSwapBuffers(_shared_window);
        glfwPollEvents();
    }
}

} // namespace sim
