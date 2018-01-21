/*
 * MenuState.h
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#ifndef MENUSTATE_H_
#define MENUSTATE_H_


#include "GameState.h"
#include "../GameObject/GameObject.h"
#include <vector>
class MenuState : public GameState
{

public:
virtual void update();
virtual void render();
virtual bool onEnter();
virtual bool onExit();
virtual std::string getStateID() const { return s_menuID; }
private:
std::vector<GameObject*> m_gameObjects;
private:
static void s_menuToPlay();
static void s_exitFromMenu();

static const std::string s_menuID;
};


#endif /* MENUSTATE_H_ */
