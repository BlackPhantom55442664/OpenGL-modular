#include "Cube.h"


Cube::Cube() {
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
		2, 3, 6,	3, 6, 7		// Down
	};


	VAO = createVAO();
	VBO = createVBO(vertices);
	EBO = createEBO(indices);

	linkVBO(VAO, VBO, attributeSize);
	linkEBO(VAO, EBO);

	
	//vertexShader = std::make_pair("CubeVertexShader.glsl", GL_VERTEX_SHADER);
	//fragmentShader = std::make_pair("CubeFragmentShader.glsl", GL_FRAGMENT_SHADER);
	//
	//shaderPack.push_back(vertexShader);
	//shaderPack.push_back(fragmentShader);

	//shader.createShader(shaderPack);
};

Cube::~Cube() {
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	//glDeleteProgram(shader);
};

void Cube::render() {
	//shader.activate();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
};
