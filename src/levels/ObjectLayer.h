/*
 * ObjectLayer.h
 *
 *  Created on: Apr 15, 2018
 *      Author: beer
 */

#ifndef LEVELS_OBJECTLAYER_H_
#define LEVELS_OBJECTLAYER_H_
#include "Layer.h"
#include "../GameObject/GameObject.h"
#include <vector>
class ObjectLayer : public Layer
{
public:
virtual void update();
virtual void render();
std::vector<GameObject*>* getGameObjects(){
	return &m_gameObjects;
}

private:
std::vector<GameObject*> m_gameObjects;
};




#endif /* LEVELS_OBJECTLAYER_H_ */
