#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameEngine {
public:
	GameEngine();
	void run();
	static sf::Texture& GetTexture(std::string const& filename);
	//static sf::Font& GetFont(std::string const& filename);
	//static sf::Shader* GetShader(std::string const& vsFile, std::string const& fsFile);

private:
	std::unique_ptr<sf::RenderWindow> window = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 640), L"Graph!", sf::Style::Close);
	sf::RectangleShape background = sf::RectangleShape(sf::Vector2f(640, 640));
	//Button* cell = new Button(sf::Vector2f(13, 140), GetTexture("image/play1.png"), GetTexture("image/pause2.png"));//ячейка
	//std::vector<sf::RectangleShape> cell;
	std::vector<sf::RectangleShape> cells;

	/*push_back добавляет копию объекта(или обеспечивает перемещение, если возможно),
	а emplace_back создает объект непосредственно в конце вектора, т.е.без лишнего копирования(или перемещения).*/

	std::map<std::string, sf::Texture> m_Textures;
	//std::map<std::string, sf::Font> m_Fonts;
	//std::map< std::string, std::unique_ptr < sf::Shader >> m_Shaders;

	//sf::Text text;
	void input();
	void draw();
	static GameEngine* sInstance;
};
