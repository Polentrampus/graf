#include "GameEngine.h"

GameEngine::GameEngine(){
	background.setFillColor(sf::Color::White);
	//cell.setTexture(&GameEngine::GetTexture("image/fon_1.png"));
	//text.setFont(GameEngine::GetFont("font/ofont.ru_1 Shelley Volante.ttf"));//шрифт
	//text.setFillColor(sf::Color::Green);
}

sf::Texture& GameEngine::GetTexture(std::string const& filename)
{
	auto& texMap = sInstance->m_Textures;
	auto pairFound = texMap.find(filename);

	if (pairFound != texMap.end())
	{
		return pairFound->second;
	}
	else
	{
		auto& texture = texMap[filename];
		texture.loadFromFile(filename);
		return texture;
	}
}

//sf::Font& GameEngine::GetFont(std::string const& filename)//получить шрифт
//{
//	auto& fontMap = sInstance->m_Fonts;
//	auto pairFound = fontMap.find(filename);
//
//	if (pairFound != fontMap.end())
//	{
//		return pairFound->second;
//	}
//	else
//	{
//		auto& font = fontMap[filename];
//		font.loadFromFile(filename);
//		return font;
//	}
//}


//sf::Shader* GameEngine::GetShader(std::string const& vsFile, std::string const& fsFile)
//{
//	auto& shaderMap = sInstance->m_Shaders;
//	auto combinedKey = vsFile + ";" + fsFile;
//	auto pairFound = shaderMap.find(combinedKey);
//
//	if (pairFound != shaderMap.end())
//	{
//		return pairFound->second.get();
//	}
//	else
//	{
//		auto& shader = (shaderMap[combinedKey] = std::unique_ptr<sf::Shader>(new sf::Shader()));
//		shader->loadFromFile(vsFile, fsFile);
//		return shader.get();
//	}
//
//}


void GameEngine::input()
{
	sf::Event event;
	sf::Vector2i mousPosition = sf::Mouse::getPosition(*window);
	cells.reserve(10);
	for (int i = 0; i < 10; ++i) {
		cells.emplace_back(sf::Vector2f(50, 50));
		cells.at(i).setFillColor(sf::Color::Yellow);
	}

	while (window->pollEvent(event))
	{
		if (event.MouseButtonPressed == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				int i, j;
				i = mousPosition.x / 50;
				j = mousPosition.y / 50;

				if (cells[i].getGlobalBounds().contains((float)mousPosition.x, (float)mousPosition.y))//если внутри контура cell наход€тс€ координаты мыши, то красим €чейку в синий
				{
					cells[i].setFillColor(sf::Color::Blue);
				}
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					if (cells[i].getGlobalBounds().contains((float)mousPosition.x, (float)mousPosition.y))//возвращает текущую позицию мыши относительно окна
					{
						cells[i].setFillColor(sf::Color::Yellow);
					}
				}
			}
		}
	}
}

void GameEngine::draw()
{
	window->clear(sf::Color::Black);
	window->draw(background);
	for (int i = 0; i < 10; ++i) {
		window->draw(cells.at(i));
	}
	//window->draw(*restart.getSprite());
	//text.setPosition(15, 515);
	//text.setString(" < score > ");
	//window->draw(text);
	window->display();
}
void GameEngine::run()
{
	while (window->isOpen())
	{
		input();
		draw();
	}
}