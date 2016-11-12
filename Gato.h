#ifndef GATO_H
#define GATO_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <iostream>
#include "Menu.h"

enum class numApretado{no,uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve};

class Gato {
public:
	Gato();
	~Gato();
	void cambiarNumApretado(numApretado);
	void render(sf::RenderWindow&);
	void reset();
	void actualizar();
	void actualizarCompu();
	void matriz();
	int gato[3][3];
	void verificaVictoria();
	int miniMax(int&x, int&y, int turno);
	void turnoComputadora();
	int jugador = 2;
	bool t = true;


	bool hayEmpate = false;
	bool ganaX = false;
	bool ganaO = false;
	bool vuelveJugar = false;
	int GetPressedItem() { return selectedItemIndex; }

private:	

	numApretado m_numApretado;
	bool m_perdio;
	int selectedItemIndex=0;
	
	sf::Text quienJuega;
	sf::Text quienGana;
	sf::Text volverJugarSi;
	sf::Text volverJugarNo;
	sf::Text quiereVolverJugar;
	sf::Text empate;

	sf::Texture pMenu;
	sf::Sprite imagenMenu;

	sf::Font font;

	sf::Texture x;
	sf::Sprite imagenX;
	sf::Texture o;
	sf::Sprite imagenO;
	sf::Texture menuEnJuego;
	sf::Sprite imagenMenuEnJuego;

	sf::Sprite contador[9];
	sf::Texture cuadro;
	sf::Sprite imagenCuadro;
	sf::Texture numero1;
	sf::Sprite imagenNumero1;
	sf::Texture numero2;
	sf::Sprite imagenNumero2;
	sf::Texture numero3;
	sf::Sprite imagenNumero3;
	sf::Texture numero4;
	sf::Sprite imagenNumero4;
	sf::Texture numero5;
	sf::Sprite imagenNumero5;
	sf::Texture numero6;
	sf::Sprite imagenNumero6;
	sf::Texture numero7;
	sf::Sprite imagenNumero7;
	sf::Texture numero8;
	sf::Sprite imagenNumero8;
	sf::Texture numero9;
	sf::Sprite imagenNumero9;
};

#endif // !GATO_H

