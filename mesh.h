#ifndef MESH_H
#define MESH_H

#include<glad/glad.h>
#include<numeric>
#include<vector>

inline GLuint createVAO() {
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	return VAO;
}

inline GLuint createVBO(std::vector<GLfloat> &vertices) {
	GLuint VBO;
	glGenBuffers(1, &VBO);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return VBO;
}

inline GLuint createEBO(std::vector<GLuint>& indices) {
	GLuint EBO;
	glGenBuffers(1, &EBO);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GL_UNSIGNED_INT), indices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	return EBO;
}

inline void linkVBO(GLuint VAO, GLuint VBO, std::vector<GLuint>& attributeSize) {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	GLuint stride = std::accumulate(attributeSize.begin(), attributeSize.end(), 0) * sizeof(GLfloat);

	size_t offset = 0;
	for (int layout = 0; layout < attributeSize.size(); layout++) {
		glVertexAttribPointer(layout, attributeSize[layout], GL_FLOAT, GL_FALSE, stride, (void*)offset);
		glEnableVertexAttribArray(layout);
		offset += attributeSize[layout] * sizeof(GLfloat);
	}
	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

inline void linkEBO(GLuint VAO, GLuint EBO) {
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#endif // !MESH_H
