#include "GameEngine.h"
#include "AssetManager.h"

GameEngine::GameEngine() {
	GameEngine::background.setFillColor(sf::Color::White);
	
	for (int i = 0; i < SIZEPOLE; i++) {
		cell[i] = new Cell[SIZEPOLE];
		for (int j = 0; j < SIZEPOLE; j++) {
			sf::Vector2f location(i * 50+10, j * 50+10);
			cell[i][j] = Cell(location, AssetManager::GetTexture("image/fon_4.png"), AssetManager::GetTexture("image/vertix.png"), sf::Vector2f(50, 50));
  		}
	}
}

GameEngine::~GameEngine() {
	for (int i = 0; i < SIZEPOLE; ++i) {
		delete[] cell[i];
	}
	delete[] cell;
	std::cout << "distructor game engine" << std::endl;
}

void GameEngine::input()
{
	sf::Event event;
	sf::Vector2i mousPosition = sf::Mouse::getPosition(*window);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::MouseButtonPressed){
			if (event.mouseButton.button == sf::Mouse::Left){
				int x = mousPosition.x / 50;
				int y = mousPosition.y / 50;
				cell[x][y].checkClick(sf::Mouse::getPosition(*window));
			}
		}
	}
}

void GameEngine::draw()
{
	window->clear();
	window->draw(background);
	/*for (int i = 0; i < SIZEPOLE; ++i) {
		for (int j = 0; j < SIZEPOLE; ++j) {
			window->draw(*cell[i][j].getSprite());
		}
	}*/
	window->draw(*cell[1][2].getSprite());
	window->display();
}
void GameEngine::run()
{
	while (window->isOpen()){
		input();
		draw();
	}
}