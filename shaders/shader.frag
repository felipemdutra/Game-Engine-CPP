#version 330 core
out vec4 FragColor;

in vec3 ColorCoord;
in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    FragColor = vec4(ColorCoord, 1.0f);
}
