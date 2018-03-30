/*
 * GameState.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */




#include "MenuState.h"
#include <iostream>
#include "../Game.h"
#include "../GameObject/MenuButton.h"
#include "PlayState.h"
#include <iostream>

#include "../TextureManager.h"
using namespace std;
const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
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
void MenuState::render()
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
bool MenuState::onEnter()
{
	bool loaded =TextureManager::getInstance()->load("images/spritelib_gpl/fishdish/fishbaddie_parts.png","fishbaddie_parts1",TheGame::Instance()->getRenderer());

	if(!loaded)
	{
	return false;
	}
	loaded =TextureManager::getInstance()->load("images/spritelib_gpl/fishdish/fishbaddie_parts.png","fishbaddie_parts2",TheGame::Instance()->getRenderer());
	if(!loaded)
	{
		return false;
	}
	GameObject* button1 = new MenuButton(s_menuToPlay);
	button1->load(new LoaderParams(100, 100,	400, 100, "fishbaddie_parts1"));
	GameObject* button2 = new MenuButton(s_exitFromMenu);
	button2->load(new LoaderParams(100, 300,	400, 100, "fishbaddie_parts1"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;


}
bool MenuState::onExit()
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
void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new	PlayState());

std::cout << "Play button clicked\n";
}
void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->clean();

}

