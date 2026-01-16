#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<vector>
#include<utility>

class Shader {
public:
	GLuint ID;
	std::vector<GLuint> shaderID;
	
	//Shader(std::vector<std::pair<const char*, GLenum>> shaders);
	void createShader(std::vector<std::pair<const char*, GLenum>> shaders);
	~Shader();
	void activate();

private:
	std::string loadShaderData(const char* path);
	GLuint createShader(const char* shaderSource, GLenum type);
	GLuint createProgram();
};

#endif