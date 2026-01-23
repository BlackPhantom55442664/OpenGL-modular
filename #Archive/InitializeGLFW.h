#ifndef INITIALIZE_GLFW_H
#define INITIALIZE_GLFW_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "Resources.h"

inline void initializeGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

inline void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
inline GLFWwindow* createWindow(GLuint width, GLuint height, const char* title) {
	GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == nullptr) std::cout << "Cannot create GLFWwindow" << std::endl;
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		std::cout << "Cannot load GLAD" << std::endl;

	return window;
}

class GLFWinitializer {
public:
	inline GLFWinitializer() {
		initializeGLFW();
		window = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
	}
};



#endif