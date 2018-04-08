/*
 * AnimatedGraphic.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#include "AnimatedGraphic.h"
using namespace std;
AnimatedGraphic::AnimatedGraphic() : SDLGameObject()
{
	m_numFrames=1;
}
void AnimatedGraphic::update()
{
m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %m_numFrames));
}

	void AnimatedGraphic::draw()
		{
				cout<<"SDL_GetTicks() "<<SDL_GetTicks()<<endl;
				cout<<"m_animSpeed"<<m_animSpeed<<endl;
				cout<<"m_numFrames"<<m_numFrames<<endl;
				m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %m_numFrames));
		}
	void AnimatedGraphic::clean()
	{

	}
	void AnimatedGraphic::load(const LoaderParams *pParams)
	{
	SDLGameObject::load(pParams);
	m_animSpeed = pParams->getAnimSpeed();
	}

