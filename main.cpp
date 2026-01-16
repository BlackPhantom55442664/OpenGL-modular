#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "InitializeSystem.h"
#include "MouseInput.h"
#include "Resources.h"
#include "stb_image.h"
#include "Texture.h"
#include "Camera.h"
#include "mesh.h"

glm::vec3 cubePositions[] = {
	glm::vec3(0.0f, 0.0f, 0.0f),
	glm::vec3(2.0f, 5.0f, -15.0f),
	glm::vec3(-1.5f, -2.2f, -2.5f),
	glm::vec3(-3.8f, -2.0f, -12.3f),
	glm::vec3(2.4f, -0.4f, -3.5f),
	glm::vec3(-1.7f, 3.0f, -7.5f),
	glm::vec3(1.3f, -2.0f, -2.5f),
	glm::vec3(1.5f, 2.0f, -2.5f),
	glm::vec3(1.5f, 0.2f, -1.5f),
	glm::vec3(-1.3f, 1.0f, -1.5f)
};

void setUniformMatrix(Shader& shader, const char* uniformName, glm::mat4 &matrix) {
	GLint uniformLoc = glGetUniformLocation(shader.ID, uniformName);
	glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(matrix));
}

const float moveSpeed = 0.0055f;
void inputProcess(GLFWwindow* window) {
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraFront * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraFront * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * moveSpeed;

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	setUniformMatrix(shader, "view", view);

	projection = glm::perspective(glm::radians(fov), (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.1f, 100.0f);
	setUniformMatrix(shader, "projection", projection);
}

void render() {
	glBindVertexArray(VAO);
	shader.activate();
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	//glDrawArrays(GL_TRIANGLES, 0, 36);

	for (unsigned int i = 0; i < 10; i++) {
		// calculate the model matrix for each object and pass it to shader before drawing
		glm::mat4 cubeModel = glm::mat4(1.0f);
		cubeModel = glm::translate(cubeModel, cubePositions[i]);
		float angle = 20.0f * (i + 1);
		cubeModel = glm::rotate(cubeModel, glm::radians(angle) * (float)glfwGetTime() * 0.5f, glm::vec3(1.0f, 0.3f, 0.5f));
		setUniformMatrix(shader, "model", cubeModel);

		//model = glm::mat4(1.0f);
		//model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 0.0f, 0.0f));
		//setUniformMatrix(shader, "model", model);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
}

int main() {
	initializeGLFW();

	window = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
	glEnable(GL_DEPTH_TEST);

	VAO = createVAO();
	VBO = createVBO(vertices);
	EBO = createEBO(indices);

	//linkVBO(VAO, VBO, attributeSize);
	//linkEBO(VAO, EBO);


	cubeVBO = createVBO(verticesCube);
	
	std::vector<GLuint> cubeAtrributeSize = { 3, 0, 2 };
	linkVBO(VAO, cubeVBO, cubeAtrributeSize);
	


	std::vector<std::pair<const char*, GLenum>> shaderPack;
	shaderPack.push_back(std::make_pair("VertexShader.glsl", GL_VERTEX_SHADER));
	shaderPack.push_back(std::make_pair("FragmentShader.glsl", GL_FRAGMENT_SHADER));
	shader.createShader(shaderPack);
	

	stbi_set_flip_vertically_on_load(true);
	GLuint texture1 = createTexture("container.jpg", GL_RGB, GL_TEXTURE0);
	GLuint texture2 = createTexture("awesomeface.png", GL_RGBA, GL_TEXTURE1);


	shader.activate();
	
	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
	glUniform1i(glGetUniformLocation(shader.ID, "texture2"), 1);
	glUniform1f(glGetUniformLocation(shader.ID, "ratio"), 0.5f);

	setUniformMatrix(shader, "model", model);
	setUniformMatrix(shader, "view", view);
	setUniformMatrix(shader, "projection", projection);


	std::cout << "Model: " << glm::to_string(model) << std::endl << std::endl;
	std::cout << "View: " << glm::to_string(view) << std::endl << std::endl;
	std::cout << "Projection: " << glm::to_string(projection) << std::endl << std::endl;

	
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	while (!glfwWindowShouldClose(window)) {
		std::cout << "Camera: " << cameraPos.x << ' ' << cameraPos.y << ' ' << cameraPos.z << "\t\t";
		std::cout << "FOV: " << fov << "\t\t";
		std::cout << "Pitch: " << pitch << "\t\t" << "Yaw: " << yaw << std::endl;

		float deltaTime = 0.0f;
		float lastFrame = 0.0f;

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		inputProcess(window);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		render();

		glfwSwapBuffers(window);
		//glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}