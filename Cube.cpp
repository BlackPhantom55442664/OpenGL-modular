#include "Cube.h"

Cube::Cube() {
	model = glm::mat4(1.0f);

	attributeSize = { 3 };
	vertices = {
		// Right
		0.5f,	0.5f,	0.5f,	// Up Front
		0.5f,	0.5f,	-0.5f,	// Up Back
		0.5f,	-0.5f,	0.5f,	// Down Front
		0.5f,	-0.5f,	-0.5f,	// Down Back

		// Left
		-0.5f,	0.5f,	0.5f,	// Up Front
		-0.5f,	0.5f,	-0.5f,	// Up Back
		-0.5f,	-0.5f,	0.5f,	// Down Front
		-0.5f,	-0.5f,	-0.5f	// Down Back
	};

	indices = {
		0, 1, 2,	1, 2, 3,	// Right
		4, 5, 6,	5, 6, 7,	// Left
		0, 1, 4,	1, 4, 5,	// Up
		2, 3, 6,	3, 6, 7,	// Down
		0, 2, 4,	2, 4, 6,	// Front
		1, 3, 5,	3, 5, 7		// Back
	};


	VAO = createVAO();
	VBO = createVBO(vertices);
	EBO = createEBO(indices);

	linkVBO(VAO, VBO, attributeSize);
	linkEBO(VAO, EBO);

	
	shaderPack.push_back(std::make_pair("CubeVertexShader.glsl", GL_VERTEX_SHADER));
	shaderPack.push_back(std::make_pair("CubeFragmentShader.glsl", GL_FRAGMENT_SHADER));
	shader.createShader(shaderPack);
}

Cube::~Cube() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void Cube::render() {
	glBindVertexArray(VAO);
	shader.activate();

	setShaderObjectModel(shader.getID(), model);
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	
	glBindVertexArray(0);
}

void Cube::update() {
	shader.activate();
	setShaderObjectModel(getShader(), getModel());
}

GLuint Cube::getShader() {
	return shader.getID();
}

glm::mat4 Cube::getModel() {
	return this->model;
}