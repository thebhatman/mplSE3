#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <string>
#include <vector>

#include "shader.hpp"
#include "object.hpp"
#include "sprite.hpp"
#include "camera.hpp"

namespace sim {

class Scene {
private:
    int _width, _height;
    std::string _name;

    GLFWwindow *_window;
    GLFWwindow *_shared_window;

    Shader *shader;
    Sprite *sprite;


    // objects in the scene
    std::vector<Object*> _objects;

public:
    Scene();
    Scene(int _width, int _height, std::string _name);

    int init();
    int render();

    // camera and its variables
    static Camera *camera;

    // key handler
    static GLboolean keys[1024];
    static bool first_mouse;
    static double x_last;
    static double y_last;
    static float last_frame;
    static float delta_time;

    static void scroll_callback(GLFWwindow *window, double dx, double dy);
    static void process_input(GLFWwindow *window);
    static void mouse_callback(GLFWwindow *window, double x_new, double y_new);
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);
};

} // namespace sim

#endif
