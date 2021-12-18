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

#ifndef NICE_UI_H
#define NICE_UI_H

#include <iostream>
#include <vector>

/* Declarations */

// Structs //

struct Nice_Element
{

};

// Classes //

class Nice_Context
{
    private:
        GLFWwindow* window;
        std::vector<Nice_Element*> elements;
    public:
        Nice_Context();
        ~Nice_Context();
        void Update();
        void Render();
        void Destroy();
};

// Functions //

/*
* @brief This creates a new context for a single GLFW window.
* @param window The GLFW window to create a Nice_UI context for, if null, the current GLFW context will be used.
* @return A pointer to the new Nice_Context.
*/
Nice_Context* New_Context(GLFWwindow* window = glfwGetCurrentContext());

/*
* @brief Draw all the UI elements on the current context's stack.
*/

#ifdef NICE_UI_IMPLEMENTATION

/* Implementation Code */ 

// Define Update from Nice_Context class
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


#else
#warning "Nice_UI is included but not implemented, you should define NICE_UI_IMPLEMENTATION before including this file."
#endif /* NICE_UI_IMPLEMENTATION */

#else
#error "nice_ui.h already included somewhere else, remove this one or check your includes."
#endif /* NICE_UI_H */