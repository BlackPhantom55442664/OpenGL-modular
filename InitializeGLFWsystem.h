#ifndef INITIALIZE_GLFW_SYSTEM_H
#define INITIALIZE_GLFW_SYSTEM_H

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "Constant.h"

class InitializeGLFWsystem {
public: 
	inline InitializeGLFWsystem(GLFWwindow*& window) {
		initializeGLFW();
		window = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, title);
	}

	inline void initializeGLFW() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	inline void framebuffer_size_callback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
	inline GLFWwindow* createWindow(GLuint width, GLuint height, const char* title) {
		GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
		if (window == nullptr) std::cout << "Cannot create GLFWwindow" << std::endl;
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); });
		
		initializeGLAD();

		return window;
	}

	inline void initializeGLAD() {
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			std::cout << "Cannot load GLAD" << std::endl;
	}
};

#endif // !INITIALIZE_GLFW_SYSTEM_H
