#include "UIManager.h"
UIManager::UIManager(sf::RenderWindow & rw) :window(rw)
{
}

void UIManager::Update()
{
	window.clear();
	pullInputs();
	drawElements();
	window.display();

}

bool UIManager::isOpen()
{
	return window.isOpen();
}


UIManager::~UIManager()
{

}

void UIManager::add(UIElement & element)
{
	uiElements.push_back(element);
}


void UIManager::drawElements()
{
	for (size_t i = 0; i < 2; i++)
	{
		uiElements[i].draw(window);
	}

}
void UIManager::pullInputs()
{
	sf::Event ev;
	//sf::Vector2i cPos(0,0);
	sf::Vector2i cPos = sf::Mouse::getPosition(window);
	while (window.pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::EventType::MouseButtonPressed:
		case sf::Event::EventType::MouseButtonReleased:
		case sf::Event::EventType::MouseMoved:

			for (int i = 0; i < uiElements.size(); i++)
			{
				uiElements[i].processEvent(ev, cPos);
			}
			//for each (auto element in uiElements)
			//{
			//	
			//}
			break;
		default:
			break;
		}
	}
}
