#ifndef UTILS_H
#define UTILS_H

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


inline void setShaderCameraUniform(GLuint shaderID, const glm::mat4 &cameraProjection, const glm::mat4 &cameraView) {
	glUseProgram(shaderID);

	GLint location = glGetUniformLocation(shaderID, "projection");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(cameraProjection));

	location = glGetUniformLocation(shaderID, "view");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(cameraView));
}

inline void setShaderObjectModel(GLuint shaderID, glm::mat4 model) {
	glUseProgram(shaderID);
	GLint location = glGetUniformLocation(shaderID, "model");
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(model));
}

#endif // !UTILS_H
