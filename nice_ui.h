/**
 * @file nice_ui.h
 * @author vortex-dev.com
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

struct Vector2
{
    float x, y;
};

struct UDim
{
    float Scale;
    int Offset;
};

/**
 * @brief 
 * 
 */
struct UDim2
{
    Vector2 x,y;
};


/* Forward Declarations */

class Nice_Context;
class Nice_Element;
class Nice_Frame;
class Nice_Image;
class Nice_Button;
class Nice_Label;
class Nice_TextField;

// Only one of these should be defined at a time.
#if defined(NICE_UI_IMPLEMENTATION) ^ defined(NICE_UI_DECLARATIONS_ONLY)

/* Implementation Code */ 

std::vector<Nice_Context*> Contexts;

class Nice_Context {
    private:
        std::vector<Nice_Element> Elements;
    public:
        Nice_Context()
        {
            Contexts.push_back(this);
        }
        void AddElement(Nice_Element* element)
        {
            // create a new element and then add it to the stack, and then return a pointer to it.

        }

};

class Nice_Element {
    private:

    public:
        Nice_Element()
        {
            //
        }
        void AddElement(Nice_Element* element)
        {
            
        }

};

class Nice_Frame : Nice_Element {

};

class Nice_Image : Nice_Frame {

};

class Nice_Button : Nice_Frame {

};

class Nice_Label : Nice_Frame {

};

class Nice_TextField : Nice_Label {

};

/* End of Implementation */

#elif !defined(NICE_UI_IMPLEMENTATION) && !defined(NICE_UI_DECLARATIONS_ONLY)
#warning "Nice_UI is included but not implemented, you should define NICE_UI_IMPLEMENTATION or NICE_UI_DECLARATIONS_ONLY before including this file."
#elif defined(NICE_UI_IMPLEMENTATION) && defined(NICE_UI_DECLARATIONS_ONLY)
#error "Nice_UI is included both as a declaration and an implementation, this is not supported."
#endif /* NICE_UI_IMPLEMENTATION */

#else
#warning "nice_ui.h already included somewhere else, remove this one or check your includes."
#endif /* NICE_UI_H */