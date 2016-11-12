
#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#define opcionesIniciales 2

class Menu
{
public:
	Menu(float width,float height);
	~Menu();
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	int GetPressedItem1() { return selectedItemIndex1; }
	bool juega = false;
	bool juegaCompu = false;

private:
	int selectedItemIndex;
	int selectedItemIndex1;
	sf::Font font;
	sf::Text gato;
	sf::Text menu[opcionesIniciales];
	sf::Text menu1[3];
	sf::Text menuCompu[4];
	sf::Texture pMenu;
	sf::Sprite imagenMenu;
};

