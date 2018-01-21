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
#include "GameState.h"
class GameObject;

class PauseState : public GameState
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

};



#endif /* PAUSESTATE_H_ */
