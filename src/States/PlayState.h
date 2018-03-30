/*
 * PlayState.h
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include <vector>
#include "GameState.h"
#include "../GameObject/SDLGameObject.h"
class PlayState : public GameState
{
public:
virtual void update();
virtual void render();
virtual bool onEnter();
virtual bool onExit();
virtual std::string getStateID() const { return s_playID; }
private:
static const std::string s_playID;
std::vector<GameObject*> m_gameObjects;
bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

};



#endif /* PLAYSTATE_H_ */
