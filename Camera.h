#ifndef CAMERA

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "utils.h"

//#include "Resources.h"

class Camera {
public:
	// Need update for move into private
	GLfloat moveSpeed;
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;

	glm::mat4 view;
	glm::mat4 projection;

	GLfloat yaw;
	GLfloat pitch;
	GLfloat fov;

	GLfloat lastX;
	GLfloat lastY;
	GLfloat sensitivity;


	Camera();
	void update(GLFWwindow* window);
	glm::mat4 getProjection();
	glm::mat4 getView();

	//static void mouseCallback(GLFWwindow* window, GLdouble xPos, GLdouble yPos);

private:


	void move(GLFWwindow* window);
};
#endif