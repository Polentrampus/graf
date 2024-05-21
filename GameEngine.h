#pragma once
#include "Cell.h"

class GameEngine {
public:
	GameEngine();
	void run();
	~GameEngine();
private:
	Cell** cell;
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 640), L"Graph!", sf::Style::Close);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(640, 640));
	/*push_back добавляет копию объекта(или обеспечивает перемещение, если возможно),
	а emplace_back создает объект непосредственно в конце вектора, т.е.без лишнего копирования(или перемещения).*/
	int CountVertix;
	AssetManager manager; 
	std::map<std::string, sf::Texture> m_Textures;
	void input();
	void draw();
};
