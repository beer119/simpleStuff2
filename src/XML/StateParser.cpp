/*
 * StateParser.cpp
 *
 *  Created on: Mar 29, 2018
 *      Author: beer
 */

#include "StateParser.h"
#include "../Game.h"
#include "../TextureManager.h"
#include "GameObjectFactory.h"
#include <string>
#include <limits.h>
#include <unistd.h>

bool StateParser::parseState(const char* stateFile, string stateID, vector<GameObject *> *pObjects, vector<std::string> *pTextureIDs)
{


	// create the XML document
	XMLDocument xmlDoc;
	// load the state file

	cout<<"loading "<<stateFile<<endl;
	if(!xmlDoc.LoadFile(stateFile))
	{
		if(xmlDoc.Error())
		{
			cout << xmlDoc.Error() << "\n";

			char result[ PATH_MAX ];
			ssize_t count = readlink( "/proc/self/exe", result, PATH_MAX );
			string place =std::string ( result, (count > 0) ? count : 0 );
			cout<<"Problem with loading "<< stateFile<<" in "<<place<<endl ;

			return false;
		}
	}
	// get the root element
	XMLElement* pRoot = xmlDoc.RootElement();
	if(pRoot==nullptr)
	{
		cout<<"Problem with loading "<< stateFile<<endl ;
		return false;
	}
	// pre declare the states root node
	XMLElement* pStateRoot = 0;
	// get this states root node and assign it to pStateRoot
	for(XMLElement* e = pRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == stateID)
		{
			pStateRoot = e;
		}
	}
	// pre declare the texture root
	XMLElement* pTextureRoot = nullptr;
	// get the root of the texture elements
	for(XMLElement* e = pStateRoot->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == string("TEXTURES"))
		{
			pTextureRoot = e;
		}
	}
	// now parse the textures
	if(pTextureRoot!=nullptr)
	parseTextures(pTextureRoot, pTextureIDs);
	// pre declare the object root node
	XMLElement* pObjectRoot = 0;
	// get the root node and assign it to pObjectRoot
	for(XMLElement* e = pStateRoot->FirstChildElement(); e !=
	NULL; e = e->NextSiblingElement())
	{
		if(e->Value() == string("OBJECTS"))
		{
		pObjectRoot = e;
		}
	}
	// now parse the objects
	parseObjects(pObjectRoot, pObjects);

	return true;

}
void StateParser::parseTextures(XMLElement* pStateRoot,std::vector<std::string> *pTextureIDs)
{

	for(XMLElement* e = pStateRoot->FirstChildElement(); e !=
	NULL; e = e->NextSiblingElement())
	{
		string filenameAttribute = e->Attribute("filename");
		string idAttribute = e->Attribute("ID");
		pTextureIDs->push_back(idAttribute); // push into list
		TextureManager::getInstance()->load(filenameAttribute,idAttribute, TheGame::Instance()->getRenderer());
	}


}
void StateParser::parseObjects(XMLElement *pStateRoot,std::vector<GameObject *> *pObjects)
{
	for(XMLElement* e = pStateRoot->FirstChildElement(); e !=
	NULL; e = e->NextSiblingElement())
	{
		int x, y, width, height, numFrames, callbackID, animSpeed;
		string textureID;
		x=e->IntAttribute("x");
		y=e->IntAttribute("y");
		width=e->IntAttribute("width");
		height=e->IntAttribute("height");
		numFrames=e->IntAttribute("numFrames");
		callbackID=e->IntAttribute("callbackID");
		animSpeed=e->IntAttribute("animSpeed");
		textureID = e->Attribute("textureID");
		GameObject* pGameObject = GameObjectFactory::Instance()->create(e->Attribute("type"));
		pGameObject->load(new LoaderParams(x,y,width,height,textureID,numFrames,callbackID, animSpeed));
		pObjects->push_back(pGameObject);
	}
}

