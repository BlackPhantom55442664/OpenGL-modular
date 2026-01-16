#version 330 core

in vec3 ourColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float ratio;

void main() {
	FragColor = vec4(ourColor, 1.0);
	FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), ratio);
}