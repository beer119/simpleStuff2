/*
 * MenuState.h
 *
 *  Created on: Mar 31, 2018
 *      Author: beer
 */

#ifndef STATES_MENUSTATE_H_
#define STATES_MENUSTATE_H_
#include "GameState.h"
#include <vector>
class MenuState : public GameState
{
protected:
typedef void(*Callback)();
virtual void setCallbacks(const std::vector<Callback>& callbacks)= 0;
std::vector<Callback> m_callbacks;
virtual ~MenuState()
{

}
};
#endif /* STATES_MENUSTATE_H_ */
