/*
 * MenuButtonCreator.h
 *
 *  Created on: Apr 7, 2018
 *      Author: beer
 */

#ifndef XML_MENUBUTTONCREATOR_H_
#define XML_MENUBUTTONCREATOR_H_


#include "BaseCreator.h"
#include "../GameObject/MenuButton.h"
class MenuButtonCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new MenuButton();
	}
};




#endif /* XML_MENUBUTTONCREATOR_H_ */
