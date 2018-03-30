/*
 * GameStateMachine.h
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#ifndef GAMESTATEMACHINE_H_
#define GAMESTATEMACHINE_H_
#include <vector>

#include "GameState.h"
class GameStateMachine
{
public:
void pushState(GameState* pState);
void changeState(GameState* pState);
void popState();
void update();
void render();

bool hasChanged=false;
private:

std::vector<GameState*> m_gameStates;

};



#endif /* GAMESTATEMACHINE_H_ */
