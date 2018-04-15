/*
 * LevelParser.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: beer
 */
#include "LevelParser.h"
#include <tinyxml2.h>
#include "../TextureManager.h"
#include "../Game.h"
#include "TileLayer.h"
#include "ObjectLayer.h"
#include "../utils.h"
#include "../XML/GameObjectFactory.h"
using namespace std;
Level* LevelParser::parseLevel(const char *levelFile)
{
	// create a TinyXML document and load the map XML
	XMLDocument levelDocument;
	levelDocument.LoadFile(levelFile);
	// create the level object
	Level* pLevel = new Level();
	// get the root node
	XMLElement* pRoot = levelDocument.RootElement();
	m_tileSize=pRoot->IntAttribute("tilewidth");
	m_width=pRoot->IntAttribute("width");
	m_height=pRoot->IntAttribute("height");
	XMLElement* pProperties = pRoot->FirstChildElement();
	 for(XMLElement* e = pProperties->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	    {
	        if(e->Value() == std::string("property"))
	        {
	            parseTextures(e);
	        }
	 }
	// parse the tilesets
	for(XMLElement* e = pRoot->FirstChildElement(); e != NULL; e =e->NextSiblingElement())
	{
		if(e->Value() == std::string("tileset"))
		{
			parseTilesets(e, pLevel->getTilesets());
		}
	}
	// parse any object layers
	// parse any object layers
	for(XMLElement* e = pRoot->FirstChildElement(); e != NULL; e =	e->NextSiblingElement())
	{
		if(e->Value() == std::string("objectgroup") || e->Value() ==std::string("layer"))
		{
			if(e->FirstChildElement()->Value() == std::string("object"))
			{
				parseObjectLayer(e, pLevel->getLayers());
			}
			else if(e->FirstChildElement()->Value() ==std::string("data"))
			{
				parseTileLayer(e, pLevel->getLayers(), pLevel->getTilesets());
			}
		}
	}


	return pLevel;
}

void LevelParser::parseTilesets(XMLElement* pTilesetRoot,std::vector<Tileset>* pTilesets)
{
	// first add the tileset to texture manager
	TextureManager::getInstance()->load(pTilesetRoot->FirstChildElement()->Attribute("source"), pTilesetRoot->Attribute("name"), Game::Instance()->getRenderer());
	// create a tileset object
	Tileset tileset;
	tileset.width=pTilesetRoot->FirstChildElement()->IntAttribute("width");
	tileset.height=pTilesetRoot->FirstChildElement()->IntAttribute("height");
	tileset.firstGridID=pTilesetRoot->IntAttribute("firstgid");
	tileset.tileWidth=pTilesetRoot->IntAttribute("tilewidth");
	tileset.tileHeight=pTilesetRoot->IntAttribute("tileheight");
	tileset.spacing=pTilesetRoot->IntAttribute("spacing");
	tileset.margin=pTilesetRoot->IntAttribute("margin");
	tileset.name = pTilesetRoot->Attribute("name");
	tileset.numColumns = tileset.width / (tileset.tileWidth +
	tileset.spacing);

	pTilesets->push_back(tileset);
}

void LevelParser::parseTileLayer(XMLElement* pTileElement,std::vector<Layer*> *pLayers, const std::vector<Tileset>* pTilesets)
{
	TileLayer* pTileLayer = new TileLayer(m_tileSize, *pTilesets);
	// tile data

	std::string decodedIDs;
	XMLElement* pDataNode;
	for(XMLElement* e = pTileElement->FirstChildElement(); e !=	NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == std::string("data"))
		{
			pDataNode = e;
		}
	}
	for(XMLNode* e = pDataNode->FirstChild(); e != NULL; e =e->NextSibling())
	{
		XMLText* text = e->ToText();
		std::string t = text->Value();
		std::vector<std::vector<int>> data;
		utils toInts;
		data=toInts.CVSStringToVector(t);

		pTileLayer->setTileIDs(data);


	}


	pLayers->push_back(pTileLayer);
}
void LevelParser::parseTextures(XMLElement* pTextureRoot)
{
	TextureManager::getInstance()->load(pTextureRoot->Attribute("value"), pTextureRoot->Attribute("name"),Game::Instance()->getRenderer());
}

void LevelParser::parseObjectLayer(XMLElement* pObjectElement,std::vector<Layer*> *pLayers)
{
// create an object layer
ObjectLayer* pObjectLayer = new ObjectLayer();

for(XMLElement* e = pObjectElement->FirstChildElement(); e !=NULL; e = e->NextSiblingElement())
{
	std::cout << e->Value();
	if(e->Value() == std::string("object"))
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		std::string textureID;
		// get the initial node values type, x and y
		x=e->IntAttribute("x");
		y=e->IntAttribute("y");
		GameObject* pGameObject =GameObjectFactory::Instance()->create(e->Attribute("type"));
		// get the property values
		for(XMLElement* properties = e->FirstChildElement();properties != NULL; properties = properties->NextSiblingElement())
		{
			if(properties->Value() == std::string("properties"))
			{
				for(XMLElement* property = properties->FirstChildElement(); property != NULL; property = property->NextSiblingElement())
				{
					if(property->Value() == std::string("property"))
					{
						if(property->Attribute("name") ==std::string("numFrames"))
						{
							numFrames=property->IntAttribute("value");
						}
						else if(property->Attribute("name") ==std::string("textureHeight"))
						{
							height=property->IntAttribute("value");
						}
						else if(property->Attribute("name") ==std::string("textureID"))
						{
							textureID = property->Attribute("value");
						}
						else if(property->Attribute("name") ==std::string("textureWidth"))
						{
							width=property->IntAttribute("value");
						}
						else if(property->Attribute("name") ==std::string("callbackID"))
						{
							callbackID=property->IntAttribute("value");
						}
						else if(e->Attribute("name") ==std::string("animSpeed"))
						{
							animSpeed=property->IntAttribute("value");
						}
					}
				}
			}
		}
		pGameObject->load(new LoaderParams(x, y, width, height, textureID,numFrames, callbackID, animSpeed));
		pObjectLayer->getGameObjects()->push_back(pGameObject);
	}
}
pLayers->push_back(pObjectLayer);
}



