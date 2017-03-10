#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <string>
#include "PAPScene.h"

using namespace std;

class PAPScene;

class PAPWindow
{
public:
	
	PAPWindow(string Title);
	void start();
	virtual ~PAPWindow();
	void key_press(GLFWwindow* window, int key, int scancode, int action, int mods);
	void size_callback(GLFWwindow* window, int width, int height);
	void render(GLFWwindow* window);
	void terminate();
	
private:
	int esc_pressed_counter;
	bool doTerminate;
	PAPScene* _currentScene;
	string _title;
};

