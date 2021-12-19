#include <iostream>
#include <GLFW/glfw3.h>
#define NICE_UI_IMPLEMENTATION
#include "nice_ui.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
    window = glfwCreateWindow(800, 600, "Nice_UI Example application", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Create a Nice_Context
    Nice_Context* context = New_Context();

    // Design interface before loop

    while (!glfwWindowShouldClose(window))
    {
        // Update UI
        context->Update();
        
        glClear(GL_COLOR_BUFFER_BIT);

        // Render all UI elements
        context->Render();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    context->Destroy();
    glfwTerminate();
    return 0;
}