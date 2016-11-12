//Proyecto 2 de Estructuras de Datos... Juego Gato.
//Realizado por José Carlos Barrantes Araya y Alex José Baltodano Paniagua
//Todos los comentarios seran hechos tanto en el main como en los archivos .cpp, ya que la información de los .h está contenida en los mismos.
//metodo minimax con ayuda de http://foro.elhacker.net/programacion_cc/ejemplo_de_minimax_3_en_raya-t350588.0.html

#include <iostream>
#include "Menu.h"
#include "Juego.h"

int numero=0;

int main() {
	sf::RenderWindow ventana(sf::VideoMode(800, 600), "Proyecto Gato");//Creacion de la primera ventana

	Menu menu(ventana.getSize().x, ventana.getSize().y); //Creacion de un objeto menu, que por definicion ya trae todos los elementos necesarios (ver clase Menu).
	menu.juega = false; //identificador de menu inicial (Juega, Salir).
	menu.juegaCompu=false;//identificador de modos (Juega 1vrs1, Juega Compu, Salir).
	while (ventana.isOpen())  //Manejo de los eventos en la ventana de menu.
	{
		sf::Event event;
		while (ventana.pollEvent(event)) 
		{
			switch (event.type) 
			{
			case sf::Event::KeyReleased://Si hay un key release, lee el key que se soltó.
				switch (event.key.code) 
				{
				case sf::Keyboard::Up://Para el manejo de colores en la seleccion
					menu.MoveUp();
					break;
				case sf::Keyboard::Down://Para el manejo de colores en la seleccion
					menu.MoveDown();
					break;
				case sf::Keyboard::Return://Si es "enter", se procede a seleccionar entre las opciones
					if (menu.juegaCompu==true) {//Si estamos en menu de modos contra computadora activado.
						switch (menu.GetPressedItem1()) {
						case 0://Jugar facil
							numero = 2;
							ventana.close();
							break;
						case 1://Jugar normal
							numero = 3;
							ventana.close();
							break;
						case 2://Jugar Dificil
							numero = 4;
							ventana.close();
							break;
						case 3://Salir
							ventana.close();
							break;
						}
					}
					if(menu.juega==true&&menu.juegaCompu==false){//Segundo menu, luego de Jugar inicial.
						switch (menu.GetPressedItem()) {
						case 0: //Contra jugador.
							std::cout << "Juega contra jugador";
							numero = 1;
							ventana.close();
							break;
						case 1://Contra computadora.
							std::cout << "Juega contra computadora";
							menu.juegaCompu = true;
							break;
						case 2: 
							ventana.close();
							break;
						}
					}
					else 
					if(menu.juega==false){//Menu inicial
					switch (menu.GetPressedItem()) 
					{
					case 0://Opcion jugar
						menu.juega = true;
						break;
					case 1://Opcion salir.
						ventana.close();
						break;
					}
					}
				break;
			}
				break;
			case sf::Event::Closed://Si se cierra la ventana.
				ventana.close();
				break;
		}
		}
		ventana.clear();//Limpia la ventana.
		menu.draw(ventana);//La dibuja
		ventana.display();//La muestra
	}

	Juego juego;//Se crea un objeto de tipo Juego, que tambien por definicion trae las dimensiones y una ventana nueva, diferente a la de menu.
	if(numero==1){
	juego.iniciar();//Sin inteligencia artificial
	}
	else if (numero == 2) {
		std::cout << "Empieza facil";
		juego.iniciarCompu();//Con inteligencia artificial
	}
	else if (numero == 3) {
		std::cout << "Empieza normal";
		juego.iniciarCompu();//Con inteligencia artificial
	}
	else if (numero == 4) {
		std::cout << "Empieza dificil";
		juego.iniciarCompu();//Con inteligencia artificial
	}
	return 0;
}