#include "Game.h"
#include <SDL_image.h>
#include <SDL_image.h>
#include <iostream>
#include "GameObject/Enemy.h"
#include "GameObject/MenuButton.h"
#include "InputHandler.h"
#include "States/MainMenuState.h"
#include "States/PlayState.h"
#include "TextureManager.h"
#include "XML/MenuButtonCreator.h"
#include "XML/PlayerCreator.h"
#include "XML/EnemyCreator.h"
#include "XML/AnimatedGraphicCreator.h"

using namespace std;
Game* Game::s_pInstance = 0;

Game::Game()
{

	GameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
	GameObjectFactory::Instance()->registerType("Player", new PlayerCreator());

	GameObjectFactory::Instance()->registerType("Enemy",new EnemyCreator());

	GameObjectFactory::Instance()->registerType("AnimatedGraphic",new AnimatedGraphicCreator());


	m_bRunning=false;
	m_pRenderer=nullptr;
	m_pWindow=nullptr;
	m_pGameStateMachine=nullptr;
	m_currentFrame=0;
}
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	m_gameHeight=height;
	m_gameWidth=width;
	// attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
	std::cout << "SDL init success\n";

	m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);

	if(m_pWindow != 0) // window init success
	{
	std::cout << "window creation success\n";
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	if(m_pRenderer != 0) // renderer init success
	{
	std::cout << "renderer creation success\n";
	SDL_SetRenderDrawColor(m_pRenderer,
	255,255,255,255);
	}
	else
	{
	std::cout << "renderer init fail\n";
	return false; // renderer init fail
	}
	}
	else
	{
	std::cout << "window init fail\n";
	return false; // window init fail
	}
	}
	else
	{
	std::cout << "SDL init fail\n";
	return false; // SDL init fail
	}
	std::cout << "init success\n";
	m_bRunning = true; // everything inited successfully,	start the main loop

	TextureManager::getInstance()->load("images/spritelib_gpl/fishdish/fishbaddie_parts.png","fishbaddie_parts",m_pRenderer);

	TextureManager::getInstance()->load("images/blocks1.png","blocks1",m_pRenderer);

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MainMenuState());


	return true;

}
void Game::update()
{

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_pGameStateMachine->update();




}
void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer tothe draw color


	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // draw to the screen


}

void Game::handleEvents2()
{


	SDL_Event event;
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				m_bRunning = false;
				break;


		default:
		break;
		}
	}

}
void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	exit(0);
}

