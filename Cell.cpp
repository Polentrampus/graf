#include "Cell.h"

Cell::Cell(sf::Vector2f location, const sf::Texture& texture, const sf::Vector2f& size) : size(size) {
    this->StateCell.setTexture(texture);
    this->StateCell.setPosition(location);
    currentSpr = &this->StateCell;
    this->setSize(size);
}

bool Cell::checkClick(sf::Vector2i mousePos)
{
    if (mousePos.x >= 0)
    {
        if (((mousePos.x) > currentSpr->getPosition().x &&
            (mousePos.x) < (currentSpr->getPosition().x +
                currentSpr->getGlobalBounds().width))
            && ((mousePos.y) > currentSpr->getPosition().y &&
                (mousePos.y) < (currentSpr->getPosition().y +
                    currentSpr->getGlobalBounds().height)))
        {
            setState(!current); return true;
        }
        //if(sprite.getGlobalBounds().contains(sf::Mouse::getPosition(win)))
    }
    else
        if (current) {
            setState(!current); return true;
        }
    return false;
}

void Cell::setState(bool which)
{
    current = which;

    if (current)
    {
        StateCell.setTextureRect(sf::IntRect(0, 0, 50, 50));
        currentSpr = &StateCell;
        return;
    }
    StateCell.setTextureRect(sf::IntRect(50, 0, 50, 50));
    currentSpr = &StateCell;
}

sf::Sprite* Cell::getSprite()
{
    return &StateCell;
}