#include "Tilemap.h"
#include <math.h>

////////////////////////////////////////////////////////////
void Tilemap::setTilemapParam(size_t width, size_t height)
{
	m_tile_size = sf::Vector2i(width, height);
}


////////////////////////////////////////////////////////////
void Tilemap::resizeVertexArray(size_t _num_x, size_t _num_y)
{
	m_tiles_number_x = _num_x;
	m_tiles_number_y = _num_y;
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(_num_x * _num_y * 4);
}


////////////////////////////////////////////////////////////
void Tilemap::pushNewTile(size_t _id)
{
	size_t t_u;
	size_t t_v;

	int n = 0;
	int u;
	while (true)
	{
		if (floor(_id / pow(n + 1, 2)) == 0)
		{
			u = _id - pow(n, 2);
			if (u <= n)
			{
				t_u = u;
				t_v = n;
			}
			else
			{
				t_u = n;
				t_v = (pow(n + 1, 2)-pow(n, 2) - 1) - u;
			}
			break;
		}
		n++;
	}

	sf::Vertex* quad = &m_vertices[4 * m_i];

	size_t k = floor(m_i / m_tiles_number_x);
	size_t m = m_i % m_tiles_number_x;

	// ��������� ������� ������
	quad[0].position = sf::Vector2f(m * m_tile_size.x, k * m_tile_size.y);
	quad[1].position = sf::Vector2f((m + 1) * m_tile_size.x, k * m_tile_size.y);
	quad[2].position = sf::Vector2f((m + 1) * m_tile_size.x, (k + 1) * m_tile_size.y);
	quad[3].position = sf::Vector2f(m * m_tile_size.x, (k + 1) * m_tile_size.y);

	// ��������������� ������
	quad[0].texCoords = sf::Vector2f(t_u * m_tile_size.x, t_v * m_tile_size.y);
	quad[1].texCoords = sf::Vector2f((t_u + 1) * m_tile_size.x, t_v * m_tile_size.y);
	quad[2].texCoords = sf::Vector2f((t_u + 1) * m_tile_size.x, (t_v + 1) * m_tile_size.y);
	quad[3].texCoords = sf::Vector2f(t_u * m_tile_size.x, (t_v + 1) * m_tile_size.y);

	m_i++;
}


////////////////////////////////////////////////////////////
void Tilemap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(m_vertices, states);
}
