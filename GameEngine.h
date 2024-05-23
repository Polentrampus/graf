#pragma once
#include "Cell.h"

class GameEngine {
public:
	GameEngine();
	void run();
	//std::vector<std::vector<Cell>> cell;
	AssetManager manager;
	Cell cell = Cell(sf::Vector2f(13,140), AssetManager::GetTexture("image/fon_4.png"), AssetManager::GetTexture("image/vertix.png"), sf::Vector2f(50, 50));
//private:
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 640), L"Graph!", sf::Style::Close);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(640, 640));
	/*push_back добавляет копию объекта(или обеспечивает перемещение, если возможно),
	а emplace_back создает объект непосредственно в конце вектора, т.е.без лишнего копирования(или перемещения).*/
	//int CountVertix;
	void input();
	void draw();
};
