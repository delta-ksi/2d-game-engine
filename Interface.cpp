#include "Interface.h"


////////////////////////////////////////////////////////////
Interface::Interface()
{
	healthbar_background.setSize(sf::Vector2f(width + 2 * outline, height));
	healthbar_background.setPosition(left, top);
	healthbar_background.setFillColor(sf::Color::Black);

	healthbar.setPosition(left + outline, top + outline);
	healthbar.setFillColor(sf::Color::Red);

	staminabar_background.setSize(sf::Vector2f(width + 2 * outline, height));
	staminabar_background.setPosition(left, top + step);
	staminabar_background.setFillColor(sf::Color::Black);

	staminabar.setPosition(left + outline, top + step + outline);
	staminabar.setFillColor(sf::Color::Blue);
}


////////////////////////////////////////////////////////////
void Interface::update(Body& hero)
{
	healthbar.setSize(sf::Vector2f(width * hero.m_health / hero.m_max_health, height - 2*outline));
	staminabar.setSize(sf::Vector2f(width * hero.m_stamina / hero.m_max_stamina, height - 2*outline));
}


////////////////////////////////////////////////////////////
void Interface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(healthbar_background, states);
	target.draw(staminabar_background, states);
	target.draw(healthbar, states);
	target.draw(staminabar, states);
}