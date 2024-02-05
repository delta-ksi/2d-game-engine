#pragma once

#ifndef _TILEMAP_
#define _TILEMAP_

#include <SFML/Graphics.hpp>
#include <fstream>

class Tilemap :
	public sf::Drawable,
	public sf::Transformable

{
public:

	void setTilemapParam(size_t width, size_t height);
	void resizeVertexArray(size_t _num_x, size_t _num_y);
	void pushNewTile(size_t _id);
	void setTilesetSize(sf::Vector2u _s)
	{
		m_tileset_w = _s.x;
		m_tileset_h = _s.y;
	}

private:

	virtual void draw(sf::RenderTarget& _target, sf::RenderStates _states) const;

	// Данные класса
	int				m_i = 0;
	sf::Vector2i	m_tile_size;
	size_t			m_tiles_number_x;
	size_t			m_tiles_number_y;
	size_t			m_tileset_w;
	size_t			m_tileset_h;
	sf::VertexArray m_vertices;
	sf::Texture     m_tileset;

};

#endif // !_TILEMAP_