/**
 * @file docking.cpp
 * @author Igor Alexey Marengo (igor@vortex.com)
 * @brief This configurable extension for Nice_UI allows docking of Frames to all sides of the viewport 
 * @version 0.1
 * @date 2021-12-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// Specify that we are getting only the declarations since we don't actually need any of the functionality that already comes with Nice_UI
// otherwise we would get a no-implementation warning.
#define NICE_UI_DECLARATIONS_ONLY
#include "nice_ui.h"

/**
 * @brief The docking frame behaves like a normal frame, with the addition of being dockable to the sides of the viewport and to other frames in different ways.
 * The docking frame is a frame with configurable dockspace functionality, which can be used to dock other frames to
 * the sides of the viewport and combined to other frames as different tabs, while sharing the same frame.
 * @param docking_enabled wether the frame should have docking capabilities or not. Doesn't apply to has_dockspace.
 * @param has_dockspace wether the frame should have an internal dockspace for docking other frames within it or not.
 */
class Docking_Frame : public Nice_Frame
{
    private:

    public:
        // Wether this frame should have docking capabilities or not. Does not apply to has_dockspace.
        bool docking_enabled = true;
        bool has_dockspace = false;
};