#include "Cell.h"

Cell::Cell(sf::Vector2f location, const sf::Texture& normal, const sf::Texture& clic, const sf::Vector2f& size) : size(size), location(location){
    this->normal.setTexture(normal);
    this->clic.setTexture(clic);
    this->normal.setPosition(location);
    this->clic.setPosition(location);
    this->setSize(size);
    currentSpr = &this->normal;
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
    }
    else
        if (current) {
            setState(!current); return true;
        }
    return false;
}

void Cell::setState(bool which)//состояние объекта(есть вершина или нет)
{
    current = which;

    if (current)
    {
        currentSpr = &clic;
        return;
    }
    currentSpr = &normal;
}

const sf::Sprite* Cell::getSprite()
{
    return currentSpr;
}