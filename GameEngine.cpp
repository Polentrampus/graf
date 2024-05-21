#include "GameEngine.h"
#include "AssetManager.h"
#define SIZEPOLE 10

GameEngine::GameEngine() {
	GameEngine::background.setFillColor(sf::Color::White);
	cell = new Cell * [SIZEPOLE]; for (int i = 0; i < SIZEPOLE; i++) { cell[i] = new Cell[SIZEPOLE]; }

	for (int i = 0; i < SIZEPOLE; i++) {
		for (int j = 0; j < SIZEPOLE; j++) {
			sf::Vector2f location(i * 50, j * 50);
			cell[i][j] = Cell(location,AssetManager::GetTexture("image/fon_3.png"),sf::Vector2f(50, 50));
		}
	}
}

GameEngine::~GameEngine() {
	std::cout << "distructor game engine" << std::endl;
	for (int i = 0; i < SIZEPOLE; i++) {
		delete[] cell[i];
	}
	delete[] cell;
}

void GameEngine::input()
{
	sf::Event event;
	sf::Vector2i mousPosition = sf::Mouse::getPosition(*window);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.MouseButtonPressed == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left){
				int x = mousPosition.x / 50;
				int y = mousPosition.y / 50;
				if (cell[x][y].checkClick(sf::Mouse::getPosition(*window)))
				{
					CountVertix++;
					cell[x][y].NumVertex = CountVertix;
				}
			}
		}
	}
}

void GameEngine::draw()
{
	window->clear();
	window->draw(background);
	for (int i = 0; i < SIZEPOLE; ++i) {
		for (int j = 0; j < SIZEPOLE; ++j) {
			window->draw(*cell[i][j].getSprite());
		}
	}
	window->display();
}
void GameEngine::run()
{
	while (window->isOpen()){
		input();
		draw();
	}
}