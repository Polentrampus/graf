#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <iostream>
#include <memory>

int main()
{
    const int window_width = 640;
    const int window_height = 640;

    const int tile_height = 50;
    const int tile_width = 50;

    const int heigh = 12;
    const int width = 50;


    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Graf!");
    float dx = 0, dy = 0;
    int radius = 40;
    sf::CircleShape shape(radius);
    std::vector<sf::CircleShape> vertices;

    char tilemap[heigh][width] = {
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
        "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq",
    };

    sf::Texture texture_2;
    if (!texture_2.loadFromFile("image/fon.png"))
    {
        std::cerr << "failed to load image" << std::endl;
        exit(1);
    }

    sf::Sprite play_map;
    play_map.setTexture(texture_2);

    sf::Sprite s;
    sf::Texture t;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.MouseButtonPressed == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    shape.setFillColor(sf::Color::Green);
                    shape.setPosition(event.mouseButton.x - radius, event.mouseButton.y - radius);
                    vertices.push_back(shape);
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f circlePosition = shape.getPosition();
                    float radius = shape.getRadius();

                    if (mousePosition.x >= circlePosition.x && mousePosition.x <= circlePosition.x + 2 * radius &&
                        mousePosition.y >= circlePosition.y && mousePosition.y <= circlePosition.y + 2 * radius) {
                        std::cout << "Mouse cursor is inside the circle\n";
                    }
                }
            }

            int i = s.getPosition().y / tile_height;
            int j = s.getPosition().x / tile_width;

            if (dx > 0 && tilemap[i][j + 1] == 'w' && tilemap[i][j] != 'w')
                s.setPosition(tile_width * j, s.getPosition().y);

            if (dx < 0 && tilemap[i][j + 1] != 'w' && tilemap[i][j] == 'w')
                s.setPosition(tile_width * (j+1), s.getPosition().y);
            //разместить шары так же как и с пнг спрайтом, относительно них будем притягивать вершины и задавать области видимости для курсора
            if (event.type == sf::Event::Closed)
                window.close();
        }  
        window.clear(sf::Color::White);
        for (int i = 0; i <= heigh; i++) {
            for (int j = 0; j <= width; j++) {
                if (tilemap[i][j] == 'q')
                    play_map.setTextureRect(sf::IntRect(tile_width * 0, 0, tile_width, tile_height));
                if (tilemap[i][j] == 'w')
                    play_map.setTextureRect(sf::IntRect(tile_width * 1, 0, tile_width, tile_height));
                if (tilemap[i][j] == 'e')
                    play_map.setTextureRect(sf::IntRect(tile_width * 2, 0, tile_width, tile_height));
                if (tilemap[i][j] == 'r')
                    play_map.setTextureRect(sf::IntRect(tile_width * 3, 0, tile_width, tile_height));
                play_map.setPosition(j * tile_width, i * tile_height);
                window.draw(play_map);
            }
        }

        for (auto it = vertices.begin(); it != vertices.end(); ++it) {
            window.draw(*it);
        }
        window.display();
    }

    return 0;
}
