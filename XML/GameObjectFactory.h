/*
 * GameObjectFactory.cpp
 *
 *  Created on: Jan 21, 2018
 *      Author: beer
 */

#ifndef GAMEOBJECTFACTORY_CPP_
#define GAMEOBJECTFACTORY_CPP_


class GameObjectFactory
{
public:
	std::map<std::string, BaseCreator*> m_creators;

bool registerType(std::string typeID, BaseCreator* pCreator)
{
	std::map<std::string, BaseCreator*>::iterator it =m_creators.find(typeID);
			// if the type is already registered, do nothing
			if(it != m_creators.end())
			{
				delete pCreator;
				return false;
			}
			m_creators[typeID] = pCreator;

			return true;
}
GameObject* create(std::string typeID)
{
	std::map<std::string, BaseCreator*>::iterator it = m_creators.find(typeID);
	if(it == m_creators.end())
	{
		std::cout << "could not find type: " << typeID << "\n";
		return nullptr;
	}
	BaseCreator* pCreator = (*it).second;
	return pCreator->createGameObject();
}
private:
	std::map<std::string, BaseCreator*> m_creators;
};


#endif /* GAMEOBJECTFACTORY_CPP_ */
