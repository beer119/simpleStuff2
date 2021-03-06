/*
 * AnimatedGraphic.h
 *
 *  Created on: Jan 20, 2018
 *      Author: beer
 */

#ifndef ANIMATEDGRAPHIC_H_
#define ANIMATEDGRAPHIC_H_
#include "SDLGameObject.h"


class AnimatedGraphic : public SDLGameObject // inherit from GameObject
{
public:

	AnimatedGraphic();

	virtual void draw();
	virtual void update();
	virtual void clean();
	int m_animSpeed;
	int m_numFrames;
	void load(const LoaderParams *pParams);

};

#endif /* ANIMATEDGRAPHIC_H_ */
