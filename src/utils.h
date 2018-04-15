/*
 * utils.h
 *
 *  Created on: Apr 15, 2018
 *      Author: beer
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <vector>
#include <string>
using namespace std;
class utils
{
public:
utils() {

}
vector<vector<int>> CVSStringToVector(string CVSString);
vector<string> split(const std::string &s, char delim);
int stringToInt(string shouldBeInt);
};


#endif /* UTILS_H_ */
