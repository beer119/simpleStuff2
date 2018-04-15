#include "Player.h"
#include "GameObject.h"
#include "../Game.h"
#include "../InputHandler.h"
#include "../TextureManager.h"
void Player::update()
	{

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



}
