#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AssetManager.h"


class Cell: public sf::RectangleShape {
public :
	Cell(sf::Vector2f location, const sf::Texture& normal, const sf::Texture& clic, const sf::Vector2f& size);
    Cell() = default;
    bool checkClick(sf::Vector2i mousePos = sf::Vector2i(-1, -1));
    const sf::Sprite* getSprite();
    //int NumVertex;
    sf::Vector2f location;
//private:

    sf::Vector2f size;
    sf::Sprite normal;
    sf::Sprite clic;
    sf::Sprite* currentSpr;
    bool current = false;
    void setState(bool which);
};
