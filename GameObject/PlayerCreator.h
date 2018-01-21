/*
 * PlayerCreator.h
 *
 *  Created on: Jan 21, 2018
 *      Author: beer
 */

#ifndef PLAYERCREATOR_H_
#define PLAYERCREATOR_H_
#include "../XML/BaseCreator.h"

#include "Player.h"

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		Player ting;
		return ting;
	}
};
#endif /* PLAYERCREATOR_H_ */
