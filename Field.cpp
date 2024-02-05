#include "Field.h"

Body hero_;

////////////////////////////////////////////////////////////
Trigger::Trigger(float _x, float _y, float _w, float _h, unsigned char _bytecode[], size_t _size)
{
	m_rect = sf::Rect<float>(_x, _y, _w, _h);

	m_bytecode = new unsigned char[_size];

	m_bytecode_size = _size;

	for (int i = 0; i < _size; i++)
		m_bytecode[i] = _bytecode[i];
}


////////////////////////////////////////////////////////////
void Trigger::doing()
{
	if (m_rect.contains(hero_.getPosition()))
		ScriptVM().interpret(m_bytecode, m_bytecode_size, *this);;
}


////////////////////////////////////////////////////////////
AllBorder::AllBorder(float _x, float _y, float _w, float _h)
{
	m_rect = sf::Rect<float>(_x, _y, _w, _h);
}


////////////////////////////////////////////////////////////
void AllBorder::doing()
{
	float l = m_rect.left;
	float t = m_rect.top;
	float w = m_rect.width;
	float h = m_rect.height;

	float h_x = hero_.getPosition().x;
	float h_y = hero_.getPosition().y;

	float y2 = (h / w) * h_x + (-l * h / w + t);
	float y1 = (-h / w) * h_x + (l * h / w + h + t);

	const float force = 2;

	if (m_rect.contains(hero_.getPosition()))
	{
		if (h_y < y1 && h_y < y2) hero_.move(0, -abs(t - h_y));
		if (h_y > y1 && h_y < y2) hero_.move(abs(l + w - h_x), 0);
		if (h_y < y1 && h_y > y2) hero_.move(-abs(h_x - l), 0);
		if (h_y > y1 && h_y > y2) hero_.move(0, abs(h_y - t - h));
	}
}


////////////////////////////////////////////////////////////
LineBorder::LineBorder(float _x, float _y, float _w, float _h, Direction _dir)
{
	m_dir = _dir;
	m_rect = sf::Rect<float>(_x, _y, _w, _h);
}


////////////////////////////////////////////////////////////
void LineBorder::doing()
{
	float l = m_rect.left;
	float t = m_rect.top;
	float w = m_rect.width;
	float h = m_rect.height;

	float h_x = hero_.getPosition().x;
	float h_y = hero_.getPosition().y;

	if (m_rect.contains(hero_.getPosition()))
	{
		switch (m_dir)
		{
		case UP:	hero_.move(0, -abs(t - h_y));
			break;

		case RIGHT:	hero_.move(abs(l + w - h_x), 0);
			break;

		case DOWN:	hero_.move(0, abs(h_y - t - h));
			break;

		case LEFT:	hero_.move(-abs(h_x - l), 0);
			break;
		}
	}
}


////////////////////////////////////////////////////////////
void FieldHandler::add(Field* field)
{
	m_fields.push_back(field);
}


////////////////////////////////////////////////////////////
void FieldHandler::check()
{
	for (auto i = m_fields.begin(); i != m_fields.end(); i++)
		if (*i) (*i)->doing();
}


////////////////////////////////////////////////////////////
FieldHandler::~FieldHandler()
{
	for (auto i = m_fields.begin(); i != m_fields.end(); i++)
		delete* i;

	m_fields.clear();
}


////////////////////////////////////////////////////////////
void FieldHandler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto i = m_fields.begin(); i != m_fields.end(); i++)
	{
		sf::RectangleShape bound(sf::Vector2f((*i)->m_rect.width, (*i)->m_rect.height));
		bound.setPosition((*i)->m_rect.left, (*i)->m_rect.top);
		bound.setOutlineThickness(1);
		bound.setOutlineColor(sf::Color::Yellow);
		bound.setFillColor(sf::Color::Transparent);
		target.draw(bound, states);
	}
}