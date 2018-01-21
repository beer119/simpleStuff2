#include "Game.h"
#include <SDL_image.h>
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "GameObject/Enemy.h"
#include "InputHandler.h"
#include "States/MenuState.h"
#include "States/PlayState.h"
using namespace std;
Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{
	// attempt to initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
	std::cout << "SDL init success5\n";

	m_pWindow = SDL_CreateWindow(title, xpos, ypos,width, height, flags);
	std::cout << "m_pWindow\n";
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
	std::cout << "init successqq33\n";
	m_bRunning = true; // everything inited successfully,	start the main loop

	TextureManager::getInstance()->load("spritelib_gpl/fishdish/fishbaddie_parts.png","fishbaddie_parts",m_pRenderer);



	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());


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

