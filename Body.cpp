#include "Body.h"
#include "State.h"
#include <math.h>

////////////////////////////////////////////////////////////
Body::Body() :
	m_state			(new StandingState()),
	m_velocity		(2.f),
	m_acceleration	(2.f),
	m_anim			(Anim::STAND_RIGHT),
	m_health		(75),
	m_stamina		(50),
	m_max_health	(100),
	m_max_stamina	(100)

{ }


////////////////////////////////////////////////////////////
void Body::changeState(Input state)
{
	BodyState* n_state = m_state->changeState(*this, state);
	if (n_state != NULL)
	{
		delete m_state;
		m_state = n_state;
	}
}


////////////////////////////////////////////////////////////
void Body::setGraphics(Anim anim)
{
	if (m_anim != anim)
	{
		m_cadrs.changeBlock(anim);
		m_anim = anim;
	}
}


////////////////////////////////////////////////////////////
void Body::update(float frametime)
{
	//if (!m_animations.empty())
	{
		m_cadrs.update(frametime);
		m_state->update(*this);
	}
}


////////////////////////////////////////////////////////////
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//if (!m_animations.empty())
	{
		states.transform *= getTransform();
		states.texture = &m_texture;
		target.draw(m_cadrs, states);
	}
}


////////////////////////////////////////////////////////////
void Body::handelInput(Input input)
{
	if (m_state) m_state->handleInput(*this, input);


}

////////////////////////////////////////////////////////////
void Body::propel(float _dx, float _dy)
{
	float a = atan2(_dy, _dx);
	a = floor(a * 100) / 100.f;

	if (-3.14f / 8 < a && a <= 3.14f / 8)
		m_state->handleInput(*this, (Input)3);

	if (3.14f / 8 < a && a <= 3 * 3.14f / 8)
		m_state->handleInput(*this, (Input)4);

	if (3 * 3.14f / 8 < a && a <= 5 * 3.14f / 8)
		m_state->handleInput(*this, (Input)5);

	if (5 * 3.14f / 8 < a && a <= 7 * 3.14f / 8)
		m_state->handleInput(*this, (Input)6);

	if (-7 * 3.14f / 8 > a && a >= -3.14f || 7 * 3.14f / 8 < a && a <= 3.14f)
		m_state->handleInput(*this, (Input)7);

	if (-3.14f / 8 > a && a >= -3 * 3.14f / 8)
		m_state->handleInput(*this, (Input)2);

	if (-3 * 3.14f / 8 > a && a >= -5 * 3.14f / 8)
		m_state->handleInput(*this, (Input)1);

	if (-5 * 3.14f / 8 > a && a >= -7 * 3.14f / 8)
		m_state->handleInput(*this, (Input)8);

}

void Body::takeDamage(float _damage)
{
	if (m_health - _damage > 0)
		m_health -= _damage;
	else
		m_health = 0.f;
}

////////////////////////////////////////////////////////////
Body::~Body()
{
	if (m_state) delete m_state;
	//@// пїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅпїЅ пїЅпїЅпїЅпїЅпїЅпїЅ?
}