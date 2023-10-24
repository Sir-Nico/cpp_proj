#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() 
{
    // GLFW Init Functions
    glfwInit();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window creation
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);  // width, height, title, fullscreen (y/n), idk what the last one does
    if (window == NULL ) {
        std::cout << "Window Failed to Create" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Telling GLFW to use the window just created
    glfwMakeContextCurrent(window);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();  // Processes all events, if not the window will be in a "not responding state"
    }

    // Terminating stuff B)
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}