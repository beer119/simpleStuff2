/*
 *  LevelParser.h
 *
 *  Created on: Apr 12, 2018
 *      Author: beer
 */

#ifndef LEVELS_LEVELPARSER_H_
#define LEVELS_LEVELPARSER_H_

#include "level.h"
#include <tinyxml2.h>
using namespace tinyxml2;
class LevelParser
{
	public:
	Level* parseLevel(const char* levelFile);
	private:
	void parseTilesets(XMLElement* pTilesetRoot,
	std::vector<Tileset>* pTilesets);
	void parseTileLayer(XMLElement* pTileElement,
	std::vector<Layer*> *pLayers, const std::vector<Tileset>*
	pTilesets);

	intintintm_tileSize;
	m_width;
	m_height;

};

#endif /* LEVELS_LEVELPARSER_H_ */
