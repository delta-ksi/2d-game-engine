#include "Map.h"


////////////////////////////////////////////////////////////
void Map::update(float _frametime)
{
	for (int i = 0; i < m_entities.size(); i++)
		m_entities[i].update(_frametime);

	//m_hero.update(_frametime);
}


////////////////////////////////////////////////////////////
void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	states.texture = &m_tilemaps_texture;
	for (int i = 0; i < m_tilemaps.size(); i++)
		target.draw(m_tilemaps[i], states);

	states.texture = &m_entities_texture;
	for (int i = 0; i < m_entities.size(); i++)
		target.draw(m_entities[i], states);
}