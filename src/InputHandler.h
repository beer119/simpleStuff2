/*
 * InputHandler.h
 *
 *  Created on: Jan 15, 2018
 *      Author: beer
 */

#ifndef INPUTHANDLER_H_
#define INPUTHANDLER_H_
#include <vector>
#include "Vector2D.h"
#include "SDL.h"
enum mouse_buttons
{
LEFT = 0,
MIDDLE = 1,
RIGHT = 2
};

class InputHandler
{
private:
	InputHandler();
	~InputHandler(){}
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;
	const Uint8* m_keystates;

	static InputHandler* s_pInstance;
public:
	bool isKeyDown(SDL_Scancode key);
	static InputHandler* Instance()
	{
		if(s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}
	Vector2D* getMousePosition()
	{
	return m_mousePosition;
	}

	void update();
	void clean();
	bool getMouseButtonState(int buttonNumber)
	{
	return m_mouseButtonStates[buttonNumber];
	}


};
typedef InputHandler TheInputHandler;



#endif /* INPUTHANDLER_H_ */
