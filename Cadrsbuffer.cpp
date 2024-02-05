#include "Cadrsbuffer.h"


////////////////////////////////////////////////////////////
Cadrsbuffer::Cadrsbuffer() :
	m_f_draw	(true),
	m_frequency	(1),
	m_i			(0),
	m_j			(0),
	m_id		(0),
	m_timer		(0)

{ }


////////////////////////////////////////////////////////////
void Cadrsbuffer::push(int _l, int _t, int _w, int _h)
{
	if (m_j < m_vertices.getVertexCount() / 4)
	{
		sf::Vertex* quad = &m_vertices[4 * m_j];

		// Установка позиции тайлов
		quad[0].position = sf::Vector2f(0, 0);
		quad[1].position = sf::Vector2f(0, -_h);
		quad[2].position = sf::Vector2f(_w, -_h);
		quad[3].position = sf::Vector2f(_w, 0);

		// Текстурирование тайлов
		quad[0].texCoords = sf::Vector2f(_l, _t + _h);
		quad[1].texCoords = sf::Vector2f(_l, _t);
		quad[2].texCoords = sf::Vector2f(_l + _w, _t);
		quad[3].texCoords = sf::Vector2f(_l + _w, _t + _h);

		m_j++;
	}
}


////////////////////////////////////////////////////////////
void Cadrsbuffer::setFrequency(float _frequency)
{ m_frequency = _frequency; }


////////////////////////////////////////////////////////////
void Cadrsbuffer::pushBlock(size_t _cadrs_number)
{
	Data data;
	if (!m_data.empty()) data.m_begin = (--m_data.end())->m_end + 1;
	else  data.m_begin = 0;
	data.m_end = data.m_begin + _cadrs_number - 1;
	m_data.push_back(data);
	m_vertices.resize(m_vertices.getVertexCount() + 4 * _cadrs_number);
	m_vertices.setPrimitiveType(sf::Quads);
}


////////////////////////////////////////////////////////////
bool Cadrsbuffer::loadTexture(std::string _address)
{
	if (!m_texture.loadFromFile(_address))
		return false;

	return true;
}


////////////////////////////////////////////////////////////
void Cadrsbuffer::update(float frametime)
{
	if (m_f_draw)
	{
		if (m_timer > 1.f / m_frequency)
		{
			m_timer = 0;
			if (m_i++ == m_data[m_id].m_end)
				m_i = m_data[m_id].m_begin;
		}
		else
			m_timer += frametime;
	}
}


////////////////////////////////////////////////////////////
void Cadrsbuffer::restart()
{ m_i = m_data[m_id].m_begin; }


////////////////////////////////////////////////////////////
void Cadrsbuffer::freeze()
{ m_f_draw = false; }


////////////////////////////////////////////////////////////
void Cadrsbuffer::unfreeze()
{ m_f_draw = true; }


////////////////////////////////////////////////////////////
void Cadrsbuffer::changeBlock(size_t _id)
{
	if (m_i - m_data[m_id].m_begin <= m_data[_id].m_end - m_data[_id].m_begin)
		m_i = m_data[_id].m_begin + m_i - m_data[m_id].m_begin;
	else
		m_i = m_data[_id].m_begin;

	m_id = _id;
}


////////////////////////////////////////////////////////////
void Cadrsbuffer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	if (m_i < m_vertices.getVertexCount() / 4)
	{
		const sf::Vertex* quad = &m_vertices[4 * m_i];
		target.draw(quad, 4, sf::Quads, states);
	}
}