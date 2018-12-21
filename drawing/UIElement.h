#pragma once
#include <SFML\Graphics.hpp>
class UIElement
{
	bool _isActive;
	bool _isPressed;
	bool _isHovered;
	void(*onPress)(UIElement &element);
	void(*onRelease)(UIElement &element);
	void(*onHover)(UIElement &element);
	void(*onEnter)(UIElement &element);
	void(*onExit)(UIElement &element);
	void(*onClick)(UIElement &element);
	sf::Shape &shape;
public:
	UIElement(sf::Shape &shape);
	~UIElement();
	void setOnPress(void(*callBack)(UIElement &element));
	void setOnRelease(void(*callBack)(UIElement &element));
	void setOnHover(void(*callBack)(UIElement &element));
	void setOnClick(void(*callBack)(UIElement &element));
	void setOnEnter(void(*callBack)(UIElement &element));
	void setOnExit(void(*callBack)(UIElement &element));
	bool isClickable();
	bool isPressed();
	void processEvent(sf::Event, sf::Vector2i);
	void setActive(bool isActive);
	bool isActive();
	void draw(sf::RenderWindow&);
	sf::Shape &getShape();
};

