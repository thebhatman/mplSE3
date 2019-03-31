#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <string>
#include <vector>
#include <map>

#include "shader.hpp"
#include "object.hpp"
#include "sprite.hpp"
#include "camera.hpp"
#include "texture.hpp"
#include "utils.hpp"
#include "sprite_plane.hpp"
#include "plane.hpp"

namespace sim {

class Scene {
private:
    int _width, _height;
    std::string _name;

    GLFWwindow *_window;
    GLFWwindow *_shared_window;

    Shader *shader;
    Sprite *sprite;
    SPlane *splane;

    // objects in the scene
    std::vector<Object*> _objects;

    // planes and walls in the scene
    std::vector<Plane*> _planes;

    // database of textures
    std::map<std::string, Texture2D> _textures;

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

    // openGL window callbacks
    static void scroll_callback(GLFWwindow *window, double dx, double dy);
    static void process_input(GLFWwindow *window);
    static void mouse_callback(GLFWwindow *window, double x_new, double y_new);
    static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

    // generate some random objects in the scene
    void generate_random_objects(size_t num=1);
};

} // namespace sim

#endif
