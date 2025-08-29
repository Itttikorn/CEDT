#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <learnopengl/shader_s.h>

#include <iostream>
#include <numbers>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

static float* calculateVertices(int triangleCount) {
    // Each triangle has 3 vertices, each vertex has 6 floats (3 position + 3 color)
    float* vertices = new float[triangleCount * 3 * 6];

    float radius = 0.9f; // Circle radius
    float centerX = 0.0f;
    float centerY = 0.0f;

    for (int i = 0; i < triangleCount; ++i) {
        float angle1 = 2.0f * std::numbers::pi_v<float> *i / triangleCount;
        float angle2 = 2.0f * std::numbers::pi_v<float> *(i + 1) / triangleCount;

        // Tip (center of circle)
        vertices[i * 18 + 0] = centerX;
        vertices[i * 18 + 1] = centerY;
        vertices[i * 18 + 2] = 0.0f;
        vertices[i * 18 + 3] = 0.0f;
        vertices[i * 18 + 4] = 0.0f;
        vertices[i * 18 + 5] = 0.0f;

        // First base vertex (on circumference)
        vertices[i * 18 + 6] = centerX + radius * cos(angle1);
        vertices[i * 18 + 7] = centerY + radius * sin(angle1);
        vertices[i * 18 + 8] = 0.0f;
        vertices[i * 18 + 9] = 1.0f;
        vertices[i * 18 + 10] = 0.0f;
        vertices[i * 18 + 11] = 0.0f;

        // Second base vertex (on circumference)
        vertices[i * 18 + 12] = centerX + radius * cos(angle2);
        vertices[i * 18 + 13] = centerY + radius * sin(angle2);
        vertices[i * 18 + 14] = 0.0f;
        vertices[i * 18 + 15] = 0.0f;
        vertices[i * 18 + 16] = 0.0f;
        vertices[i * 18 + 17] = 1.0f;
    }
    return vertices;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
int triangleCount = 1;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    Shader ourShader("3.3.shader.vs", "3.3.shader.fs"); // you can name your shader files however you like

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    //float vertices[] = {
    //    // positions         // colors
    //     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
    //    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
    //     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
    //};

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); // set the vertex attribute pointers (stride = 6 * sizeof(float) because we have 6 floats per vertex: 3 for position and 3 for color)
    glEnableVertexAttribArray(0);
    // color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float))); // set the vertex attribute pointers (stride = 6 * sizeof(float) because we have 6 floats per vertex: 3 for position and 3 for color | (void*)(3 * sizeof(float)) determine the 3 bytes offset for color data)
    glEnableVertexAttribArray(1);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    // glBindVertexArray(0);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        float* vertices = calculateVertices(triangleCount);
        glBufferData(GL_ARRAY_BUFFER, triangleCount * 6 * 3 * sizeof(float), vertices, GL_STATIC_DRAW);
        delete[] vertices;

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // render the triangle
        ourShader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3 * triangleCount);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    static bool enterWasPressed = false;
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    {
        if (!enterWasPressed)
        {
            triangleCount++;
            enterWasPressed = true;
            cout << "Triangle count: " << triangleCount << endl;

            float* vertices = calculateVertices(triangleCount);
            int vertexCount = triangleCount * 3;
            for (int i = 0; i < vertexCount; i += 3) {
                cout << "Triangle " << (i / 3) + 1 << " Top : ("
                    << vertices[i * 3 + 0] << ", "
                    << vertices[i * 3 + 1] << ", "
                    << vertices[i * 3 + 2] << ")" << endl;
                cout << "Triangle " << (i / 3) + 1 << " Left : ("
                    << vertices[i * 3 + 3] << ", "
                    << vertices[i * 3 + 4] << ", "
                    << vertices[i * 3 + 5] << ")" << endl;
                cout << "Triangle " << (i / 3) + 1 << " Right : ("
                    << vertices[i * 3 + 6] << ", "
                    << vertices[i * 3 + 7] << ", "
                    << vertices[i * 3 + 8] << ")" << endl;
            }
            delete[] vertices;
        }
    }
    else
    {
        enterWasPressed = false;
    }
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
