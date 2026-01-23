#include "Resources.h"

int SCREEN_WIDTH = 800;
int SCREEN_HEIGHT = 600;
const char* title = "OpenGL learning";
GLFWwindow* window = nullptr;


// Game loop
const short FPS = 60;
const double timePerFrame = 1.0f / FPS;
const short UPS = 200;
const double timePerUpdate = 1.0f / UPS;