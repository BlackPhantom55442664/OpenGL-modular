#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "Resources.h"
#include "Constant.h"
#include "utils.h"

void processInput(GLFWwindow* window);
void update();
void render();


int main() {
	GLdouble lastUpdateTime = 0, currentUpdateTime;
	GLdouble lastFrameTime = 0, currentFrameTime;
	GLdouble lastTime = 0, currentTime;

	std::cout << "Setting: \t" << "FPS: " << FPS << "\t" << "UPS: " << UPS << std::endl;

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, [](GLFWwindow * window, GLdouble xPos, GLdouble yPos) {	
		static bool firstMouse = true;
		if (firstMouse) {
			camera.lastX = xPos;
			camera.lastY = yPos;
			firstMouse = false;
		}

		GLfloat xOffset = xPos - camera.lastX;
		GLfloat yOffset = camera.lastY - yPos;
		camera.lastX = xPos;
		camera.lastY = yPos;


		// Update mouse position
		xOffset *= camera.sensitivity, yOffset *= camera.sensitivity;
		camera.yaw += xOffset, camera.pitch += yOffset;

		// Limit the pitch angle
		camera.pitch = camera.pitch > 89.0f ? 89.0f : camera.pitch;
		camera.pitch = camera.pitch < -89.0f ? -89.0f : camera.pitch;

		// Update looking direction
		camera.front.x = glm::cos(glm::radians(camera.yaw)) * glm::cos(glm::radians(camera.pitch));
		camera.front.y = glm::sin(glm::radians(camera.pitch));
		camera.front.z = glm::sin(glm::radians(camera.yaw)) * glm::cos(glm::radians(camera.pitch));
		camera.front = glm::normalize(camera.front);
	});

	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window)) {
		currentFrameTime = currentUpdateTime = currentTime = glfwGetTime();

		static short frameCounter = 0;
		if (currentFrameTime - lastFrameTime >= timePerFrame) {
			render();
			lastFrameTime = currentFrameTime;
			frameCounter++;
		}

		static short updateCounter = 0;
		if (currentUpdateTime - lastUpdateTime >= timePerUpdate) {
			update();
			lastUpdateTime = currentUpdateTime;
			updateCounter++;
		}

		if (currentTime - lastTime >= 1.0f) {
			std::cout << "FPS: " << frameCounter << "\tUPS: " << updateCounter << std::endl;
			frameCounter = updateCounter = 0;
			lastTime = currentTime;
		}
	}
}

void processInput(GLFWwindow* window) {
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void update() {
	processInput(window);
	camera.update(window);

	//GLuint cubeShader = cube.getShader();

	setShaderCameraUniform(cube.getShader(), camera.getProjection(), camera.getView());
	setShaderCameraUniform(light.getShader(), camera.getProjection(), camera.getView());
	cube.update();
	light.update(); 
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cube.render();
	light.render();

	glfwSwapBuffers(window);
}