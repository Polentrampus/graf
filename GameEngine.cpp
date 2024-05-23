#include "GameEngine.h"
#include "AssetManager.h"
#define SIZEPOLE 10

GameEngine::GameEngine() {
	GameEngine::background.setFillColor(sf::Color::White);
	
	//cell.resize(SIZEPOLE);
	//for (int i = 0; i < SIZEPOLE; i++) {
	//	cell[i].resize(SIZEPOLE);
	//	for (int j = 0; j < SIZEPOLE; j++) {
	//		sf::Vector2f location(i * 50, j * 50);
	//		cell[i][j] = Cell(location,AssetManager::GetTexture("image/fon_4.png"), AssetManager::GetTexture("image/vertix.png"),sf::Vector2f(50, 50));
	//	}
	//}
}

//GameEngine::~GameEngine() {
//	std::cout << "distructor game engine" << std::endl;
//}

void GameEngine::input()
{
	sf::Event event;
	//sf::Vector2i mousPosition = sf::Mouse::getPosition(*window);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window->close();
		if (event.type == sf::Event::MouseButtonPressed){
			if (event.mouseButton.button == sf::Mouse::Right){
				cell.checkClick(sf::Mouse::getPosition(*window));
		//		if (cell.checkClick(sf::Mouse::getPosition(*window)))
		//		{
		//			CountVertix++;
		//		}
		//		/*int x = mousPosition.x / 50;
		//		int y = mousPosition.y / 50;

		//		cell.checkClick(sf::Vector2i(mousPosition.x, mousPosition.y));*/
		//		//if (cell[x][y].getGlobalBounds().contains(mousPosition.x, mousPosition.y))//почему реагирует только 1-ая клетка?
		//		//{
		//		//	cell[x][y].checkClick(sf::Vector2i(mousPosition.x, mousPosition.y));
		//		//	CountVertix++;
		//		//	cell[x][y].NumVertex = CountVertix;
		//		//}
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
	window->draw(*cell.getSprite());
	window->display();
}
void GameEngine::run()
{
	while (window->isOpen()){
		input();
		draw();
	}
}