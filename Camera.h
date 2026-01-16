#ifndef CAMERA_H
#define CAMERA_H

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

// Camera position
extern glm::vec3 cameraPos;
extern glm::vec3 cameraFront;

// Camera direction
extern glm::vec3 cameraTarget;
extern glm::vec3 cameraDirection;

// Camera up
extern glm::vec3 cameraUp;

// Look at
extern glm::mat4 view;

// Matrix
extern glm::mat4 model;
extern glm::mat4 view;
extern glm::mat4 projection;

// Direction
//extern glm::vec3 direction;
extern float yaw;
extern float pitch;
extern float fov;

#endif