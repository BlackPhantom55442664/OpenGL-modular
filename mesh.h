#ifndef MESH_H
#define MESH_H

#include<glad/glad.h>
#include<vector>

GLuint createVAO();
GLuint createVBO(std::vector<GLfloat> &vertices);
GLuint createEBO(std::vector<GLuint> &indices);

void linkVBO(GLuint VAO, GLuint VBO, std::vector<GLuint>& attributeSize);
void linkEBO(GLuint VAO, GLuint EBO);

#endif