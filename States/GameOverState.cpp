/*
 * GameOverState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#include "../Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "GameOverState.h"
#include "../LoaderParams.h"
#include "../GameObject/AnimatedGraphic.h"
#include "../GameObject/MenuButton.h"
#include <iostream>
using namespace std;
const std::string GameOverState::s_gameOverID = "GAMEOVER";
void GameOverState::s_gameOverToMain()
{
TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}
void GameOverState::s_restartPlay()
{
TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}
bool GameOverState::onEnter()
{
	std::cout << "entering GameOverState\n";
//GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "fishbaddie_parts"), 2);
GameObject* button1 = new MenuButton(s_gameOverToMain);
button1->load(new LoaderParams(200, 200, 200, 80, "fishbaddie_parts"));
GameObject* button2 = new MenuButton(s_restartPlay);
button2->load(new LoaderParams(200, 500,200, 80, "fishbaddie_parts"));
//m_gameObjects.push_back(gameOverText);
m_gameObjects.push_back(button1);
m_gameObjects.push_back(button2);
std::cout << "setup GameOverState\n";
return true;
}


bool GameOverState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
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
	for(int i = 0; i < m_gameObjects.size(); i++)
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
for(int i = 0; i < m_gameObjects.size(); i++)
{
m_gameObjects[i]->draw();
}
}
