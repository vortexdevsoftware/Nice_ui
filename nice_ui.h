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
    float x, y;
};

struct Vector4
{
    float x, y, z, w;
};

struct UDim
{
    float
    Scale, // Scale of the parent container from 0 to 1
    Pixels; // Pixels of the window from 0 to a maximum of 65,535
};

struct UDim2
{
    UDim X,Y;
};

struct ElementPack
{
    std::vector<Nice_Frame> Frames;
    std::vector<Nice_Image> Images;
};


// Classes //

class Nice_Frame
{
    public:
        ElementPack Children;
        std::string Name;
        bool Visible;
        int ZIndex;
        UDim2 Position;
        UDim2 Size;
        Vector2 Anchor_Point;
        Vector4 Background_Color;
        UI_ELEMENT_STATE State;
        Nice_Frame() {Name = "Frame"; Position = {0.0f,0.0f}; Size = {100.0f,100.0f}; Anchor_Point = {0.0f,0.0f}; Background_Color = {1.0f,1.0f,1.0f,0.0f};}
        virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Frame*);
        virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Image*);
        virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Button*);
        virtual ElementPack* GetChildren();
};

class Nice_Image
{
    ElementPack Children;
    std::string Name;
    bool Visible;
    int ZIndex;
    UDim2 Position;
    UDim2 Size;
    Vector2 Anchor_Point;
    Vector4 Background_Color;
    Vector4 Image_Color;
    UI_ELEMENT_STATE State;
    Nice_Image() {Name = "Image"; Position = {0.0f,0.0f}; Size = {100.0f,100.0f}; Anchor_Point = {0.0f,0.0f}; Background_Color = {1.0f,1.0f,1.0f,0.0f}; Image_Color = {1.0f,1.0f,1.0f,1.0f};}
    virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Frame*);
    virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Image*);
    virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Button*);
    virtual ElementPack* GetChildren();
};

class Nice_Button
{
    public:
        ElementPack Children;
        std::string Name;
        bool Visible;
        int ZIndex;
        UDim2 Position;
        UDim2 Size;
        Vector2 Anchor_Point;
        Vector4 Background_Color;
        UI_ELEMENT_STATE State;
        Nice_Button() {Name = "Button"; Position = {0.0f,0.0f}; Size = {100.0f,100.0f}; Anchor_Point = {0.0f,0.0f}; Background_Color = {1.0f,1.0f,1.0f,0.0f};}
        virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Frame*);
        virtual void AddElement(UI_ELEMENT_TYPE, std::string, Nice_Image*);
        // Skipping AddElement(UI_ELEMENT_TYPE, std::string, Nice_Button*); since there is no reason to add a button in a button.
        virtual ElementPack* GetChildren();
};

/**
 * @brief Nice_Context is a container for all UI elements and context-related for a single window
 * Nice_Context is a container for all UI elements and context-related funtions for a single window, it should be created using New_Context()
 * and Destroyed using context->Destroy();
*/
class Nice_Context
{
    private:
        std::vector<Nice_Frame> elements;

    public:
        GLFWwindow* window;
        virtual Nice_Frame* AddFrame(std::string);
        void Update(); // Process input and update all UI elements.
        void Render(); // Render all UI elements.
        void Destroy(); // Destroy this Nice_Context and all its elements.
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

/**
 * @brief Create a new element inside the context.
 * Create a new element of specified type and name (which is not an unique identifier) inside the context.
 * @param UI_ELEMENT_TYPE
 * @param name 
 */
Nice_Frame* Nice_Context::AddFrame(std::string name)
{
    // create a new frame in the elements vector with the name, and return it
    Nice_Frame* frame = new Nice_Frame();
    frame->Name = name;
    elements.push_back(*frame);
    return frame;

}

void Nice_Context::Update()
{

}

void Nice_Context::Render()
{
    // Render all UI elements

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