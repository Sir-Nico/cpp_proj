#ifndef TEXTURED_SQUARE_CLASS_H
#define TEXTURED_SQUARE_CLASS_H

#include <glad/glad.h>
#include <stb/stb_image.h>
#include <string>

#include "../../src/shaderClass.cpp"
#include "../../src/VAO.cpp"
#include "../../src/VBO.cpp"
#include "../../src/EBO.cpp"
#include "../../src/stb.cpp"

class TexturedSquare
{
    public:
        GLfloat* verteces;
        std::string texPath;
        Shader shaderProgram;
        GLuint uniID;
        GLuint texture;
        VAO shaderVAO;
        VBO shaderVBO;
        EBO shaderEBO;

        TexturedSquare(GLfloat* vertexList, char* filePath);

        void Draw();
        void Delete();
};

#endif