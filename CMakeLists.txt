cmake_minimum_required(VERSION 3.0)

project(mplSE3)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
set(glm_DIR "/usr/local/include/glm")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(HEADERS "include")
include_directories(${HEADERS} ${glm_DIR})

set(LIBS glfw)
set(SRCS 
    src/glw3.c
    src/scene.cc
    src/shader.cc
    src/object.cc
    src/texture.cc
    src/utils.cc
    src/plane.cc
    src/point.cc
    src/line.cc
    src/sprite/scube.cc
    src/sprite/sline.cc
    src/sprite/splane.cc
    src/sprite/spoint.cc
    src/sprite/sprite.cc
    src/config.cc
    )

add_executable(simulator examples/simulate.cc ${SRCS})
target_link_libraries(simulator ${LIBS})
