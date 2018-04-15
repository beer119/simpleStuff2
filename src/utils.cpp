/*
 * utils.cpp
 *
 *  Created on: Apr 15, 2018
 *      Author: beer
 */


#include "utils.h"
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>
#include <stdlib.h>     /* atoi */
using namespace std;
vector<vector<int>> utils::CVSStringToVector(string CVSString)
{


	vector<vector<int>> resturValue;
	vector<string> lines=split(CVSString,'\n');
	for(unsigned int i=0;i<lines.size();i++)
	{
		vector<string> element=split(lines[i],',');
		vector<int> elements;

		for(unsigned int j=0;j<element.size();j++)
		{
			int value=stringToInt(element[j]);
			elements.push_back(value);

		}
		if(elements.size()!=0)
		resturValue.push_back(elements);

	}
	return resturValue;

}
vector<string> utils::split(const std::string &s, char delim) {
    std::stringstream ss(s);
    std::string item;
    vector<string> result;
    while (std::getline(ss, item, delim)) {
    	result.push_back(item);
    }
    return result;
}
int utils::stringToInt(string shouldBeInt)
{
	int value = atoi(shouldBeInt.c_str()); //value = 45
	return value;
}
