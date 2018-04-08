/*
 * PauseState.h
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_
#include <string>
#include <vector>
#include "../GameObject/GameObject.h"
#include "MenuState.h"
#include <iostream>
#include <SDL.h>
class GameObject;

class PauseState : public MenuState
{
	public:
	virtual void update();

	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_pauseID;}
	private:
	static void s_pauseToMain();
	static void s_resumePlay();
	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;
	virtual void setCallbacks(const std::vector<Callback>& callbacks);


};



#endif /* PAUSESTATE_H_ */
