#ifndef NICE_UI_H
#define NICE_UI_H

#include <iostream>
#include <vector>

/* Declarations */

void Render(void);

#ifdef NICE_UI_IMPLEMENTATION

/* Implementation */ 

void Render()
{

}


#endif /* NICE_UI_IMPLEMENTATION */

#else
#error "nice_ui.h already included somewhere, please check your includes!"
#endif /* NICE_UI_H */