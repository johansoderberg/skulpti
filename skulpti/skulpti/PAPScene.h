﻿#pragma once

#include "PAPWindow.h"
#include "PAPShaderProgram.h"


class PAPWindow;

class PAPScene
{
public:
	PAPScene(PAPWindow* window);
	virtual ~PAPScene();
	virtual void render(GLFWwindow* window) = 0;
	virtual void key_press(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
	virtual void size_callback(GLFWwindow* window, int width, int height) = 0;
	// mouse callbacks
	// Switch scene methods
protected:
	PAPWindow* _window;

};

