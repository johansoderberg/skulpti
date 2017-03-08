#pragma once
#include "PAPScene.h"
class SkultpiScene :
	public PAPScene
{
public:
	SkultpiScene(PAPWindow* window);
	~SkultpiScene();
	virtual void render(GLFWwindow* window);
	virtual void key_press(GLFWwindow* window, int key, int scancode, int action, int mods);
	virtual void size_callback(GLFWwindow* window, int width, int height);
};

