#include <iostream>
#include "GLFW/glfw3.h"
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

    // Create a Nice_UI Context
    Nice_Context* context = new Nice_Context();
    Nice_Frame* frame, topbar;
    Nice_Button* closebutton, togglebutton;
    Nice_Label* title, content;
    /*
    context->AddElement("Nice_UI Window", &frame);
    frame->AddElement("Topbar", &topbar);
    topbar->AddElement("Close Button", &closebutton);

    // Design interface before loop

    frame->Anchor_Point = Vector2{0.5f, 0.5f}; // The default anchor point is at the top left corner of the frame, this centers it to the middle.
    frame->Position = UDim2{0.5f, 0.0f, 0.5f, 0.0f}; // Screen centered
    frame->Size = UDim2{0.5f, 0.0f, 0.8f, 0.0f}; //  size in Scale and offset(pixels). Offset decimals are discarded.
    frame->Background_Color = Vector4{0.1f, 0.1f, 0.1f, 1.0f}; // Dark gray background (RGBA)

    Nice_Button* button = frame->AddElement(UI_ELEMENT_TYPE::BUTTON);

    button->Text = "Click me!";
    button->Position = UDim2{0.0f, 0.0f, 0.0f, 0.0f}; // Top left corner
    button->Size = UDim2(1.0f, 0.0f, 0.1f, 0.0f); // Full width, 10% height
    button->Background_Color = Vector4{0.0f, 0.0f, 1.0f, 1.0f}; // Blue background (RGBA)*/

    while (!glfwWindowShouldClose(window))
    {
        // resize viewport to match window size
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        // Update UI
        //context->Update();
        
        glClear(GL_COLOR_BUFFER_BIT);

        // Render all UI elements
        //context->Render()

        glfwSwapBuffers(window);    

        glfwPollEvents();
    }
    context->Destroy();
    glfwTerminate();
    return 0;
}