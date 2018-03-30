#ifndef Playerh2
#define Playerh2
#include "SDLGameObject.h"

class Player : public SDLGameObject // inherit from GameObject
{
public:

	Player();


	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();

};



#endif
