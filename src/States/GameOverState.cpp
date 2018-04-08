/*
 * GameOverState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#include "../Game.h"
#include "MainMenuState.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "../LoaderParams.h"
#include "../XML/StateParser.h"
#include "../GameObject/AnimatedGraphic.h"
#include "../GameObject/MenuButton.h"
#include <iostream>
using namespace std;
const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
bool GameOverState::onEnter()
{
	std::cout << "entering GameOverState\n";
/*	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "fishbaddie_parts"), 2);
	MenuButton* button1 = new MenuButton();
	button1->load(new LoaderParams(200, 200, 200, 80, "fishbaddie_parts"));
	button1->setCallback(s_gameOverToMain);
	GameObject* button2 = new MenuButton();
	button1->setCallback(s_restartPlay);
	button2->load(new LoaderParams(200, 500,200, 80, "fishbaddie_parts"));
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "setup GameOverState\n";*/
	// parse the state
	StateParser stateParser;
	stateParser.parseState("setupfiles/test.xml", s_gameOverID, &m_gameObjects,	&m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_gameOverToMain);
	m_callbacks.push_back(s_restartPlay);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);


return true;
}


bool GameOverState::onExit()
{
	for(unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
			m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

std::cout << "exiting onExit" <<m_gameObjects.size()<<" \n" ;
return true;
}
void GameOverState::update()
{
	std::cout << "entering GameOverState update" <<m_gameObjects.size()<<"\n";
	for(unsigned int i = 0; i < m_gameObjects.size(); i++)
	{
		if(TheGame::Instance()->getStateMachine()->hasChanged==false)
			m_gameObjects[i]->update();
		else
				{
					break;
				}

	}
}
void GameOverState::render()
{
	std::cout << "entering GameOverState render\n";
for(unsigned int i = 0; i < m_gameObjects.size(); i++)
{
m_gameObjects[i]->draw();
}
}

void GameOverState::setCallbacks(const std::vector<Callback>&callbacks)
{
	// go through the game objects
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback based	on the id passed in from the file
		if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton =
			dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}
