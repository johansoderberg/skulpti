#pragma once

#include <string>
#include <map>
#include "PAPWindow.h"


class PAPShaderProgram
{
public:
	PAPShaderProgram(std::string vertexFilename, std::string fragmentFilename);
	~PAPShaderProgram();

	GLuint getProgramID();
	void use();
protected:
	GLuint _programID;
	GLuint PAPShaderProgram::loadShader(std::string filename, GLuint shaderType);
};

