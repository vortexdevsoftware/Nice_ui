/**
 * @file nice_ui.h
 * @author @Sororfortuna @wTechnoo
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

enum class UI_
{
    
};

struct Vector2
{
    float x, y;
};

/**
 * @brief Universal Dimension, used to specify size and position of UI elements in one axis.
 * @param Scale is a number between 0.0 and 1.0 as a percentage of the parent object's size.
 * @param Offset is an integer value that is added to the parent object's size.
 */
struct UDim
{
    float scale;
    int offset;
};

/**
 * @brief Universal Dimension 2D, used to specify size and position of UI elements in two axes, using 2 UDim values.
 * @param X is a UDim value for the X axis.
 * @param Y is a UDim value for the Y axis.
 */
struct UDim2
{
    UDim x,y;
};

struct RGBA
{
    float r, g, b, a;
};


/* Forward Declarations */

class Nice_Context;
class Nice_Element;
class Nice_Frame;
class Nice_Image;
class Nice_Label;
class Nice_Button;
class Nice_TextField;

// Only one of these should be defined at a time.
#if defined(NICE_UI_IMPLEMENTATION) ^ defined(NICE_UI_DECLARATIONS_ONLY)

/* Implementation Code */ 

std::vector<Nice_Context*> Contexts;

/**
 * @brief Nice_Context is the main class of the library.
 * The Nice_Context class is the base class of the element system
 * 
 */
class Nice_Context {
    private:
        std::vector<Nice_Element> Elements;
    public:
        Nice_Context()
        {
            Contexts.push_back(this);
        }
        void AddElement(const char* Name, Nice_Element* element)
        {
            // create a new element and then add it to the stack, and then return a pointer to it.

        }
        void Update()
        {
            // Update all elements in the context   
        }
        // Deallocates the entire context, including all elements within it.
        void Destroy()
        {
            // Destroy this context
            delete this;
        }

};

/**
 * @brief Nice_Element is the base class of all UI elements.
 * @param Tags Tags are an additional way of denoting and identifying a UI element.
 * 
 */
class Nice_Element {
    private:
        std::vector<Nice_Element> Elements;
        // Tags are an additional way of denoting and identifying a UI element.
        std::vector<const char*> Tags;
    public:
        UDim2 Size = {{0.0, 100}, {0.0, 100}};
        UDim2 Position = {{0.0f, 0}, {0.0f, 0}};
        RGBA Color = {0,0,0,0};
        Nice_Element()
        {
            //
        }
        void AddElement(const char* name, Nice_Element*& element)
        {
            
        }
        // Returns a copy of this Element and all its children.
        Nice_Element* Clone()
        {
            return this;
        }
        /**
         * @brief Adds a tag to this element.
         * Add a custom user-given tag to this element.
         * @param tag 
         */
        void AddTag(const char* tag)
        {
            Tags.push_back(tag);
        }
        /**
         * @brief Remove the first tag with specified name from the element.
         * 
         * @param tag The name of the tag to remove.
         * @return 0 if tag was successfully removed, 1 if tag was not found.
         */
        int RemoveTag(const char* tag)
        {
            // Loop through the Tags vector
            // If the tag is found, remove it from the vector and return 0 (success)
            for (int i = 0; i < Tags.size(); i++)
            {
                if (strcmp(Tags[i], tag) == 0)
                {
                    Tags.erase(Tags.begin() + i);
                    return 0;
                }
            }
            return 1;
        }
        // Deallocate the element and all its elements.
        void Destroy()
        {
            delete this;
        }

};

class Nice_Frame : Nice_Element {
    private:

    public:


};

class Nice_Image : Nice_Frame {

};


class Nice_Label : Nice_Frame {
    private:

    public:
    const char* Text;
};

class Nice_Button : Nice_Label {
    private:

    public:
    void OnClick()
    {
        //
    }
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