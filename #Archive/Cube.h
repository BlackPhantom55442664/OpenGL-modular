#ifndef CUBE_H
#define CUBE_H

#include<glad/glad.h>
#include<vector>

#include "Shader.h"
#include "Mesh.h"

class Cube {
public:
	Cube();
	~Cube();
	
	void render();
	//void addShader(const char* shaderPath, GLenum shaderType);

private:
	std::vector<GLfloat> vertices;
	std::vector<GLuint> attributeSize;
	std::vector<GLuint> indices;

	std::vector<std::pair<const char*, GLenum>> shaderPack;
	std::pair<const char*, GLenum> vertexShader;
	std::pair<const char*, GLenum> fragmentShader;

	GLuint VAO;
	GLuint VBO;
	GLuint EBO;
	//Shader shader;

};

#endif