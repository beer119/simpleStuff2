/*
 * StateParser.h
 *
 *  Created on: Mar 29, 2018
 *      Author: beer
 */

#ifndef XML_STATEPARSER_H_
#define XML_STATEPARSER_H_

#include <iostream>
#include <vector>
#include <tinyxml2.h>
#include "../GameObject/GameObject.h"
using namespace tinyxml2;
using namespace std;
class GameObject;
class StateParser
{
	public:
	bool parseState(const char* stateFile, string stateID, vector<GameObject *> *pObjects, vector<std::string>	*pTextureIDs);
		private:
		void parseObjects(XMLElement* pStateRoot,
		std::vector<GameObject*> *pObjects);
		void parseTextures(XMLElement* pStateRoot,
		std::vector<std::string> *pTextureIDs);
};




#endif /* XML_STATEPARSER_H_ */
