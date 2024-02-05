#pragma once

#ifndef _CADRSBUFFER_
#define _CADRSBUFFER_

////////////////////////////////////////////////////////////
// Заголовки
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <vector>

////////////////////////////////////////////////////////////
class Cadrsbuffer : public sf::Drawable, public sf::Transformable
{
public:

	Cadrsbuffer();

	void update			(float frametime);
	void restart		();
	void freeze			();
	void unfreeze		();
	void changeBlock	(size_t _id);
	bool loadTexture	(std::string _address);
	void push			(int _l, int _t, int _w, int _h);
	void setFrequency	(float _frequency);
	void pushBlock		(size_t _cadrs_number);

	~Cadrsbuffer()
	{
		m_vertices.clear();
		m_data.clear();
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


	// Данные класса Animation
	//bool			m_f_animatable;	// Флаг возможности отрисовать анимацию, если кол-во кадров > 0, то true, иначе false
	//bool			m_f_endless;	// Флаг отвечающий за конечночность или бесконечность анимации
	bool			m_f_draw;		// Флаг, если анимация конечная, то этот флаг будет false, когда анимация закончится

	size_t			m_frequency;	// Частота отрисовки кадров
	float			m_timer;		// Отрисовачный таймер
	size_t			m_i;			// Номер кадра, который должен быть отрисован
	sf::Texture		m_texture;		// Текстура анимации

	sf::VertexArray	m_vertices;		//
	size_t			m_id;			//
	size_t			m_j;

	struct Data
	{
		size_t m_begin;				//
		size_t m_end;				//
	};

	std::vector <Data> m_data;		//
};

#endif // !_CADRSBUFFER_
