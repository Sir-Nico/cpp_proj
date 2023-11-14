#version 330 core
out vec4 FragColor;

// Takes the colour from the vertex shader as an argument
in vec3 color;

void main()
{
   FragColor = vec4(color, 1.0f);
}