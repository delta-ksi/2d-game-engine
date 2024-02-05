#include "Entity.h"

////////////////////////////////////////////////////////////
Entity::Entity() :
	m_anim(0)

{ }


////////////////////////////////////////////////////////////
void Entity::setGraphics(size_t _anim)
{
	m_cadrs.changeBlock(_anim);
	m_anim = _anim;
}


////////////////////////////////////////////////////////////
void Entity::update(float _frametime)
{
	//if (!m_cadrs.empty())
	m_cadrs.update(_frametime);
}


////////////////////////////////////////////////////////////
void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//if (!m_animations.empty())
	{
		states.transform *= getTransform();

		target.draw(m_cadrs, states);
	}
}