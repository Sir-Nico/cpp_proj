#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// Copied from the tutorial I am using (I am out of my depth here)
//----------------------------------------------------------------
// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.9f, 0.46f, 1.0f);\n"
"}\n\0";


int main() 
{
    // GLFW Init Function
    glfwInit();
    
    // Specifying which version is being used, here 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // Specifying profiles, in this case only the CORE profile, this gives access to only the modern OpenGL functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Vertex Coordinates
    GLfloat vertices[] = {
        -0.3f, 0.64f, 0.0f,
        -0.78f, 0.2f, 0.0f,
        0.5f, -0.31f, 0.0f
    };

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

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);  // Creating Vertex Shader Object and getting its reference
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);  // Attaching Vertex Shader Source Code to Vertex Shader Object
    glCompileShader(vertexShader);  // Compiles shader into machine code

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);  // Creating Fragment Shader Object and getting its reference
    // Attaching Fragment Shader Source Code to Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();  // Creating Shader Program Object and getting its reference
    // Adding the shaders to the Shader Program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);  // Links all the shaders into the Shader Program

    // Deleting the original shader objects, as they now are redundant
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    GLuint VAO, VBO;  // Creating reference values for Vertex Array Object & Vertex Buffer Object

    // Generating the Vertex Array Object and Vertex Buffer Object
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);  // Makes the reference value the current vertex array through binding 
    glBindBuffer(GL_ARRAY_BUFFER, VBO);  // Bind the buffer object and specifying buffer type
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);  // Adds the verteces as data in the buffer

    // Configures and enables the Vertex Attributes, so that OpenGL can read it properly
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Binding the VBO & VAO to 0 to avoid accidentally tampering with the Objects already created
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Clearing the entire window with a navy colour, specified in normalised floats
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);  // Clearing and swapping the color buffer bit (makes the changes render)
    glfwSwapBuffers(window);
    
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);  // Specifying which Shader Program to use
        glBindVertexArray(VAO);  // Binding the VAO so that OpenGL knows to use it
        glDrawArrays(GL_TRIANGLES, 0, 3);  // Drawing the triangle with the GL_TRIANGLES primitive
        glfwSwapBuffers(window);

        glfwPollEvents();  // Processes all events, if not the window will be in a "not responding state"
    }

    // Deleting every object created
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminating stuff B)
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
