#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include<map>

class AssetManager//мэнеджер рессурсов, для удержания в памяти значений текстур и прочего
{
	//класс является синглтоном, так как может иметь лишь один объект 
public:
	AssetManager();
	static sf::Texture& GetTexture(std::string const& filename);
private:

	std::map<std::string, sf::Texture> m_Textures;
	static AssetManager* sInstance;
};