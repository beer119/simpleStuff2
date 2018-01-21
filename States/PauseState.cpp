/*
 * PauseState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */
#include "PauseState.h"

#include "../Game.h"
#include "MenuState.h"
#include "../GameObject/MenuButton.h"
#include "../InputHandler.h"

const std::string PauseState::s_pauseID = "PAUSE";
void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MenuState());
}
void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}
void PauseState::update()
{
for(int i = 0; i < m_gameObjects.size(); i++)
{
m_gameObjects[i]->update();
}
}
void PauseState::render()
{
for(int i = 0; i < m_gameObjects.size(); i++)
{
m_gameObjects[i]->draw();
}
}
bool PauseState::onEnter()
{

GameObject* button1 = new MenuButton( s_pauseToMain);
button1->load(new LoaderParams(300, 100,200, 80, "fishbaddie_parts"));
GameObject* button2 = new MenuButton(s_resumePlay);
button1->load(new LoaderParams(300, 300,200, 80, "fishbaddie_parts"));
m_gameObjects.push_back(button1);
m_gameObjects.push_back(button2);
std::cout << "entering PauseState\n";
return true;
}
bool PauseState::onExit()
{
for(int i = 0; i < m_gameObjects.size(); i++)
{
m_gameObjects[i]->clean();
}
m_gameObjects.clear();


std::cout << "exiting PauseState\n";
return true;
}
