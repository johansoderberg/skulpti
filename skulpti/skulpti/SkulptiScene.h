#pragma once
#include "PAPScene.h"

class SkulptiScene :
	public PAPScene
{
public:
	SkulptiScene(PAPWindow* window);
	~SkulptiScene();
	virtual void render(GLFWwindow* window);
	virtual void key_press(GLFWwindow* window, int key, int scancode, int action, int mods);
	virtual void size_callback(GLFWwindow* window, int width, int height);
	
	GLfloat g_vertex_buffer_data[9] = {-1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,  1.0f, 0.0f};
	GLuint vertexbuffer;
};

