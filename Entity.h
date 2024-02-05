#pragma once

#ifndef _ENTITY_
#define _ENTITY_

#include "Cadrsbuffer.h"
#include "Object.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Entity : public GameObject
{
public:

	Entity();

	void setGraphics	(size_t anim);
	void update			(float frametime);

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//@// Данные класса должны быть private
public:

	// Данные класса
	size_t		m_anim;		// Тип проигрываемой анимации
	sf::Texture	m_texture;	// Текстура объекта
	Cadrsbuffer	m_cadrs;	// Все анимации entity
};

#endif // !_ENTITY_
