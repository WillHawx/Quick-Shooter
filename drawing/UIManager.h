#pragma once
#include <vector>
#include "UIElement.h"
#include <SFML\Graphics.hpp>

class UIManager
{
	//sf::Vector2f screenWidth;
	sf::RenderWindow &window;
	std::vector<UIElement> uiElements;

public:
	//UIManager(int width, int height);
	UIManager(sf::RenderWindow&);
	void Update();
	bool isOpen();
	void pullInputs();
	~UIManager();
	void add(UIElement&);
private:
	//void processElement(UIElement&);
	void drawElements();
};

