#pragma once
#pragma comment(lib, "opengl32.lib")

#include <iostream>
#include <string>

//#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Init {
public:
	explicit Init();
	~Init();

	void initOpenGL();
	void initWindow(const int width, const int height, std::string name);
	//void initGlad();
	void rendering();
	void deleteInitOpenGL();

	GLFWwindow* window;

	//void reshape(GLsizei _width, GLsizei _height, GLint _x = 0, GLint _y = 0);
	void drawScene();
};