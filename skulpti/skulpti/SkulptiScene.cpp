#include "stdafx.h"
#include "SkulptiScene.h"
#include "GLFW\glfw3.h"


SkulptiScene::SkulptiScene(PAPWindow* window) : PAPScene(window)
{

	GLuint VertexArrayID;
	
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);


	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}


SkulptiScene::~SkulptiScene()
{

}

void SkulptiScene::render(GLFWwindow* window) {

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,			// attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,			// size
		GL_FLOAT,	// type
		GL_FALSE,	// normalized?
		0,			// stride
		(void*)0	// array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void SkulptiScene::key_press(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

void SkulptiScene::size_callback(GLFWwindow* window, int width, int height) {

}