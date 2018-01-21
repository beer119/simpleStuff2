/*
 * GameStateMachine.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */

#include "GameStateMachine.h"
#include <iostream>
using namespace std;

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
	hasChanged=true;
}

void GameStateMachine::popState()
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
	hasChanged=true;
}
void GameStateMachine::changeState(GameState *pState)
{
	if(!m_gameStates.empty())
	{
		if(m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return; // do nothing
		}
	}
	std::cout<<m_gameStates.size()<<std::endl;
	if(!m_gameStates.empty())
	{
		m_gameStates.back()->onExit();
		delete m_gameStates.back();
		m_gameStates.pop_back();
	}

	// push back our new state
	m_gameStates.push_back(pState);
	// initialise it
	m_gameStates.back()->onEnter();
	hasChanged=true;
}
void GameStateMachine::update()
{
if(!m_gameStates.empty())
{
	std::cout<<"GameStateMachine::update"<<std::endl;
	std::cout<<m_gameStates.size()<<std::endl;
	std::cout<<m_gameStates.back()->getStateID()<<std::endl;
	m_gameStates.back()->update();
}
hasChanged=false;
}
void GameStateMachine::render()
{
if(!m_gameStates.empty())
{
m_gameStates.back()->render();
}
}

