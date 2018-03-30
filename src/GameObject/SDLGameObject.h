#ifndef SDLGameObject_H
#define SDLGameObject_H
#include <SDL.h>
#include <string>
#include <iostream>
#include "../LoaderParams.h"
#include "GameObject.h"
#include "../Vector2D.h"
class SDLGameObject: public GameObject
{
public:

	virtual void draw();
	virtual void update();
	virtual void clean(){};
	SDLGameObject();
	virtual void load(const LoaderParams* pParams);
	Vector2D getPosition(){return m_position;}
	int getWidth()
	{
		return m_width;
	}
	int getHeight()
	{
			return m_height;
	}
protected:
	virtual ~SDLGameObject() {}


std::string m_textureID;
int m_currentFrame;
int m_currentRow;
Vector2D m_position;
Vector2D m_velocity;
Vector2D m_acceleration;
int m_numFrames;
int m_width;
int m_height;

};
#endif

