#include "Camera.h"

// Camera position
glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);

// Camera direction
glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
//glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);
glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);

// Camera up
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

// Look at
//glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

// Matrix
glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
glm::mat4 projection = glm::perspective(glm::radians(fov), 800.0f / 600.0f, 0.1f, 100.0f);

// Direction
glm::vec3 direction;
float yaw = -90.0f;
float pitch = 0.0f;
float fov = 45.0f;