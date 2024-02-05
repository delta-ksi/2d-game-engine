#pragma once

//!// Иногда имена предпроцессорных модулей могут совпадать с именами модулей в библиотеке, что может привести
//!// к крашу и абсолютно непредсказуемым ошибкам в подключаемых библиотеках
#ifndef __MAP__
#define __MAP__

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <assert.h>

#include "Tilemap.h"
#include "Body.h"
#include "Entity.h"
#include "Field.h"

////////////////////////////////////////////////////////////
class Map : public sf::Drawable, public sf::Transformable
{
public:

	//bool loadFromFile(std::string _address);
	void update(float _frametime);

private:

	void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

public:

	std::vector <Tilemap>	m_tilemaps;
	std::vector <Entity>	m_entities;
	sf::Texture				m_tilemaps_texture;
	sf::Texture				m_entities_texture;
	FieldHandler			m_fieldHandler;

	Body					m_hero;
};

#endif // !__MAP__
