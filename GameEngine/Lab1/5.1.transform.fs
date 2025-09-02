#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform float time; // Add this uniform

void main()
{
    vec4 texColor = texture(texture1, TexCoord);

    // Create a smooth RGB loop
    float r = 0.5 + 0.5 * sin(time);
    float g = 0.5 + 0.5 * sin(time + 2.0944); // 2π/3 phase shift
    float b = 0.5 + 0.5 * sin(time + 4.1888); // 4π/3 phase shift

    vec3 rgbLoop = vec3(r, g, b);

    FragColor = vec4(texColor.rgb * rgbLoop, texColor.a);
}