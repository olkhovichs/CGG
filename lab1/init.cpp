#include "init.h"

Init::Init() {}

Init::~Init() {}

void Init::initOpenGL() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (!glfwInit()) {
        std::cerr << "GlfwInit failed" << std::endl;
        return;
    }
}

void Init::initWindow(const int width, const int height, std::string name) {
    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (window == NULL) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);
}

void Init::drawScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void Init::deleteInitOpenGL() {
    glfwTerminate();
    return;
}


void Init::drawTriangle() {
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);

    float   ratio = width / (float)height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 1.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(1.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(1.f, 1.f, 0.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();
}

void Init::rendering() {
    while (!glfwWindowShouldClose(window))
    {
        drawScene();
        glClear(GL_COLOR_BUFFER_BIT);

        drawTriangle();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
