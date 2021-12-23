/**
 * @file nice_ui.h
 * @author Igor Alexey Marengo (igor@vortex-dev.com)
 * @brief Nice is a single-header C++ library that allows you to create a UI for GLFW with a simple object oriented API.
 * @brief It is designed to be flexible, easy to use and easy to understand.
 * @version 1.0
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
*/

#if !defined(__cplusplus)
#error "Nice_UI is a C++ header file. You should use C++ in order to compile it."
#endif

#if !defined(NICE_UI_H)
#define NICE_UI_H

#if !defined(_glfw3_h_)
#warning "It's recommended to include GLFW before Nice_UI."
#include "GLFW/glfw3.h"
#endif

/* Includes */

#include <iostream>
#include <vector>

/* Declarations */

// Enums //

enum class UI_ELEMENT_TYPE
{
    FRAME,
    IMAGE,
    BUTTON,
    TEXT_LABEL,
    TEXT_BOX,
    CHECK_BOX,
    RADIO_BUTTON
};

enum class UI_ELEMENT_STATE
{
    NORMAL,
    HOVER,
    PRESSED,
    DISABLED
};

// Structs //

struct Vector2
{
    float x;
    float y;
};

struct UDim
{
    float Scale; // Scale of the parent container from 0 to 1
    unsigned short Pixels; // Pixels of the window from 0 to a maximum of 65,535
};

struct UDim2
{
    UDim X,Y;
};


class Nice_Element
{
    private:
        UDim2 Position;
        UDim2 Size;
        std::vector<Nice_Element*> Children;
    public:
        Vector2 Anchor_Point = {0.0f,0.0f}; // Top-left corner of the element
        UI_ELEMENT_TYPE Type;
        UI_ELEMENT_STATE State;

};

// Classes //

/**
 * @brief Nice_Context is a container for all UI elements and context-related for a single window
 * Nice_Context is a container for all UI elements and context-related funtions for a single window, it should be created using New_Context()
 * and Destroyed using context->Destroy();
*/
class Nice_Context
{
    private:
        std::vector<Nice_Element> elements;

    public:
        GLFWwindow* window;
        void Update();
        void Render();
        void Destroy(); 
};

// Functions //

// Create a new Nice_Context in the list of contexts, and returns a pointer to the new context.
Nice_Context* New_Context(GLFWwindow* = glfwGetCurrentContext());

// Get the mouse position inside the window
Vector2 Get_Mouse_Position_Relative_To_Window(GLFWwindow* = glfwGetCurrentContext());

// Only one of these should be defined at a time.
#if defined(NICE_UI_IMPLEMENTATION) ^ defined(NICE_UI_DECLARATIONS_ONLY)

/* Implementation Code */ 

std::vector<Nice_Context> Nice_Contexts;

void Nice_Context::Update()
{
    // Update all UI elements
    for (Nice_Element element : elements)
    {
        
    }
}

void Nice_Context::Render()
{
    // Render all UI elements
    for (Nice_Element element : elements)
    {
        
    }
}

void Nice_Context::Destroy()
{
    delete this;
}

Nice_Context* New_Context(GLFWwindow* window)
{
    // Create new context directly inside the Nice_Contexts vector.
    Nice_Contexts.push_back(Nice_Context());
    Nice_Contexts.back().window = window;
    return &Nice_Contexts.back();
}

Vector2 Get_Mouse_Position_Relative_To_Window(GLFWwindow* window)
{
    // Get mouse position relative to the window using glfwGetCursorPos() and return it as a Vector2
    double x,y;
    glfwGetCursorPos(window,&x,&y);
    return Vector2{(float)x,(float)y};
}

/* End of Implementation */

#elif !defined(NICE_UI_IMPLEMENTATION) && !defined(NICE_UI_DECLARATIONS_ONLY)
#warning "Nice_UI is included but not implemented, you should define NICE_UI_IMPLEMENTATION or NICE_UI_DECLARATIONS_ONLY before including this file."
#elif defined(NICE_UI_IMPLEMENTATION) && defined(NICE_UI_DECLARATIONS_ONLY)
#error "Nice_UI is included both as a declaration and an implementation, this is not supported."
#endif /* NICE_UI_IMPLEMENTATION */

#else
#warning "nice_ui.h already included somewhere else, remove this one or check your includes."
#endif /* NICE_UI_H */