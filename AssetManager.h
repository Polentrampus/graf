#pragma once
#include<SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include<map>
#include<memory>

class AssetManager
{

public:
	AssetManager();

	static sf::Texture& GetTexture(std::string const& filename);
private:

	std::map<std::string, sf::Texture> m_Textures;

	static AssetManager* sInstance;

};