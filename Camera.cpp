#include "Camera.h"
#include "Constant.h"

Camera::Camera() {
	yaw = -90.0f;
	pitch = 0.0f;
	fov = 45.0f;

	moveSpeed = 0.01f;
	position = glm::vec3(0.0f, 0.0f, 3.0f);
	front = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(position, position + front, up);

	lastX = SCREEN_WIDTH >> 1;
	lastY = SCREEN_HEIGHT >> 1;
	sensitivity = 0.05f;
}

void Camera::update(GLFWwindow* window) {
	move(window);
	view = glm::lookAt(position, position + front, up);
	projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::getProjection() {
	return projection;
}

glm::mat4 Camera::getView() {
	return view;
}

void Camera::move(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		position += glm::vec3(front.x, 0, front.z) * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		position -= glm::vec3(front.x, 0, front.z) * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		position += glm::normalize(glm::cross(front, up)) * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		position -= glm::normalize(glm::cross(front, up)) * moveSpeed;

	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		position += up * moveSpeed * 2.0f;

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		position -= up * moveSpeed * 2.0f;
}

//void Camera::mouseCallback(GLFWwindow* window, GLdouble xPos, GLdouble yPos) {
//	static bool firstMouse = true;
//	if (firstMouse) {
//		lastX = xPos;
//		lastY = yPos;
//		firstMouse = false;
//	}
//
//	GLfloat xOffset = xPos - lastX;
//	GLfloat yOffset = lastY - yPos;
//	lastX = xPos;
//	lastY = yPos;
//
//
//	// Update mouse position
//	xOffset *= sensitivity, yOffset *= sensitivity;
//	yaw += xOffset, pitch += yOffset;
//
//	// Limit the pitch angle
//	pitch = pitch > 89.0f ? 89.0f : pitch;
//	pitch = pitch < -89.0f ? -89.0f : pitch;
//	
//	// Update looking direction
//	front.x = glm::cos(glm::radians(yaw)) * glm::cos(glm::radians(pitch));
//	front.y = glm::sin(glm::radians(pitch));
//	front.z = glm::sin(glm::radians(yaw)) * glm::sin(glm::radians(pitch));
//	front = glm::normalize(front);
//}