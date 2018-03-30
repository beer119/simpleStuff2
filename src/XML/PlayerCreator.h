/*
 * PlayerCreator.h
 *
 *  Created on: Mar 29, 2018
 *      Author: beer
 */

#ifndef XML_PLAYERCREATOR_H_
#define XML_PLAYERCREATOR_H_
#include "BaseCreator.h"
#include "../GameObject/Player.h"
class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};




#endif /* XML_PLAYERCREATOR_H_ */
