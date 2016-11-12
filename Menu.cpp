#include "Menu.h"



Menu::Menu(float width,float height)//Definicion de una altura y una anchura.
{
	if (!font.loadFromFile("Fuente.ttf")) {//Si falla la lectura de la fuente del texto.
		std::cout << "Error leyendo la fuente";
	}

	gato = sf::Text("Juego Gato", font, 125U);//Definicion del texto gato visualizado en pantalla principal
	gato.setPosition(sf::Vector2f(width / 7,height /40));//Se define la ubicación del texto

	//Declaración, indicación de color, posición, texto y ubicación de los elementos de los diferentes menús.
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Green);
	menu[0].setCharacterSize(75);
	menu[0].setString("Jugar");
	menu[0].setPosition(sf::Vector2f(width/5.5, height / (opcionesIniciales + 2) * 1.4));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setCharacterSize(75);
	menu[1].setString("Salir");
	menu[1].setPosition(sf::Vector2f(width / 1.3, height / (opcionesIniciales + 2) * 3));

	menu1[0].setFont(font);
	menu1[0].setColor(sf::Color::Green);
	menu1[0].setCharacterSize(75);
	menu1[0].setString("Jugar uno contra uno");
	menu1[0].setPosition(sf::Vector2f(width / 5.5, height / (opcionesIniciales + 2) * 1.4));

	menu1[1].setFont(font);
	menu1[1].setColor(sf::Color::White);
	menu1[1].setCharacterSize(75);
	menu1[1].setString("Jugar contra computadora");
	menu1[1].setPosition(sf::Vector2f(width / 5.5, height / (opcionesIniciales + 2) * 2.2));

	menu1[2].setFont(font);
	menu1[2].setColor(sf::Color::White);
	menu1[2].setCharacterSize(75);
	menu1[2].setString("Salir");
	menu1[2].setPosition(sf::Vector2f(width / 1.3, height / (opcionesIniciales + 2) * 3));
	

	menuCompu[0].setFont(font);
	menuCompu[0].setColor(sf::Color::Green);
	menuCompu[0].setCharacterSize(75);
	menuCompu[0].setString("Modo fácil");
	menuCompu[0].setPosition(sf::Vector2f(width / 5.5, height / (opcionesIniciales + 2) * 1.4));

	menuCompu[1].setFont(font);
	menuCompu[1].setColor(sf::Color::White);
	menuCompu[1].setCharacterSize(75);
	menuCompu[1].setString("Modo normal");
	menuCompu[1].setPosition(sf::Vector2f(width / 5.5, height / (opcionesIniciales + 2) * 2.2));

	menuCompu[2].setFont(font);
	menuCompu[2].setColor(sf::Color::White);
	menuCompu[2].setCharacterSize(75);
	menuCompu[2].setString("Modo difícil");
	menuCompu[2].setPosition(sf::Vector2f(width / 5.5, height / (opcionesIniciales + 2) * 3));

	menuCompu[3].setFont(font);
	menuCompu[3].setColor(sf::Color::White);
	menuCompu[3].setCharacterSize(75);
	menuCompu[3].setString("Salir");
	menuCompu[3].setPosition(sf::Vector2f(width / 1.3, height / (opcionesIniciales + 2) * 3));


	//Indices de seleccion para el manejo de eventos up y down.
	selectedItemIndex = 0;
	selectedItemIndex1 = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window) {

	pMenu.loadFromFile("menu1.jpg");
	imagenMenu.setTexture(pMenu);
	window.draw(imagenMenu);
	window.draw(gato);

	if (juega == false) {//Si aun no da "enter" muestra el primer menu.
		for (int i = 0;i < opcionesIniciales;i++) {
			window.draw(menu[i]);
		}
	}
	else if (juegaCompu == true) {//Si ya selecciono modo, pasa a la etapa de menu "facil, normal, dificil".
		for (int i = 0;i < 4;i++) {
			window.draw(menuCompu[i]);
		}
	}
	else if (juega == true) {//Despliega menu de opciones de juego, contra 1 jugador, contra computadora.
		for (int i = 0;i < 3;i++) {
			window.draw(menu1[i]);
		}
	}

}

void Menu::MoveUp() {
	//Manejo de entrada de teclado Up, únicamente para el cambio de color.
	//Lo que se hace es con los índices de posicion, saber si un elemento esta siendo seleccionado, si es
	//el borde de arriba, no se hace nada, si es otro elemento, dependiendo del menu se cambia el indice por 1,-1 o más, 
	//de esta manera se pueden manejar los colores para que el usuario los pueda ver mejor.

	if(juega==false){//Si esta en el menu primero
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Green);
	}
	}
	else if (juegaCompu == true) {//Si esta en el menu tercero
		if (selectedItemIndex1 - 1 >= 0) {
			menuCompu[selectedItemIndex1].setColor(sf::Color::White);
			selectedItemIndex1--;
			menuCompu[selectedItemIndex1].setColor(sf::Color::Green);
		}
	}
	else if (juega == true&&juegaCompu==false) {//Si esta en el menu segundo
		if (selectedItemIndex - 1 >= 0) {
			menu1[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex--;
			menu1[selectedItemIndex].setColor(sf::Color::Green);
		}

	}

}

void Menu::MoveDown(){
	//Analogamente al metodo MoveUp(), se maneja la entrada de teclado para saber cual elemento del menu debe cambiar de color.
	//Tomando en cuenta que esta entrada depende si esta en el borde inferior, donde no ocurriría nada.
	if (juega == false) {
		if (selectedItemIndex + 1 <	opcionesIniciales) {
			menu[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menu[selectedItemIndex].setColor(sf::Color::Green);
		}
	}
	else if (juegaCompu == true) {
		if (selectedItemIndex1 + 1 <	4) {
			menuCompu[selectedItemIndex1].setColor(sf::Color::White);
			selectedItemIndex1++;
			menuCompu[selectedItemIndex1].setColor(sf::Color::Green);
		}
	}
	else if (juega == true) {
		if (selectedItemIndex + 1 <	3) {
			menu1[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menu1[selectedItemIndex].setColor(sf::Color::Green);
		}
	}


}