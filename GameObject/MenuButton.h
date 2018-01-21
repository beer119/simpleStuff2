/*
 *  MenuButton.h
 *
 *  Created on: Jan 18, 2018
 *      Author: beer
 */

#ifndef MENUBUTTON_H_
#define MENUBUTTON_H_
#include "SDLGameObject.h"
enum button_state
{
MOUSE_OUT = 0,
MOUSE_OVER = 1,
CLICKED = 2
};


class MenuButton : public SDLGameObject
{
public:
MenuButton(void (*m_callback)());
virtual void draw();
virtual void update();
virtual void clean();
void (*m_callback)();
bool m_bReleased;



};




#endif /* MENUBUTTON_H_ */
