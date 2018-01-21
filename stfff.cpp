#include "Game.h"
#include "InputHandler.h"
int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int DELAY_TIME = 1000.0f / FPS;
	Uint32 frameStart, frameTime;
	Game::Instance()->init("Chapter 1", 100, 100, 1000, 1000, SDL_WINDOW_MAXIMIZED);
	while(Game::Instance()->running())
	{

		frameStart = SDL_GetTicks();
		TheInputHandler::Instance()->update();
		Game::Instance()->handleEvents2();
		Game::Instance()->update();
		Game::Instance()->render();
		frameTime = SDL_GetTicks() - frameStart;
		if(frameTime< DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

	}

	Game::Instance()->clean();


}
