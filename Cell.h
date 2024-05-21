#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"


class Cell: public sf::RectangleShape {
public :
	Cell(sf::Vector2f location, const sf::Texture& texture, const sf::Vector2f& size = sf::Vector2f(0, 0));
    Cell() = default;
    bool checkClick(sf::Vector2i mousePos);
    sf::Sprite* getSprite();
    int NumVertex;
    sf::Vector2i CoordinatesVertex;
private:
    void setState(bool which);

    sf::Vector2f size;
    sf::Sprite StateCell;
    sf::Sprite* currentSpr;
    bool current = false;
};
