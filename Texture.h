#ifndef TEXTURE_H
#define TEXTURE_H

#include<iostream>
#include<glad/glad.h>
#include "stb_image.h"

GLuint createTexture(const char* texturePath, GLenum colorMode, GLenum texLayer);

#endif