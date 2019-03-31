#include <iostream>
#include <thread>

#include "scene.hpp"

using namespace sim;

int main() {

   Scene scene(1200, 600, "Simulator");

   std::thread _thread = std::thread(&Scene::render, scene);
   _thread.join();
}
