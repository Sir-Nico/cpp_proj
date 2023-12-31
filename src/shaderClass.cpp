#include "../headers/shaderClass.h"

std::string get_file_contents(const char* filename) 
{
    std::ifstream in(filename, std::ios::binary);
    if (in) 
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return(contents);
    }
    throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) 
{
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmentCode = get_file_contents(fragmentFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);  // Creating Vertex Shader Object and getting its reference
    glShaderSource(vertexShader, 1, &vertexSource, NULL);  // Attaching Vertex Shader Source Code to Vertex Shader Object
    glCompileShader(vertexShader);  // Compiles shader into machine code
    compileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);  // Creating Fragment Shader Object and getting its reference
    // Attaching Fragment Shader Source Code to Fragment Shader Object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    compileErrors(fragmentShader, "FRAGMENT");


    ID = glCreateProgram();  // Creating Shader Program Object and getting its reference
    // Adding the shaders to the Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);  // Links all the shaders into the Shader Program
    compileErrors(ID, "PROGRAM");

    // Deleting the original shader objects, as they now are redundant
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate() 
{
    glUseProgram(ID);  // Specifying which Shader Program to use
}

void Shader::Delete() 
{
    glDeleteProgram(ID);  // Specifying which Shader Program to use
}

void Shader::compileErrors(unsigned int shader, const char* type)
{
    GLint hasCompiled;
    char infoLog[1024];
    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_COMPILATION_ERROR for: " << type << "\n" << std::endl;
        }
    } else
    {
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
        if (hasCompiled == GL_FALSE)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "SHADER_LINKING_ERROR for: " << type << "\n" << std::endl;
        }
    }
}
