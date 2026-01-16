#include "MouseInput.h"
#include "Resources.h"
#include "Camera.h"

// Initial mouse location
float lastX = SCREEN_WIDTH >> 1;
float lastY = SCREEN_HEIGHT >> 1;

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
	static bool firstMouse = true;
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xOffset = xpos - lastX;
	float yOffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	const float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	yaw += xOffset;
	pitch += yOffset;

	pitch = pitch > 89.0f ? 89.0f : pitch;
	pitch = pitch < -89.0f ? -89.0f : pitch;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}

void scroll_callback(GLFWwindow* window, double xOffset, double yOffset) {
	fov -= (float)yOffset;
	fov = fov < 1.0f ? 1.0f : fov;
	fov = fov > 45.0f ? 45.0f : fov;
}