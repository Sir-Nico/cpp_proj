#include "../headers/classes/texturedSquare.h"

TexturedSquare::TexturedSquare(GLfloat* vertexList, char* filePath)
{
    verteces = vertexList;
    char* texPath = filePath;

    // List of indeces for buffer
    GLuint indeces[] = 
    {
        0, 2, 1,  // Upper left tri
        0, 3, 2   // Lower right tri
    };

    shaderProgram = Shader("../resources/shaders/default.vert", "../resources/shaders/default.frag");
    
    shaderVAO.Bind();
    shaderVBO = VBO(verteces, sizeof(verteces));
    shaderEBO = EBO(indeces, sizeof(indeces));

    // Linking VAO attributes like coords and colours to VAO
    shaderVAO.LinkAttrib(shaderVBO, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    shaderVAO.LinkAttrib(shaderVBO, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    shaderVAO.LinkAttrib(shaderVBO, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));

    // Unbinding everything to avoid modifying
    shaderVAO.Unbind();
    shaderVBO.Unbind();
    shaderEBO.Unbind();

    // Getting the ID of the "scale" uniform
    uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture

    int imgWidth, imgHeight, colourChannelsNum;
    unsigned char* bytes = stbi_load(texPath, &imgWidth, &imgHeight, &colourChannelsNum, 0);

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint tex0Uniform = glGetUniformLocation(shaderProgram.ID, "tex0");
    shaderProgram.Activate();
    glUniform1i(tex0Uniform, 0);
}

void TexturedSquare::Draw()
{
    shaderProgram.Activate();  // Activates shader program

    // Scale the triangles (0 is the default size)
    glUniform1f(uniID, 0.5);

    glBindTexture(GL_TEXTURE_2D, texture);

    shaderVAO.Bind();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);  // Drawing the triangles with the GL_TRIANGLES primitive

}

void TexturedSquare::Delete()
{
    shaderVAO.Delete();
    shaderVBO.Delete();
    shaderEBO.Delete();
    glDeleteTextures(1, &texture);
    shaderProgram.Delete();
}