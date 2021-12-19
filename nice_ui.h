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

#ifndef __cplusplus
#error "Nice_UI is a C++ header file. Please use C++ to compile it."
#endif

#ifndef NICE_UI_H
#define NICE_UI_H

#include <iostream>
#include <vector>

/* Declarations */

// Enums //

enum class UI_ELEMENT_TYPE
{
    FRAME,
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
    unsigned int Pixels;
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
        Vector2 Anchor_Point;
        std::vector<Nice_Element*> Children;
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
        GLFWwindow* window;
        std::vector<Nice_Element*> elements;
        
    public:
        Nice_Context();
        ~Nice_Context();
        void Update(); // Update all UI elements, should be called once per frame.
        void Render(); // Draw all the UI elements on the context's stack.
        void Destroy(); // Destroy the context and all its elements from memory.
};

// Functions //

Nice_Context* New_Context(GLFWwindow* window = glfwGetCurrentContext());

Nice_Context* Get_Current_Context();

// Only one of these should be defined at a time.
#ifdef NICE_UI_IMPLEMENTATION ^ NICE_UI_DECLARATIONS_ONLY

/* Implementation Code */ 



void Nice_Context::Update()
{
    // Update all UI elements
    for (auto& element : elements)
    {
        //element->Update();
    }
}

void Nice_Context::Render()
{
    // Render all UI elements
    for (auto& element : elements)
    {
        //element->Render();
    }
}

void Nice_Context::Destroy()
{
    delete this;
}

#elif !defined(NICE_UI_IMPLEMENTATION) && !defined(NICE_UI_DECLARATIONS_ONLY)
#warning "Nice_UI is included but not implemented, you should define NICE_UI_IMPLEMENTATION or NICE_UI_DECLARATIONS_ONLY before including this file."
#elif defined(NICE_UI_IMPLEMENTATION) && defined(NICE_UI_DECLARATIONS_ONLY)
#error "Nice_UI is included both as a declaration and an implementation, this is not supported."
#endif /* NICE_UI_IMPLEMENTATION */

#else
#warning "nice_ui.h already included somewhere else, remove this one or check your includes."
#endif /* NICE_UI_H */