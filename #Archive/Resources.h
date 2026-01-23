#ifndef RESOURCES_H
#define RESOUCES_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "Cube.h"


// GLFW Window
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern const char* title;
extern GLFWwindow* window;

// Game loop
extern const short FPS;
extern const double timePerFrame;
extern const short UPS;
extern const double timePerUpdate;


extern Cube cube;


#endif