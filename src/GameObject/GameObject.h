#ifndef GameObject_H
#define GameObject_H
#include <SDL.h>
#include <string>
#include <iostream>
#include "../LoaderParams.h"
class GameObject
{
public:

	virtual void draw()=0;
	virtual void update()=0;
	virtual void clean()=0;
	virtual void load(const LoaderParams* pParams)=0;



protected:
	virtual ~GameObject(){};
	GameObject(){

		};


};
#endif

