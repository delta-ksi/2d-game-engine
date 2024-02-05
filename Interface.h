#pragma once

#ifndef _INTERFACE_
#define _INTERFACE_

#include <SFML/Graphics.hpp>
#include "Body.h"

class Interface : public sf::Drawable, public sf::Transformable
{
public:

	Interface();

	void update(Body&);

private:

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::RectangleShape healthbar;
	sf::RectangleShape staminabar;
	sf::RectangleShape healthbar_background;
	sf::RectangleShape staminabar_background;

	const size_t width = 100;
	const size_t height = 10;
	const size_t top = 300;
	const size_t left = 50;
	const size_t step = 15;
	const size_t outline = 2;
};

#endif _INTERFACE_