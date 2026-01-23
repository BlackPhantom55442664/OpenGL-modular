#include "Shader.h"

Shader::Shader() {
	ID = 0;
	shaderID = {};
}

Shader::Shader(std::vector<std::pair<const char*, GLenum>> &shaders) {
	createShader(shaders);
}

void Shader::createShader(std::vector<std::pair<const char*, GLenum>> &shaders) {
	if (ID != 0) glDeleteProgram(ID);
	shaderID.clear();

	for (auto shader : shaders) {
		std::string shaderSource = loadShaderData(shader.first);
		const char* shaderCode = shaderSource.c_str();

		GLuint shaderObject = createShader(shaderCode, shader.second);
		shaderID.push_back(shaderObject);

		//std::cerr << shader.first << "return: " << std::endl << shaderSource << std::endl << std::endl;
	}

	ID = createProgram();
}

Shader::~Shader() {
	glDeleteProgram(ID);
}

GLuint Shader::getID() {
	return ID;
}

void Shader::activate() {
	if (ID == 0) std::cout << "Shader is blank" << std::endl;
	glUseProgram(ID);
}

std::string Shader::loadShaderData(const char* path) {
	std::string code;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		shaderFile.open(path);

		std::stringstream shaderStream;
		shaderStream << shaderFile.rdbuf();

		shaderFile.close();
		return shaderStream.str();
	}
	catch (std::ifstream::failure e) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		std::cout << "\tFile: " << path << std::endl;
	}

	return "";
}

GLuint Shader::createShader(const char* shaderSource, GLenum type) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	return shader;
}

GLuint Shader::createProgram() {
	GLuint program = glCreateProgram();

	for (GLuint shader : shaderID)
		glAttachShader(program, shader);

	glLinkProgram(program);

	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		GLchar infoLog[512];
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	for (GLuint shader : shaderID)
		glDeleteShader(shader);

	return program;
}