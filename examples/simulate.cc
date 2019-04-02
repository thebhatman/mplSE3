#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <thread>
#include <unistd.h>

#include "scene.hpp"
#include "plane.hpp"
#include "point.hpp"
#include "object.hpp"
#include "texture.hpp"

using namespace sim;

int main() {
    // Generate the scene (by default no objects are present)
    Scene *scene = new Scene(1200, 900, "Simulator");

    // Add cuboids
    std::vector<Object*> &_objects = scene->mutable_cubes();
    std::map<std::string, Texture2D> &_textures = scene->get_textures();
    _objects.push_back(
        new Object("cube1",
                   glm::vec3(-20.0f, 0.0f, 0.0f),  // center of cube
                   glm::vec3(5.0f, 5.0f, 5.0f), // size of cube
                   glm::vec3(1.0f, 1.0f, 1.0f),    // color
                   glm::vec3(0.0f, 0.0f, 0.0f),    // velocity
                   _textures["wall1"]              // texture to apply
                   )
        );
    _objects.push_back(
        new Object("cube2",
                   glm::vec3(40.0f, 40.0f, 0.0f),
                   glm::vec3(2.0f, 2.0f, 2.0f),
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   glm::vec3(0.0f, 0.0f, 0.0f),
                   _textures["wall2"]
                   )
        );
    _objects.push_back(
        new Object("cube3",
                   glm::vec3(0.0f, 0.0f, -30.0f),
                   glm::vec3(5.0f, 5.0f, 5.0f),
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   glm::vec3(0.0f, 0.0f, 0.0f),
                   _textures["wall3"]
                   )
        );

    // Add some points
    std::vector<Point*> &_points = scene->mutable_points();
    _points.push_back(
        new Point("point1",
                  glm::vec3(0.0f, 0.0f, 0.0f), // position
                  15.0f,                       // size
                  glm::vec3(1.0f, 0.0f, 0.0f)) // color
        );
    _points.push_back(
        new Point("point2",
                  glm::vec3(10.0f, 0.0f, 0.0f),
                  15.0f,
                  glm::vec3(0.0f, 1.0f, 0.0f))
        );
    _points.push_back(
        new Point("point3",
                  glm::vec3(20.0f, 0.0f, 0.0f),
                  15.0f,
                  glm::vec3(0.0f, 0.0f, 1.0f))
        );

    // Add some lines
    std::vector<Line*> &_lines = scene->mutable_lines();
    _lines.push_back(
        new Line("line1",
                 glm::vec3(0.0f, 0.0f, 0.0f), // starting point
                 glm::vec3(5.0f, 0.0f, 0.0f), // ending point
                 glm::vec3(1.0f, 0.0f, 0.0f)) // color
        );
    _lines.push_back(
        new Line("line2",
                 glm::vec3(0.0f, 0.0f, 0.0f),
                 glm::vec3(0.0f, 5.0f, 0.0f),
                 glm::vec3(0.0f, 1.0f, 0.0f))
        );
    _lines.push_back(
        new Line("line3",
                 glm::vec3(0.0f, 0.0f, 0.0f),
                 glm::vec3(0.0f, 0.0f, 5.0f),
                 glm::vec3(0.0f, 0.0f, 1.0f))
        );

    // Render the scene in a separate thread
    std::thread _thread = std::thread(&Scene::render, scene);

    usleep(10000000);

    scene->add_cube(
        new Object("cube4",
                   glm::vec3(0.0f, 0.0f, 50.0f),
                   glm::vec3(5.0f, 5.0f, 5.0f),
                   glm::vec3(1.0f, 1.0f, 1.0f),
                   glm::vec3(0.0f, 0.0f, 0.0f),
                   _textures["wall5"]
                   )
        );

    _thread.join();
}
