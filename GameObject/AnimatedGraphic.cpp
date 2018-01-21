/*
 * AnimatedGraphic.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#include "AnimatedGraphic.h"
AnimatedGraphic::AnimatedGraphic(const LoaderParams* pParams, int animSpeed) : SDLGameObject(), m_animSpeed(animSpeed)
{
}
void AnimatedGraphic::update()
{
m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %m_numFrames));
}

	void AnimatedGraphic::draw()
		{
		m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) %m_numFrames));
		}
	void AnimatedGraphic::clean()
	{

	}
