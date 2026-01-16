#include "mesh.h"

#include<numeric>

GLuint createVAO() {
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	return VAO;
}

GLuint createVBO(std::vector<GLfloat> &vertices) {
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return VBO;
}

GLuint createEBO(std::vector<GLuint> &indices) {
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	return EBO;
}

void linkVBO(GLuint VAO, GLuint VBO, std::vector<GLuint> &attributeSize) {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	int stride = std::accumulate(attributeSize.begin(), attributeSize.end(), 0) * sizeof(GLfloat);

	size_t offset = 0;
	for (GLuint layout = 0; layout < attributeSize.size(); layout++) {
		glVertexAttribPointer(layout, attributeSize[layout], GL_FLOAT, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(layout);
		offset += attributeSize[layout] * sizeof(GLfloat);
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void linkEBO(GLuint VAO, GLuint EBO) {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	//glBindVertexArray(0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}