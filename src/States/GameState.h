/*
 *  GameState.h
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include<string>
class GameState
{
public:
virtual void update() = 0;
virtual void render() = 0;
virtual bool onEnter() = 0;
virtual bool onExit() = 0;
virtual std::string getStateID() const = 0;
};




#endif /* GAMESTATE_H_ */
