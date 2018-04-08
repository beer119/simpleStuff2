/*
 * EnemyCreator.h
 *
 *  Created on: Apr 8, 2018
 *      Author: beer
 */

#ifndef XML_ENEMYCREATOR_H_
#define XML_ENEMYCREATOR_H_


#include "BaseCreator.h"
#include "../GameObject/Enemy.h"
class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};




#endif /* XML_ENEMYCREATOR_H_ */
