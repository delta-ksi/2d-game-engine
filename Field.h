#pragma once

#ifndef _FIELD_
#define _FIELD_

#include <list>
#include "Script.h"
#include "Body.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Field : public MechanicObject
{
public:
	virtual void	doing()	{}
	size_t			getId()				{ return m_id; }

	virtual void	draw(sf::RenderTarget& target, sf::RenderStates states) const {};

	virtual			~Field()			{}

	size_t				m_id;
	sf::Rect <float>	m_rect;
};


////////////////////////////////////////////////////////////
class Trigger : public Field
{
public:
	Trigger(float _x, float _y, float _w, float _h, unsigned char _bytecode[], size_t _size);

	virtual void doing();

	~Trigger()
	{ if (m_bytecode) delete m_bytecode; }

	unsigned char* m_bytecode;
	size_t m_bytecode_size;
};


////////////////////////////////////////////////////////////
class AllBorder : public Field
{
public:
	AllBorder(float _x, float _y, float _w, float _h);

	virtual void doing();
};


enum Direction
{
	UP,
	RIGHT,
	DOWN,
	LEFT
};

////////////////////////////////////////////////////////////
class LineBorder : public Field
{
public:
	LineBorder(float _x, float _y, float _w, float _h, Direction _dir);

	virtual void doing();

	Direction m_dir;
};

////////////////////////////////////////////////////////////
class FieldHandler : public sf::Drawable
{
public:

	void add(Field* field);
	void check();

	~FieldHandler();

private:

	//@// ���������� ��� ����������� �������� (������ � ����� ������)
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::list <Field*> m_fields;
};

#endif // !_FIELD_
