#ifndef CUBE_H
#define CUBE_H

#include<glad/glad.h>
#include<vector>
#include "Mesh.h"
#include "Shader.h"
#include "utils.h"
#include<glm/gtc/type_ptr.hpp>

class Cube {
public:
	Cube();
	~Cube();
	void render();
	void update();
	GLuint getShader();
	glm::mat4 getModel();

private:
	glm::mat4 model;

	std::vector<GLuint> attributeSize;
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	std::vector<std::pair<const char*, GLenum>> shaderPack;
	Shader shader;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
};

#endif // !CUBE_H
