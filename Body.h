#pragma once

#ifndef _BODY_
#define _BODY_

////////////////////////////////////////////////////////////
// ���������
////////////////////////////////////////////////////////////
#include "Cadrsbuffer.h"
#include "Object.h"

////////////////////////////////////////////////////////////
// ���������
////////////////////////////////////////////////////////////
#include "input.h"
class BodyState;
class StandingState;
class DuckingState;
class JumpingState;
class RunningState;

////////////////////////////////////////////////////////////
enum Anim
{
	STAND_UP,
	STAND_RIGHT,
	STAND_DOWN,
	STAND_LEFT,
	WALK_UP,
	WALK_UP_RIGHT,
	WALK_RIGHT,
	WALK_DOWN_RIGHT,
	WALK_DOWN,
	WALK_DOWN_LEFT,
	WALK_LEFT,
	WALK_UP_LEFT,
	RUN_UP,
	RUN_UP_RIGHT,
	RUN_RIGHT,
	RUN_DOWN_RIGHT,
	RUN_DOWN,
	RUN_DOWN_LEFT,
	RUN_LEFT,
	RUN_UP_LEFT
};

// �������� ������� ������������ ������ - "���������"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Body : public GameObject
{
public:

	Body();

	void changeState(Input _state);
	void setGraphics(Anim _anim);
	void handelInput(Input _input);

	virtual void update(float _frametime);
	virtual void propel(float _dx, float _dy);

	void takeDamage(float _damage);

	~Body();

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

//@// ������ ������ ������ ���� private
public:

	// ������ ������
	Anim					m_anim;			// ��� ������������� ��������
	Cadrsbuffer				m_cadrs; // ��� �������� entity
	sf::Texture				m_texture;
	BodyState*				m_state;		// ������� ��������� body

	float	m_velocity;
	float	m_acceleration;

	float	m_health;
	float	m_stamina;
	float	m_max_health;
	float	m_max_stamina;
};

extern Body hero_;

#endif // !_BODY_
