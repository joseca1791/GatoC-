#include "Gato.h"
#include <sstream>

//constructor que tiene la funcion reset.
Gato::Gato() {
	reset();
}
//inicializa la matriz en unos.
void Gato::matriz() {
	vuelveJugar = false;
	ganaO = false;
	ganaX = false;
	hayEmpate = false;

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			gato[i][j] = 1;
		}
	}
}
//Cambia el numero en el enum de acuerdo a la entrada de teclado que se haya realizado
void Gato::cambiarNumApretado(numApretado numApretado) {
	m_numApretado = numApretado;
}
//destructor.
Gato::~Gato() {
}
//carga las imagenes que van a ser necesarias en el juego
//muestra en pantalla el gato
//maneja los eventos en caso de que sea X o O
void Gato::render(sf::RenderWindow& ventana) {
	
	if (!font.loadFromFile("Fuente.ttf")) {
	}

	pMenu.loadFromFile("menu1.jpg");
	imagenMenu.setTexture(pMenu);
	imagenMenu.setPosition(200, 0);
	ventana.draw(imagenMenu);

	if (hayEmpate == true) {
		empate = sf::Text("Hay empate!", font, 110U);
		empate.setPosition(620, 375);
		empate.setColor(sf::Color::Green);
		ventana.draw(empate);
	}

	if (ganaX == true) {
		quienGana = sf::Text("Gana: X", font, 110U);
		quienGana.setPosition(620, 375);
		quienGana.setColor(sf::Color::Green);
		ventana.draw(quienGana);
	}
	else if (ganaO == true) {
		quienGana = sf::Text("Gana: O", font, 110U);
		quienGana.setPosition(620, 375);
		quienGana.setColor(sf::Color::Green);
		ventana.draw(quienGana);
	}
	
	if(ganaO==false&&ganaX==false&&hayEmpate==false){
	if (jugador == 2) {
		quienJuega = sf::Text("Juega: X", font, 110U);
		quienJuega.setPosition(620, 50);
		quienJuega.setColor(sf::Color::Green);
		ventana.draw(quienJuega);
	}
	else if (jugador == 3) {
		quienJuega = sf::Text("Juega: O", font, 110U);
		quienJuega.setPosition(620, 50);
		quienJuega.setColor(sf::Color::Green);
		ventana.draw(quienJuega);
	}
	}

	if (ganaO == true || ganaX == true||hayEmpate==true) {

		quiereVolverJugar = sf::Text("¿Volver a jugar?", font, 80U);
		quiereVolverJugar.setPosition(620, 50);
		quiereVolverJugar.setColor(sf::Color::Green);
		ventana.draw(quiereVolverJugar);

		volverJugarSi = sf::Text("Si (s)", font, 70U);
		volverJugarSi.setPosition(650, 200);
		volverJugarSi.setColor(sf::Color::White);
		ventana.draw(volverJugarSi);

		volverJugarNo= sf::Text("No (n)", font, 70U);
		volverJugarNo.setPosition(800, 200);
		volverJugarNo.setColor(sf::Color::White);
		ventana.draw(volverJugarNo);

		sf::Event event;
		while (ventana.pollEvent(event))
		{
		switch (event.type) {
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::S:
				vuelveJugar = true;
				ganaO = false;
				break;
			case sf::Keyboard::N:
				exit(0);
				break;
			}
			break;
		}
		}
	}


	int contador2 = 0;
	cuadro.loadFromFile("cuadro.png");
	imagenCuadro.setTexture(cuadro);

	x.loadFromFile("x.png");
	imagenX.setTexture(x);

	o.loadFromFile("o.png");
	imagenO.setTexture(o);

	menuEnJuego.loadFromFile("menu.png");
	imagenMenuEnJuego.setTexture(menuEnJuego);

	numero1.loadFromFile("1.png");
	numero2.loadFromFile("2.png");
	numero3.loadFromFile("3.png");
	numero4.loadFromFile("4.png");
	numero5.loadFromFile("5.png");
	numero6.loadFromFile("6.png");
	numero7.loadFromFile("7.png");
	numero8.loadFromFile("8.png");
	numero9.loadFromFile("9.png");

	for (int i = 0;i < 9;i++) {
		if (i == 0) {
			contador[i].setTexture(numero1);
		}
		if (i == 1) {
			contador[i].setTexture(numero2);
		}
		if (i == 2) {
			contador[i].setTexture(numero3);
		}
		if (i == 3) {
			contador[i].setTexture(numero4);
		}
		if (i == 4) {
			contador[i].setTexture(numero5);
		}
		if (i == 5) {
			contador[i].setTexture(numero6);
		}
		if (i == 6) {
			contador[i].setTexture(numero7);
		}
		if (i == 7) {
			contador[i].setTexture(numero8);
		}
		if (i == 8) {
			contador[i].setTexture(numero9);
		}

	}


	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			imagenCuadro.setPosition(j * 200, i * 200);
			contador[contador2].setPosition((j * 200) + 67, (i * 200) + 65);
			ventana.draw(imagenCuadro);
			ventana.draw(contador[contador2]);
			contador2++;
		}
	}
	//guarda valor alamacena el valor de la matriz en la que posicion que va recorriendo
	//y verifica para cada jugada que valor toma para ser dibujado en pantalla.
	int guardaValor;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			guardaValor = gato[i][j];
			switch (guardaValor)
			{
			case 2: //X
				imagenCuadro.setPosition(j * 200, i * 200);
				imagenX.setPosition(j * 200+50, i * 200 + 50);
				ventana.draw(imagenCuadro);
				ventana.draw(imagenX);

				break;
			case 3: //O
				imagenCuadro.setPosition(j * 200, i * 200);
				imagenO.setPosition(j * 200 + 50, i * 200 + 50);
				ventana.draw(imagenCuadro);
				ventana.draw(imagenO);


				break;

			default: "no se cargo el archivo";
				break;
			}
		}
	}
}
//Deja la pantalla de nuevo como si no se hubiera jugado aun, el enum en no, para saber que ningún numero ha sido ingresado por teclado
void Gato::reset() {
	cambiarNumApretado(numApretado::no);
	m_perdio = false;
}
//metodo que verifica quien gana, evaluando todas las posibles combinaciones para una victoria
//en caso de haber empate lo muestra igualmente
void Gato::verificaVictoria() {

	if (gato[0][0] == 2 && gato[0][1] == 2 && gato[0][2] == 2 ||
		gato[1][0] == 2 && gato[1][1] == 2 && gato[1][2] == 2 ||
		gato[2][0] == 2 && gato[2][1] == 2 && gato[2][2] == 2 ||
		gato[0][0] == 2 && gato[1][1] == 2 && gato[2][2] == 2 ||
		gato[0][2] == 2 && gato[1][1] == 2 && gato[2][0] == 2 ||
		gato[0][0] == 2 && gato[1][0] == 2 && gato[2][0] == 2 ||
		gato[0][1] == 2 && gato[1][1] == 2 && gato[2][1] == 2 ||
		gato[0][2] == 2 && gato[1][2] == 2 && gato[2][2] == 2)
	{
		ganaX = true;
		std::cout << "gana X";
	}
	else if (gato[0][0] == 3 && gato[0][1] == 3 && gato[0][2] == 3 ||
		gato[1][0] == 3 && gato[1][1] == 3 && gato[1][2] == 3 ||
		gato[2][0] == 3 && gato[2][1] == 3 && gato[2][2] == 3 ||
		gato[0][0] == 3 && gato[1][1] == 3 && gato[2][2] == 3 ||
		gato[0][2] == 3 && gato[1][1] == 3 && gato[2][0] == 3 ||
		gato[0][0] == 3 && gato[1][0] == 3 && gato[2][0] == 3 ||
		gato[0][1] == 3 && gato[1][1] == 3 && gato[2][1] == 3 ||
		gato[0][2] == 3 && gato[1][2] == 3 && gato[2][2] == 3)
	{
		ganaO = true;
		std::cout << "gana O";
	}
	else{
		int contadorEmpate = 0;
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				if (gato[i][j] != 1) {
					contadorEmpate++;
				}
			}
		}
		if (contadorEmpate==9){
			hayEmpate = true;
		}
	}
}
//maneja los eventos para el juego uno contra uno
//asignando los turnos y validando las pocisiones en caso de que ya esten ocupadas.
void Gato::actualizar() {
	
		if (m_numApretado == numApretado::no) {
		return;
		}
		if (m_numApretado == numApretado::uno) {
		
			if (jugador == 2&&gato[0][0]!=2&&gato[0][0]!=3) {
				gato[0][0] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if(jugador==3 && gato[0][0] != 2 && gato[0][0] != 3){
				gato[0][0] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::dos) {
			if (jugador == 2 && gato[0][1] != 2 && gato[0][1] != 3) {
				gato[0][1] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[0][1] != 2 && gato[0][1] != 3) {
				gato[0][1] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::tres) {
			if (jugador == 2 && gato[0][2] != 2 && gato[0][2] != 3) {
				gato[0][2] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[0][2] != 2 && gato[0][2] != 3) {
				gato[0][2] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
	    if (m_numApretado == numApretado::cuatro) {
			if (jugador == 2 && gato[1][0] != 2 && gato[1][0] != 3) {
				gato[1][0] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[1][0] != 2 && gato[1][0] != 3) {
				gato[1][0] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
	    if (m_numApretado == numApretado::cinco) {
			if (jugador == 2 && gato[1][1] != 2 && gato[1][1] != 3) {
				gato[1][1] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[1][1] != 2 && gato[1][1] != 3) {
				gato[1][1] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::seis) {
			if (jugador == 2 && gato[1][2] != 2 && gato[1][2] != 3) {
				gato[1][2] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[1][2] != 2 && gato[1][2] != 3) {
				gato[1][2] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::siete) {
			if (jugador == 2 && gato[2][0] != 2 && gato[2][0] != 3) {
				gato[2][0] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[2][0] != 2 && gato[2][0] != 3) {
				gato[2][0] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::ocho) {
			if (jugador == 2 && gato[2][1] != 2 && gato[2][1] != 3) {
				gato[2][1] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[2][1] != 2 && gato[2][1] != 3) {
				gato[2][1] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::nueve) {
			if (jugador == 2 && gato[2][2] != 2 && gato[2][2] != 3) {
				gato[2][2] = 2;
				m_numApretado = numApretado::no;
				jugador++;
			}
			else if (jugador == 3 && gato[2][2] != 2 && gato[2][2] != 3) {
				gato[2][2] = 3;
				m_numApretado = numApretado::no;
				jugador--;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
	}
//maneja los eventos del juego contra la computadora
//asignando los turnos de computadora y jugador, de igual manera
//validando si los campos estan ocupados o no.
void Gato::actualizarCompu() {

		if (m_numApretado == numApretado::no) {
			return;
		}
		if (m_numApretado == numApretado::uno) {

			if (jugador == 2 && gato[0][0] != 2 && gato[0][0] != 3) {
				gato[0][0] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
				std::cout << jugador;
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::dos) {
			if (jugador == 2 && gato[0][1] != 2 && gato[0][1] != 3) {
				gato[0][1] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::tres) {
			if (jugador == 2 && gato[0][2] != 2 && gato[0][2] != 3) {
				gato[0][2] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::cuatro) {
			if (jugador == 2 && gato[1][0] != 2 && gato[1][0] != 3) {
				gato[1][0] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::cinco) {
			if (jugador == 2 && gato[1][1] != 2 && gato[1][1] != 3) {
				gato[1][1] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}

			else {
				std::cout << "Ficha ocupada, seleccione otra" << std::endl;
				std::cout << gato[1][2];
			}
		}
		if (m_numApretado == numApretado::seis) {
			if (jugador == 2 && gato[1][2] != 2 && gato[1][2] != 3) {
				gato[1][2] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::siete) {
			if (jugador == 2 && gato[2][0] != 2 && gato[2][0] != 3) {
				gato[2][0] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::ocho) {
			if (jugador == 2 && gato[2][1] != 2 && gato[2][1] != 3) {
				gato[2][1] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
			}
		}
		if (m_numApretado == numApretado::nueve) {
			if (jugador == 2 && gato[2][2] != 2 && gato[2][2] != 3) {
				gato[2][2] = 2;
				m_numApretado = numApretado::no;
				turnoComputadora();
			}
			else {
				std::cout << "Ficha ocupada, seleccione otra";
				std::cout << jugador;
				std::cout << gato[2][2];
			}
		}
	}
//metodo que genera un numero tomando en cuenta la posicion marcada por el jugador
//el numero generado va a ser la posicion de la computadora en el gato.
int Gato::miniMax(int &x, int &y, int torn) {
		int best = -2;
		int z, t;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (gato[i][j] != 1) continue;
				gato[i][j] = torn;
				if (1 == torn) {
					x = i;
					y = j;
					return 1;
				}
				gato[i][j] = torn;
				int aux = miniMax(z, t, (torn == 1) ? 2 : 1);
				if (aux == -2 || aux == 0) {
					if (best < 0) {
						best = 0;
						x = i;
						y = j;
					}
				}
				else if (aux == -1) {
					if (best < 1) {
						best = 1;
						x = i;
						y = j;
						gato[i][j] = 1;
						return best;
					}
				}
				else if (aux == 1) {
					if (best < -1) {
						best = -1;
						x = i;
						y = j;
					}
				}
				gato[i][j] = 1;

			}
		}
		return best;
	}
//metodo recursivo, que llama a minimax para generar la posicion de la computadora en el juego.
//y asigna el turno a jugador.
	void Gato::turnoComputadora() {
		int x, y;
		int aux = miniMax(x, y, 1);
		gato[x][y] = 3;
		jugador = 2;
	}

		

