#include<iostream>

#include "InitializeGLFW.h"
#include "Resources.h"

void processInput(GLFWwindow* window);
void update();
void render();

GLFWinitializer initializerGLFWSystem();
Cube cube;

void initializeObject() {
	
}

int main() {
	double currentRenderTime = glfwGetTime(), lastRenderTime = 0.0f;
	double currentUpdateTime = glfwGetTime(), lastUpdateTime = 0.0f;

	std::cout << "Time frame: " << timePerFrame << std::endl;
	std::cout << "Time update: " << timePerUpdate << std::endl;
	std::cout << "currentRenderTime: " << currentRenderTime << std::endl;

	double currentGameTime = glfwGetTime(), lastGameTime = 0.0f;
	while (!glfwWindowShouldClose(window)) {
		currentRenderTime = currentUpdateTime = glfwGetTime();

		static short updateCounter = 0;
		if (currentUpdateTime - lastUpdateTime >= timePerUpdate) {
			update();
			lastUpdateTime = currentUpdateTime;
			updateCounter++;
		}

		static short renderCounter = 0;
		if (currentRenderTime - lastRenderTime >= timePerFrame) {
			render();
			lastRenderTime = currentRenderTime;
			renderCounter++;
		}
		
		currentGameTime = glfwGetTime();
		if (currentGameTime - lastGameTime >= 1.0f) {
			std::cout << "FPS: " << renderCounter << "\tUPS: " << updateCounter << std::endl;
			lastGameTime = currentGameTime;
			renderCounter = updateCounter = 0;
		}
		
		//std::cout << currentGameTime - lastGameTime << std::endl;
	}
}

void processInput(GLFWwindow* window) {
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void update() {
	processInput(window);
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT);

	cube.render();

	glfwSwapBuffers(window);
}