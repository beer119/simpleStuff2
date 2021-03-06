/*
 * TileLayer.h
 *
 *  Created on: Apr 12, 2018
 *      Author: beer
 */

#ifndef LEVELS_TILELAYER_H_
#define LEVELS_TILELAYER_H_
#include "Layer.h"
#include <vector>
#include "../Vector2D.h"
#include "level.h"
class TileLayer : public Layer
{
public:
	TileLayer(int tileSize, const std::vector<Tileset> &tilesets);
	virtual void update();
	virtual void render();
	void setTileIDs(const std::vector<std::vector<int>>& data)
	{
	m_tileIDs = data;
	}
	void setTileSize(int tileSize)
	{
	m_tileSize = tileSize;
	}
	Tileset getTilesetByID(int tileID);
	private:
	int m_numColumns;
	int m_numRows;
	int m_tileSize;
	Vector2D m_position;
	Vector2D m_velocity;
	const std::vector<Tileset> &m_tilesets;
	std::vector<std::vector<int>> m_tileIDs;
};



#endif /* LEVELS_TILELAYER_H_ */
