/*
 * AnimatedGraphicCreator.h
 *
 *  Created on: Apr 8, 2018
 *      Author: beer
 */

#ifndef XML_ANIMATEDGRAPHICCREATOR_H_
#define XML_ANIMATEDGRAPHICCREATOR_H_

#include "BaseCreator.h"
#include "../GameObject/AnimatedGraphic.h"
class AnimatedGraphicCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new AnimatedGraphic();
	}
};





#endif /* XML_ANIMATEDGRAPHICCREATOR_H_ */
