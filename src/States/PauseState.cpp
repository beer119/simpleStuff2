/*
 * PauseState.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */
#include "PauseState.h"

#include "../Game.h"
#include "MainMenuState.h"
#include "../GameObject/MenuButton.h"
#include "../InputHandler.h"
#include "../XML/StateParser.h"

const std::string PauseState::s_pauseID = "PAUSE";
void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
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
	/*

	MenuButton* button1 = new MenuButton();
	button1->setCallback(s_pauseToMain);
	button1->load(new LoaderParams(300, 100,200, 80, "fishbaddie_parts"));

	MenuButton* button2 = new MenuButton();
	button2->setCallback(s_resumePlay);
	button1->load(new LoaderParams(300, 300,200, 80, "fishbaddie_parts"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	*/
	StateParser stateParser;
	stateParser.parseState("setupfiles/test.xml", s_pauseID, &m_gameObjects,
	&m_textureIDList);
	m_callbacks.push_back(0);
	m_callbacks.push_back(s_pauseToMain);
	m_callbacks.push_back(s_resumePlay);
	setCallbacks(m_callbacks);

	std::cout << "entering PauseState\n";
	return true;
}
void PauseState::setCallbacks(const std::vector<Callback>&callbacks)
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
