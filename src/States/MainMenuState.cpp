/*
 * GameState.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */




#include <iostream>
#include "../Game.h"
#include "../GameObject/MenuButton.h"
#include "../XML/StateParser.h"
#include "PlayState.h"
#include <iostream>

#include "../TextureManager.h"
#include "MainMenuState.h"
using namespace std;
const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		if(TheGame::Instance()->getStateMachine()->hasChanged==false)
			m_gameObjects[i]->update();
		else
			break;
	}

// nothing for now
}
void MainMenuState::render()
{

	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		if(TheGame::Instance()->getStateMachine()->hasChanged==false)
			m_gameObjects[i]->draw();
		else
		{
			cout<<"< "<<endl;
		}
	}


}
bool MainMenuState::onEnter()
{

	std::cout << "entering MenuState\n";
	// clear the texture manager

	std::cout << "entering MenuState2\n";
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::getInstance()->	clearFromTextureMap(m_textureIDList[i]);
	}
	std::cout << "done clearing of texture \n";
	// parse the state
	StateParser stateParser;
	stateParser.parseState("setupfiles/test.xml", s_menuID, &m_gameObjects, &m_textureIDList);

	m_callbacks.push_back(0); //pushback 0 callbackID start from 1
	m_callbacks.push_back(s_menuToPlay);
	m_callbacks.push_back(s_exitFromMenu);
	// set the callbacks for menu items
	setCallbacks(m_callbacks);
	std::cout << "entering MenuState\n";
	return true;

	return true;


}
void MainMenuState::setCallbacks(const std::vector<Callback>& callbacks)
{
	// go through the game objects
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		// if they are of type MenuButton then assign a callback		based on the id passed in from the file
		if(dynamic_cast<MenuButton*>(m_gameObjects[i]))
		{
			MenuButton* pButton =
			dynamic_cast<MenuButton*>(m_gameObjects[i]);
			pButton->setCallback(callbacks[pButton->getCallbackID()]);
		}
	}
}

bool MainMenuState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
	m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TextureManager::getInstance()->clearFromTextureMap("playbutton1");
	TextureManager::getInstance()->clearFromTextureMap("exitbutton2");

	return true;
}

void MainMenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new	PlayState());

std::cout << "Play button clicked\n";
}
void MainMenuState::s_exitFromMenu()
{
	TheGame::Instance()->clean();

}

