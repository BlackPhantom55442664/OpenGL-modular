#ifndef RESOURCES_H
#define RESOURCES_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "InitializeSystem.h"
#include "Shader.h"

#include<vector>

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern const char* SCREEN_TITLE;
extern GLFWwindow* window;


extern std::vector<GLfloat> verticesCube;
extern std::vector<GLfloat> vertices;
extern std::vector<GLuint> attributeSize;
extern std::vector<GLuint> indices;
//extern glm::vec3 cubePositions[];


extern GLuint VAO;
extern GLuint VBO;
extern GLuint EBO;

extern GLuint cubeVBO;


extern Shader shader;

#endif