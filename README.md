# Motion planning in SE(3)

---

## Requirements
- gl3w (window management)
- glm (shader maths)
- glfw (window management)
- openGL (rendering scene)
- ompl (motion planning)
- C++14

## Usage
Install openGL, glm, glfw

Building the project
```
git clone https://github.com/kvmanohar22/mplSE3.git
cd mplSE3
mkdir build
cd build
cmake ..
``` 

To render a simple scene
```
cd build
./simulator
``` 


## New features to be added
- [ ] Moving camera along a trajectory
- [ ] Antialiasing
- [ ] Organize resources in a better way (textures & shaders)
