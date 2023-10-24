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
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";


int main() 
{
    // GLFW Init Functions
    glfwInit();
    
    // Specifying which version is being used, here 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    
    // Specifying profiles, in this case only the CORE profile, this gives me access to only the modern OpenGL functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

    // Telling GLFW to use the window just created
    glfwMakeContextCurrent(window);

    // Load GLAD, giving me access to its functions
    gladLoadGL();

    // Specifying viewport, here the entire window (0,0 to 800,600)
    glViewport(0, 0, 800, 600);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    GLuint VAO, VBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Clearing the entire window with a navy colour, specified in normalised floats
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    // Clearing and swapping the color buffer bit (makes the changes render)
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);

        glfwPollEvents();  // Processes all events, if not the window will be in a "not responding state"
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // Terminating stuff B)
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}