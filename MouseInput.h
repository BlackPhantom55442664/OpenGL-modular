#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>

extern float lastX;
extern float lastY;

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);

#endif