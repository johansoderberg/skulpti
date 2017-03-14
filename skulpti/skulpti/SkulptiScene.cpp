#include "stdafx.h"
#include "SkulptiScene.h"
#include "PAPPositionable.h"


SkulptiScene::SkulptiScene(PAPWindow* window) : PAPScene(window)
{
	program = new PAPShaderProgram(string("C:\\Users\\JohanSöderberg\\OneDrive - One Agency AB\\Code\\skulpti\\skulpti\\Shaders\\Vertex1.txt"),
		"C:\\Users\\JohanSöderberg\\OneDrive - One Agency AB\\Code\\skulpti\\skulpti\\Shaders\\Fragment1.txt");
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}


SkulptiScene::~SkulptiScene()
{
	delete program;
}

void SkulptiScene::render(GLFWwindow* window) {

	glUseProgram(program->getProgramID());
	// 1st attribute buffer : vertices
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
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_0) {
			PAPPositionable* pos = new PAPPositionable();
			cout << "creating an object with name: " << pos->getName() << endl;
			
		}
		if (key == GLFW_KEY_1) {
			PAPObjectManager::getInstance().deleteObject("Unnamed_3");
		}
		if (key == GLFW_KEY_2) {
			PAPPositionable* pos = (PAPPositionable*) PAPObjectManager::getInstance().getObject("Unnamed_3");
			if (pos == nullptr) {
				cout << "Object doesn't exist\n";
			}
			else
				cout << "Object exists! yay\n";
		}
	}

}

void SkulptiScene::size_callback(GLFWwindow* window, int width, int height) {

}