/*
 * level.h
 *
 *  Created on: Apr 12, 2018
 *      Author: beer
 */

#ifndef LEVELS_LEVEL_H_
#define LEVELS_LEVEL_H_
#include <string>
#include <vector>
#include "Layer.h"
struct Tileset
{
	int firstGridID;
	int tileWidth;
	int tileHeight;
	int spacing;
	int margin;
	int width;
	int height;
	int numColumns;
	std::string name;
};


class Level
{
public:
	Level();
	~Level(){}
	void update();
	void render();
private:
	std::vector<Tileset> m_tilesets;
	std::vector<Layer*> m_layers;

	std::vector<Tileset>* getTilesets()
	{
		return &m_tilesets;
	}
	std::vector<Layer*>* getLayers()
	{
		return &m_layers;
	}


};
#endif /* LEVELS_LEVEL_H_ */
