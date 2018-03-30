/*
 * LoaderParams.h
 *
 *  Created on: Jan 13, 2018
 *      Author: beer
 */

#ifndef LOADERPARAMS_H_
#define LOADERPARAMS_H_
#include <string>
class LoaderParams
{
public:
	LoaderParams(int x, int y, int width, int height, std::string
	textureID, int numFrames =1, int callbackID = 0, int animSpeed = 0) :
	m_x(x),
	m_y(y),
	m_width(width),
	m_height(height),
	m_textureID(textureID),
	m_numFrames(numFrames),
	m_callbackID(callbackID),
	m_animSpeed(animSpeed)
	{
	}

int getX() const { return m_x; }
int getY() const { return m_y; }
int getWidth() const { return m_width; }
int getHeight() const { return m_height; }
std::string getTextureID() const { return m_textureID; }
int getNumFrames() const { return m_numFrames;}
private:
int m_x;
int m_y;
int m_width;
int m_height;
int m_numFrames;
int m_callbackID;
int m_animSpeed;
std::string m_textureID;
};






#endif /* LOADERPARAMS_H_ */
