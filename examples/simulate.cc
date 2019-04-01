#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <thread>

#include "scene.hpp"

using namespace sim;

int main() {
    // Generate the scene (by default no objects are present)
    Scene scene(1200, 900, "Simulator");

    // Add some random objects
    scene.generate_random_objects();

    // Render the scene in a separate thread
    std::thread _thread = std::thread(&Scene::render, scene);

    // Do any work here
    _thread.join();
}
