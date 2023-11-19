#include <iostream>
#include <cmath>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

#include "texture.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

// Vertex Coordinates
GLfloat verteces[] = 
{ //       Coords       /  R     G     B    / img coords
    -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,  // Lower left corner
    -0.5f,  0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 1.0f,  // Upper left corner
     0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   1.0f, 1.0f,  // Upper right corner
     0.5f, -0.5f, 0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f   // Lower right corner
};

// List of indeces for buffer
GLuint indeces[] = 
{
    0, 2, 1,  // Upper left tri
    0, 3, 2   // Lower right tri
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
    GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);  // width, height, title, fullscreen (y/n), idk what the last one does
    
    // Error handling for the case where the window does not initialise
    if (window == NULL) {
        std::cout << "Window Failed to Create" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);  // Telling GLFW to use the window just created

    gladLoadGL();  // Load GLAD, giving access to its functions

    // Specifying viewport, here the entire window (0,0 to 800, 800)
    glViewport(0, 0, 800, 800);

    Shader shaderProgram("../resources/shaders/default.vert", "../resources/shaders/default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(verteces, sizeof(verteces));
    EBO EBO1(indeces, sizeof(indeces));

    // Linking VAO attributes like coords and colours to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    // Unbinding everything to avoid modifying
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Getting the ID of the "scale" uniform
    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture
	Texture squareChad("../resources/textures/squarechad.jpg", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
	squareChad.texUnit(shaderProgram, "tex0", 0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.Activate();  // Activates shader program

        // Scale the triangles (0 is the default size)
        glUniform1f(uniID, 0.5);

        squareChad.Bind();

        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);  // Drawing the triangles with the GL_TRIANGLES primitive
        glfwSwapBuffers(window);  // Buffer swap :O

        glfwPollEvents();  // Processes all events, if not the window will be in a "not responding state"
    }

    // Deleting every object created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    squareChad.Delete();
    shaderProgram.Delete();
    // Terminating stuff B)
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
