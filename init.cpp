

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

void Init::rendering() {
    while (!glfwWindowShouldClose(window))
    {
        drawScene();
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

/*void Init::reshape(GLsizei _width, GLsizei _height, GLint _x = 0, GLint _y = 0) {
        if (!_height)
            return;
        glViewport(_x, _y, _width, _height);
}*/

void Init::deleteInitOpenGL() {
    glfwTerminate();
    return;
}

/*void Init::initGlad() {
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }
}*/
