/*
 * Layer.h
 *
 *  Created on: Apr 12, 2018
 *      Author: beer
 */

#ifndef LEVELS_LAYER_H_
#define LEVELS_LAYER_H_

class Layer
{
public:
	virtual void render() = 0;
	virtual void update() = 0;
protected:
	virtual ~Layer() {}
};




#endif /* LEVELS_LAYER_H_ */
