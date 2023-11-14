#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.cpp"
#include "VAO.cpp"
#include "VBO.cpp"
#include "EBO.cpp"

// Vertex Coordinates
GLfloat vertices[] = 
{
    -0.5f, -0.5f * float(sqrt(3)) / 3 * 4 / 3,     0.0f, 0.8f, 0.3f,  0.02f,  // Lower left vertex
    0.5f,  -0.5f * float(sqrt(3)) / 3 * 4 / 3,     0.0f, 0.8f, 0.3f,  0.02f,  // Lower right vertex
    0.0f,   0.5f * float(sqrt(3)) * 2 / 3 * 4 / 3, 0.0f, 1.0f, 0.6f,  0.32f,  // Upper vertex
    -0.25f, 0.5f * float(sqrt(3)) / 6 * 4 / 3,     0.0f, 0.9f, 0.45f, 0.17f,  // Inner left vertex
    0.25f,  0.5f * float(sqrt(3)) / 6 * 4 / 3,     0.0f, 0.9f, 0.45f, 0.17f,  // Inner right vertex
    0.0f,  -0.5f * float(sqrt(3)) / 3 * 4 / 3,     0.0f, 0.8f, 0.3f,  0.02f   // Inner lower vertex
};

// List of indeces for buffer
GLuint indeces[] = 
{
    0, 3, 5,  // Lower left triangle
    3, 2, 4,  // Lower right triangle
    5, 4, 1   // Upper triangle
};


int main() 
{
    // GLFW Init Function
    glfwInit();
    
    // Specifying which version is being used, here 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // Specifying profiles, in this case only the CORE profile, this gives access to only the modern OpenGL functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Window creation
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);  // width, height, title, fullscreen (y/n), idk what the last one does
    
    // Error handling for the case where the window does not initialise
    if (window == NULL) {
        std::cout << "Window Failed to Create" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);  // Telling GLFW to use the window just created

    gladLoadGL();  // Load GLAD, giving access to its functions

    // Specifying viewport, here the entire window (0,0 to 800,600)
    glViewport(0, 0, 800, 600);

    Shader shaderProgram("../shaders/default.vert", "../shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indeces, sizeof(indeces));

    // Linking VAO attributes like coords and colours to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    // Unbinding everything to avoid modifying
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Getting the ID of the "scale" uniform
    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Clearing the entire window with a navy colour, specified in normalised floats
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);  // Clearing and swapping the color buffer bit (makes the changes render)
    glfwSwapBuffers(window);
    
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();  // Activates shader program

        // Scale the triangles (0 is the default size)
        glUniform1f(uniID, 0);

        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);  // Drawing the triangles with the GL_TRIANGLES primitive
        glfwSwapBuffers(window);  // Buffer swap :O

        glfwPollEvents();  // Processes all events, if not the window will be in a "not responding state"
    }

    // Deleting every object created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    // Terminating stuff B)
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
