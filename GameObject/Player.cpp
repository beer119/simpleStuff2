#include "Player.h"
#include "GameObject.h"
#include "../Game.h"
#include "../TextureManager.h"
#include "../InputHandler.h"
void Player::update()
	{
		//std::cout<<"update player object"<<std::endl;

		//m_velocity.setX(0);
		//m_velocity.setY(0);

		handleInput();
		m_position.setX(m_position.getX()+m_velocity.getX());
		m_position.setY(m_position.getY()+m_velocity.getY());
		m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
		//m_acceleration.setX(6);


	}
Player::Player() :SDLGameObject()
{
}
void Player::draw()
{
	SDLGameObject::draw();
}
void Player::clean(){
}

void Player::handleInput()
{
	Vector2D* target = TheInputHandler::Instance()->getMousePosition();
	m_velocity = *target - m_position;
	m_velocity /= 50;

	/*Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	if(vec->getX())
	{
		m_velocity = (*vec - m_position) / 100;
	}*/

}
