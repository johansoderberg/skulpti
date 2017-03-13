#include "stdafx.h"
#include "PAPShaderProgram.h"
#include <fstream>
#include <iostream>
#include <vector>

PAPShaderProgram::PAPShaderProgram(std::string vertexFilename, std::string fragmentFilename){
	GLuint vertexShaderID = loadShader(vertexFilename, GL_VERTEX_SHADER);
	if (vertexShaderID == 0) {
		throw 0;
	}

	GLuint fragmentShaderID = loadShader(fragmentFilename, GL_FRAGMENT_SHADER);
	if (fragmentShaderID == 0) {
		throw 0;
	}

	GLint result = 0;
	GLint logLength = 0;

	// Link the program
	cout << "Linking program.\n";
	_programID = glCreateProgram();
	glAttachShader(_programID, vertexShaderID);
	glAttachShader(_programID, fragmentShaderID);
	glLinkProgram(_programID);

	// Check the program
	glGetProgramiv(_programID, GL_LINK_STATUS, &result);
	glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &logLength);
	if (logLength > 0) {
		std::vector<char> ProgramErrorMessage(logLength + 1);
		glGetProgramInfoLog(_programID, logLength, NULL, &ProgramErrorMessage[0]);
		cout << &ProgramErrorMessage[0] << endl;
	}

	glDetachShader(_programID, vertexShaderID);
	glDeleteShader(vertexShaderID);

	glDetachShader(_programID, fragmentShaderID);
	glDeleteShader(fragmentShaderID);
}

PAPShaderProgram::~PAPShaderProgram(){
	glDeleteProgram(_programID);
}

void PAPShaderProgram::use() {
	glUseProgram(_programID);
}

GLuint PAPShaderProgram::getProgramID(){
	if (_programID == 0) {
		cout << "Warning: program 0 is being used.\n";
	}
	return _programID;
}

// returns new shaderID
// if errors are encountered 0 is returned.
GLuint PAPShaderProgram::loadShader(std::string filename, GLuint shaderType){
	if ((shaderType != GL_FRAGMENT_SHADER) && (shaderType != GL_VERTEX_SHADER)) {
		cout << "Invalid Shader type. Filename: " << filename << endl;
		return 0;
	}

	GLuint shaderID = glCreateShader(shaderType);
	std::string code = "";
	std::ifstream VertexShaderStream(filename, std::ios::in);

	if (!(VertexShaderStream.is_open())) {
		std::cout << "Failed to open file (" << filename << ").\n";
		return 0;
	}
	
	std::string Line = "";
	while (getline(VertexShaderStream, Line))
		code += "\n" + Line;
	VertexShaderStream.close();
	
	// Compile Shader
	cout << "Compiling shader: " << filename << endl;
	char const * sourcePointer = code.c_str();
	glShaderSource(shaderID, 1, &sourcePointer, NULL);
	glCompileShader(shaderID);

	// Check Shader compilation result.
	GLint result = GL_FALSE;
	GLint logLength = 0;
	
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
	
	if (logLength > 1){
		std::vector<char> VertexShaderErrorMessage(logLength + 1);
		glGetShaderInfoLog(shaderID, logLength, NULL, &VertexShaderErrorMessage[0]);
		cout << "Shader compilation failed. (" << filename << ")\n" << code << endl;
		cout << &VertexShaderErrorMessage[0] << endl;
		return 0;
	}

	return shaderID;
}


