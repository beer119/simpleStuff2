#include "InputHandler.h"
#include "Game.h"
using namespace std;
InputHandler* InputHandler::s_pInstance = 0;

InputHandler::InputHandler()
{
	for(int i = 0; i < 3; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition=new Vector2D;

}
bool InputHandler::isKeyDown(SDL_Scancode key)
{
if(m_keystates != 0)
{
if(m_keystates[key] == 1)
{
return true;
}
else
{
return false;
}
}
return false;
}

void InputHandler::update()
{
	m_keystates = SDL_GetKeyboardState(0);

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			Game::Instance()->clean();
		}

		if(event.type == SDL_MOUSEBUTTONDOWN)
		{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
		m_mouseButtonStates[LEFT] = true;

		}
		if(event.button.button == SDL_BUTTON_MIDDLE)
		{
		m_mouseButtonStates[MIDDLE] = true;
		}
		if(event.button.button == SDL_BUTTON_RIGHT)
		{
		m_mouseButtonStates[RIGHT] = true;
		}
		}
		if(event.type == SDL_MOUSEBUTTONUP)
		{
		if(event.button.button == SDL_BUTTON_LEFT)
		{
		m_mouseButtonStates[LEFT] = false;
		std::cout<<"left false"<<std::endl;
		}
		if(event.button.button == SDL_BUTTON_MIDDLE)
		{
		m_mouseButtonStates[MIDDLE] = false;
		}
		if(event.button.button == SDL_BUTTON_RIGHT)
		{
		m_mouseButtonStates[RIGHT] = false;
		}
		}
		if(event.type == SDL_MOUSEMOTION)
		{
		m_mousePosition->setX(event.motion.x);
		m_mousePosition->setY(event.motion.y);
		}

	}

}

