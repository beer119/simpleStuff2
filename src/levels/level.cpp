/*
 * level.cpp
 *
 *  Created on: Apr 12, 2018
 *      Author: beer
 */


#include "level.h"

void Level::render()
{
	for(int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->render();
	}
}
void Level::update()
{
	for(int i = 0; i < m_layers.size(); i++)
	{
		m_layers[i]->update();
	}
}
