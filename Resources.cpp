#include "Resources.h"

// Window screen
GLFWwindow* window;
InitializeGLFWsystem initializer(window);

// Object 
Cube cube;
Camera camera;
Light light;

// Camera
glm::mat4 cameraProjection = glm::mat4(1.0f);
glm::mat4 cameraView = glm::mat4(1.0f);