#pragma once
#pragma comment(lib, "opengl32.lib")

#include <iostream>
#include <string>

#include <GLFW/glfw3.h>

class Init {
public:
	Init();
	~Init();

	GLFWwindow* window;

	void initOpenGL();
	void initWindow(const int width, const int height, std::string name);
	void rendering();
	void deleteInitOpenGL();
	void drawScene();
	void drawTriangle();
};