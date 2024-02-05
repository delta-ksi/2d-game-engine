#pragma once

#ifndef _OBJECT_
#define _OBJECT_

#include <SFML/Graphics.hpp>

// ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜ ˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜
// ˜˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜
class MechanicObject : public sf::Transformable
{
public:
	virtual void activate() {};
	virtual void update(float _frametime) {};
	virtual void propel(float _dx, float _dy) {};
};

// ˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜˜˜˜˜˜˜ ˜ ˜˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜˜˜˜˜˜˜˜˜˜ ˜˜˜˜˜,
// ˜˜˜˜˜˜˜ ˜˜˜˜˜ ˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜, ˜˜˜˜˜˜, ˜˜˜˜˜˜˜˜ ˜˜˜ ˜˜˜˜˜˜ ˜ ˜˜˜˜ ˜˜˜-˜˜
class GameObject : public sf::Drawable, public sf::Transformable //, public MechanicObject
{
public:

	virtual void update(float _frametime) {};
	virtual void propel(float _dx, float _dy) {};

	float	m_velocity;
	float	m_acceleration;

	float	m_health;
	float	m_stamina;
	float	m_max_health;
	float	m_max_stamina;
};

#endif // !_GAMEOBJECT_