#ifndef RESOURCES_H
#define RESOURCES_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "InitializeGLFWsystem.h"
#include "Cube.h"
#include "Camera.h"
#include "Lighting.h"

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

// Window screen
extern GLFWwindow* window;
extern InitializeGLFWsystem initializer;


// Object
extern Camera camera;
extern Cube cube;
extern Light light;


// Camera
extern glm::mat4 cameraProjection;
extern glm::mat4 cameraView;

#endif // !RESOURCES_H
