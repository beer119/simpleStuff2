/*
 * GameObjectFactory.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: beer
 */

#ifndef GAMEOBJECTFACTORY_CPP_
#define GAMEOBJECTFACTORY_CPP_
#include "BaseCreator.h"
#include <map>

class GameObjectFactory
{

public:
	bool registerType(std::string typeID, BaseCreator* pCreator);
	GameObject* create(std::string typeID);
static GameObjectFactory* Instance()
{
	if(s_pInstance == 0)
	{
		s_pInstance = new GameObjectFactory();
	}
	return s_pInstance;
}
private:

	static GameObjectFactory* s_pInstance;
	std::map<std::string, BaseCreator*> m_creators;
};


#endif /* GAMEOBJECTFACTORY_CPP_ */
