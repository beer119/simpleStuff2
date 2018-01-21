#ifndef Enemyh
#define Enemyh
#include "SDLGameObject.h"
class Enemy : public SDLGameObject // inherit from GameObject
{
public:

	Enemy();

	virtual void draw();
	virtual void update();
	virtual void clean();

};
#endif
