#include "stdafx.h"
#include <iostream>
#include "PAPWindow.h"
#include "SkulptiScene.h"

using namespace std;

PAPWindow* win = NULL;

void error_callback(int error, const char* description){
		cout << "error_callback: " << description << endl;
}

void window_size_callback(GLFWwindow* window, int width, int height){
	win->size_callback(window, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	win->key_press(window, key, scancode, action, mods);
}

void render(GLFWwindow *window) {
	win->render(window);
}

void PAPWindow::start() {

	cout << "initialising GLFW: ";
	if (!glfwInit())
	{
		cout << "Failed to initialise GLFW. (Exiting) \n";
		throw 8;
	}

	cout << glfwGetVersionString() << endl;
	glfwSetErrorCallback(error_callback);

	// Select OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1600, 800, _title.c_str(), NULL, NULL);
	if (window == NULL) {
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetKeyCallback(window, key_callback);

	// Load extentions and function pointers.
	if (!gladLoadGL()) {
		printf("Something went wrong!\n");
		exit(-1);
	}
	cout << "Vendor:   " << glGetString(GL_VENDOR) << endl;
	cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
	cout << "Version:  " << glGetString(GL_VERSION) << endl;

	_currentScene = new SkulptiScene(this);

	// Start window handling
	while ((!glfwWindowShouldClose(window)) && (!doTerminate))
	{
		render(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	// Stop window handling.

	// Clean up
	glfwDestroyWindow(window);
	glfwTerminate();
}

PAPWindow::PAPWindow(string Title)
{
	if (win != NULL) {
		throw 9;
	}
	else
		win = this;
	esc_pressed_counter = 0;
	doTerminate = false;
	_title = Title;
}

PAPWindow::~PAPWindow()
{

}

void PAPWindow::key_press(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if ((key == GLFW_KEY_ESCAPE)) {
		if ((action == GLFW_PRESS)) {
			esc_pressed_counter++;
		}
		
		if (esc_pressed_counter >= 3) {
			terminate();
		}
	}
	else
		esc_pressed_counter = 0;

	if (_currentScene == NULL) {
		cout << "Warning: Current Scene is NULL (key_press).\n";
		return;
	}
	_currentScene->key_press(window, key, scancode, action, mods);
}

void PAPWindow::size_callback(GLFWwindow* window, int width, int height) {
	
	if(_currentScene == NULL) {
		cout << "Warning: Current Scene is NULL (size_callback).\n";
		return;
	}
	_currentScene->size_callback(window, width, height);
}

void PAPWindow::terminate() {
	doTerminate = true;
}

void PAPWindow::render(GLFWwindow* window) {
	if(_currentScene == NULL) {
		cout << "Warning: Current Scene is NULL (render).\n";
		return;
	}
	glClear(GL_COLOR_BUFFER_BIT);
	_currentScene->render(window);
}

