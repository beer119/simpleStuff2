/*
 * GameState.cpp
 *
 *  Created on: Jan 17, 2018
 *      Author: beer
 */




#include "MainMenuState.h"
#include <iostream>
#include "PlayState.h"
#include "../GameObject/Player.h"
#include "../GameObject/Enemy.h"
#include "../InputHandler.h"
#include "../XML/StateParser.h"
#include "../Game.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "../TextureManager.h"
const std::string PlayState::s_playID = "PLAY";
void PlayState::update()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}
	if(checkCollision(dynamic_cast<SDLGameObject*>	(m_gameObjects[0]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
	}



}
void PlayState::render()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}
bool PlayState::onEnter()
{
/*	GameObject* p=new Player();
	p->load(new LoaderParams(100, 100, 128, 82,"fishbaddie_parts"));
	m_gameObjects.push_back(p);
	GameObject* e=new Enemy();
	e->load(new LoaderParams(300, 300, 128, 82,"fishbaddie_parts"));
	m_gameObjects.push_back(e);

*/
	// parse the state
	StateParser stateParser;
	stateParser.parseState("setupfiles/test.xml", s_playID, &m_gameObjects,
	&m_textureIDList);

	std::cout << "entering PlayState\n";
	return true;
}
bool PlayState::onExit()
{
	for(int i = 0; i < m_gameObjects.size(); i++)
	{
			m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	for(int i = 0; i < m_textureIDList.size(); i++)
	{
		TextureManager::getInstance()->clearFromTextureMap(m_textureIDList[i]);
	}


std::cout << "exiting PlayState\n";
return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject*
p2)
{
int leftA, leftB;
int rightA, rightB;
int topA, topB;
int bottomA, bottomB;
leftA = p1->getPosition().getX();
rightA = p1->getPosition().getX() + p1->getWidth();
topA = p1->getPosition().getY();
bottomA = p1->getPosition().getY() + p1->getHeight();
//std::cout<<leftA<<" "<<rightA<<" "<<topA<< " "<<bottomA<<std::endl;
//Calculate the sides of rect B
leftB = p2->getPosition().getX();
rightB = p2->getPosition().getX() + p2->getWidth();
topB = p2->getPosition().getY();
bottomB = p2->getPosition().getY() + p2->getHeight();
//std::cout<<leftB<<" "<<rightB<<" "<<topB<< " "<<bottomB<<std::endl;
//If any of the sides from A are outside of B
if( bottomA <= topB ){
	return false;}
if( topA >= bottomB ){
	return false; }
if( rightA <= leftB ){
	return false; }
if( leftA >= rightB ){
	return false;}
return true;
}

