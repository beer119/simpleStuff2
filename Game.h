#ifndef __Game__
#define __Game__
#include<SDL.h>
#include "GameObject/Player.h"
#include "GameObject/GameObject.h"
#include <vector>
#include "States/GameStateMachine.h"
//#include "TextureManager.h"
class Game
{
public:

~Game() {}
bool init(const char*, int, int, int ,int , int);
void render();
void update();
void handleEvents2();
void clean();
// a function to access the private running variable
bool running() { return m_bRunning; }
private:
SDL_Window* m_pWindow;
SDL_Renderer* m_pRenderer;
int m_currentFrame;
private:
Game()
{
	m_bRunning=false;
}
// create the s_pInstance member variable
static Game* s_pInstance;



public:
SDL_Renderer* getRenderer() {return  m_pRenderer;}


static Game* Instance()
{
	if(s_pInstance == 0)
	{
		s_pInstance = new Game();
		return s_pInstance;
	}

	return s_pInstance;
}
GameStateMachine* m_pGameStateMachine;
GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }


bool m_bRunning;
};
// create the typedef
typedef Game TheGame;

#endif /* defined(__Game__) */


