#include "Shader.h"

void Shader::createShader(std::vector<std::pair<const char*, GLenum>> shaders) {
	for (auto shader : shaders) {
		std::string shaderSource = loadShaderData(shader.first); 
		std::cerr << shader.first << "return: " << std::endl << shaderSource << std::endl << std::endl;
		const char* shaderCode = shaderSource.c_str();

		GLuint shaderObject = createShader(shaderCode, shader.second);
		shaderID.push_back(shaderObject);
	}

	ID = createProgram();
}

Shader::~Shader() {
	glDeleteProgram(ID);
}

void Shader::activate() {
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