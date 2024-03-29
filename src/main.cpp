#include "iostream"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

const char* window_title = "gfx foundation";
constexpr int window_width = 1280;
constexpr int window_height = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    // Make sure the viewport matches the new window dimensions
    glViewport(0, 0, width, height);
}

int main() {
    std::cout << "Starting GLFW..." << std::endl;

    //Initialize GLFW
    if (!glfwInit()) {
        // Initialization failed
        std::cout << "glfwInit -> Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title, nullptr, nullptr);
    if (!window) {
        // Window creation failed
        std::cout << "glfwCreateWindow -> Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the OpenGL version to 4.6 and use the core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    // Forward compatibility with macOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, window_width, window_height);

    // Register the framebuffer_size_callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)) {
        // @TODO -> Render stuff here

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up GLFW before exiting
    std::cout << "Terminating GLFW..." << std::endl;
    glfwTerminate();
    return 0;
}