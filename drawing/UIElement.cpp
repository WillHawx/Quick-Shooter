#include "UIElement.h"

UIElement::UIElement(sf::Shape &shape) :shape(shape)
{
	this->shape = shape;
	onPress = nullptr;
	onRelease = nullptr;
	onClick = nullptr;
	onHover = nullptr;
	onEnter = nullptr;
	onExit = nullptr;
	_isActive = true;
	_isHovered = false;
	_isPressed = false;
	printf("const %i\n", _isPressed);
}

UIElement::~UIElement()
{

}


void UIElement::setOnPress(void(*callBack)(UIElement &element))
{
	onPress = callBack;
}

void UIElement::setOnRelease(void(*callBack)(UIElement &element))
{
	onRelease = callBack;
}

void UIElement::setOnHover(void(*callBack)(UIElement &element))
{
	onHover = callBack;
}

void UIElement::setOnClick(void(*callBack)(UIElement &element))
{
	onClick = callBack;
}

void UIElement::setOnEnter(void(*callBack)(UIElement &element))
{
	onEnter = callBack;
}

void UIElement::setOnExit(void(*callBack)(UIElement &element))
{
	onExit = callBack;
}

bool UIElement::isClickable()
{
	return onPress != nullptr;
}
bool UIElement::isPressed()
{
	printf("ispressd??? %i\n", _isPressed);
	return _isPressed;
}
void UIElement::processEvent(sf::Event ev, sf::Vector2i cPos)
{
	switch (ev.type)
	{
	case sf::Event::EventType::MouseButtonPressed:
	{
		if (this->getShape().getGlobalBounds().contains(cPos.x, cPos.y)) {
			if (onPress != nullptr && _isActive)
				onPress(*this);
			_isPressed = true;
			printf("MouseButtonPressed %i\n", _isPressed);
		}
	}

	break;
	case sf::Event::EventType::MouseButtonReleased:
	{
		printf("MouseButtonReleased %i\n", _isPressed);
		if (_isPressed) {
			printf("release\n");
			_isPressed = false;
			printf("2 MouseButtonReleased %i\n", _isPressed);
			if (this->getShape().getGlobalBounds().contains(cPos.x, cPos.y)) {
				if (onClick != nullptr)
					onClick(*this);
			}
			if (onRelease != nullptr)
				onRelease(*this);
		}
	}
	break;
	case sf::Event::EventType::MouseMoved:
		if (this->getShape().getGlobalBounds().contains(cPos.x, cPos.y)) {
			if (onHover != nullptr)
				onHover(*this);
			if (!_isHovered) {
				_isHovered = true;
				if (onEnter != nullptr)
					onEnter(*this);
			}
		}
		else
		{
			_isHovered = false;
			if (onExit != nullptr)
				onExit(*this);

		}
		break;
	default:
		break;
	}
}

void UIElement::setActive(bool isActive)
{
	this->_isActive = isActive;
}

bool UIElement::isActive()
{
	return _isActive;
}

void UIElement::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

sf::Shape & UIElement::getShape()
{
	return shape;
}
