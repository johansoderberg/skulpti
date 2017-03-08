
#include "stdafx.h"
#include <iostream>

#include <GLFW/glfw3.h>

using namespace std;



void error_callback(int error, const char* description)
{
	cout << "error_callback: " << description << endl;
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
	cout << "Rezised window: " << width << " x " << height << endl;
}

int esc_pressed_counter = 0;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE) {
		esc_pressed_counter++;
		if (esc_pressed_counter >= 3) {

		}
	}
	else
		esc_pressed_counter = 0;
		
}

void render(GLFWwindow *window) {
	glClear(GL_COLOR_BUFFER_BIT);
	
}


int main(int argc, char* argv[])
{
	cout << "Starting skulpti.\n";
	cout << "initialising GLFW: ";

	if (!glfwInit())
	{
		cout << "Failed to initialise GLFW. (Exiting) \n";
		return 1;
	}

	cout << glfwGetVersionString() << endl;
	glfwSetErrorCallback(error_callback);

	GLFWwindow* window = glfwCreateWindow(1600, 800, "skulpti", NULL, NULL);
	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, window_size_callback);
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window))
	{
		render(window);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);
	// Clean up

	glfwTerminate();

    return 0;
}



