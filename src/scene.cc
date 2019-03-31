#include "scene.hpp"

namespace sim {

Camera *Scene::camera = new Camera(glm::vec3(30.0f, 30.0f, 0.0f));
GLboolean Scene::keys[1024];
bool Scene::first_mouse = true;
double Scene::x_last;
double Scene::y_last;
float Scene::last_frame = 0.0f;
float Scene::delta_time = 0.0f;

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
    glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSwapInterval(1);
    gl3wInit();

    // Load textures
    _textures["wall0"] = utils::load_texture_from_file("../textures/wall0.tga");
    _textures["wall1"] = utils::load_texture_from_file("../textures/wall1.tga");
    _textures["wall1"] = utils::load_texture_from_file("../textures/wall1.tga");
    _textures["wall2"] = utils::load_texture_from_file("../textures/wall2.tga");
    _textures["wall3"] = utils::load_texture_from_file("../textures/wall3.tga");
    _textures["wall4"] = utils::load_texture_from_file("../textures/wall4.tga");
    _textures["wall5"] = utils::load_texture_from_file("../textures/wall5.tga");
    _textures["wall6"] = utils::load_texture_from_file("../textures/marble.jpg");
    _textures["ground"] = utils::load_texture_from_file("../textures/ground.tga");
    _textures["grass"] = utils::load_texture_from_file("../textures/grass2.jpg");
}

int Scene::render() {
    glfwWindowHint(GLFW_VISIBLE, GL_TRUE);
    _shared_window = glfwCreateWindow(_width, _height, _name.c_str(), NULL, _window);
    glfwMakeContextCurrent(_shared_window);
    glfwSetWindowUserPointer(_shared_window, this);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // openGL callbacks
    glfwSetCursorPosCallback(_shared_window, Scene::mouse_callback);
    glfwSetScrollCallback(_shared_window, Scene::scroll_callback);
    glfwSetKeyCallback(_shared_window, Scene::key_callback);
    glfwSetErrorCallback([](int error, const char* description) {
     fprintf(stderr, "Error %d: %s\n", error, description);
    });

    if (_shared_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Create a simple shader
    shader = new Shader("../shaders/simple.vs",
                        "../shaders/simple.fs");

    // Sprite for rendering all objects
    sprite = new Sprite(*shader);

    // For rendering planes
    splane = new SPlane(*shader);

    // Add perspective projection
    GLfloat AR = (float)static_cast<float>(_width) / static_cast<float>(_height);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                            AR, 0.1f, 1000.0f);
    glm::mat4 view = camera->get_view_matrix();

    shader->use();
    shader->setmat4("projection", projection);
    shader->setmat4("view", view);

    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(_shared_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    while (!glfwWindowShouldClose(_shared_window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        process_input(_shared_window);

        // Update the scene with new events
        projection = glm::perspective(glm::radians(camera->zoom),
                                      AR,
                                      0.1f, 1000.0f);
        view = camera->get_view_matrix();

        shader->use();
        shader->setmat4("projection", projection);
        shader->setmat4("view", view);
        shader->seti("image", 0);

        // Render objects
        for (auto &obj: _objects) {
            obj->render(*sprite);
        }

        // Render planes and walls
        for (auto &_plane: _planes) {
            _plane->render(*splane);
        }

        glfwSwapBuffers(_shared_window);
        glfwPollEvents();
    }
}

void Scene::key_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    if (key >= 0 && key < 1024) {
    if (action == GLFW_PRESS)
        keys[key] = GL_TRUE;
    else if (action == GLFW_RELEASE)
        keys[key] = GL_FALSE;
    }
}

void Scene::mouse_callback(GLFWwindow *window, double x_new, double y_new) {
    if (first_mouse) {
        x_last = x_new;
        y_last = y_new;
        first_mouse = false;
    }
    float dx = x_new - x_last;
    float dy = y_last - y_new;
    x_last = x_new;
    y_last = y_new;

    camera->process_mouse_movement(dx, dy);
}

void Scene::process_input(GLFWwindow *window) {
    float current_frame = glfwGetTime();
    delta_time = current_frame - last_frame;
    last_frame = current_frame;
    float camera_speed = 2.5f * delta_time;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera->process_keyboard(FORWARD, delta_time);
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera->process_keyboard(BACKWARD, delta_time);
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera->process_keyboard(LEFT, delta_time);
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera->process_keyboard(RIGHT, delta_time);
}

void Scene::scroll_callback(GLFWwindow *window, double dx, double dy) {
    camera->process_scroll(dy);
}

void Scene::generate_random_objects(size_t num) {
    // Add cuboids
    for (int ii = 0; ii < num; ++ii) {
        Object *obj = new Object("cube",
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 glm::vec3(50.0f, 50.0f, 50.0f),
                                 glm::vec3(1.0f, 1.0f, 1.0f),
                                 glm::vec3(0.0f, 0.0f, 0.0f),
                                 _textures["wall6"]);
        _objects.push_back(obj);
    }

    // Add planes (walls and ground surface)
    Plane *plane = new Plane("ground",
                             glm::vec3(0.0f, 0.0f, 0.0f),
                             glm::vec3(500.0f, 1.0f, 500.0f),
                             glm::vec3(1.0f, 1.0f, 1.0f),
                             _textures["wall4"]);
    _planes.push_back(plane);

}

} // namespace sim
