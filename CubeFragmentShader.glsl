#version 330 core

in vec3 aColor;

out vec4 FragColor;

void main() {
	FragColor = vec4(aColor + vec3(0.5), 1.0f);
}