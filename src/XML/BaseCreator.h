/*
 *  BaseCreator.h
 *
 *  Created on: Jan 21, 2018
 *      Author: beer
 */

#ifndef BASECREATOR_H_
#define BASECREATOR_H_



#include <string>
#include <map>
#include "../GameObject/GameObject.h"
class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}

};


#endif /* BASECREATOR_H_ */
