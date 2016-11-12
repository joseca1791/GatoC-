#include "Juego.h"
#include <Windows.h>
#include "Menu.h"
//inicializa la ventan del juego.
Juego::Juego():	m_window("Gato",sf::Vector2u(1000,600))
{
}
//constructor.
Juego::~Juego(){
}
//Retorna la ventana sobre la cual se está trabajando, con una referencia a un objeto de tipo ventana.
Window* Juego::getWindow() {
	return &m_window;
}
//metodo que maneja la entrada de los eventos que se van a utilizar en los metodos de juego.
//asignando los valores que van a ser utilizados para el modo de juego.
void Juego::manejarEntrada() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
		std::cout << "Juega 1";
		m_gato.cambiarNumApretado(numApretado::uno);
		Sleep(150);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
		std::cout << "Juega 2";
		m_gato.cambiarNumApretado(numApretado::dos);
		Sleep(150);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad3)) {
		std::cout << "Juega 3";
		m_gato.cambiarNumApretado(numApretado::tres);
		Sleep(150);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4)) {
		std::cout << "Juega 4";
		m_gato.cambiarNumApretado(numApretado::cuatro);
		Sleep(150);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5)) {
		std::cout << "Juega 5";
		m_gato.cambiarNumApretado(numApretado::cinco);
		Sleep(150);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6)) {
		std::cout << "Juega 6";
		m_gato.cambiarNumApretado(numApretado::seis);
		Sleep(150);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7)) {
		std::cout << "Juega 7";
		m_gato.cambiarNumApretado(numApretado::siete);
		Sleep(150);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
		std::cout << "Juega 8";
		m_gato.cambiarNumApretado(numApretado::ocho);
		Sleep(150);
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9)) {
		std::cout << "Juega 9";
		m_gato.cambiarNumApretado(numApretado::nueve);
		Sleep(150);
	} else{
		numApretado::no;
	}
}
//El render dibuja el juego, primero se limpia la pantalla sobre la que se este trabajando y luego se hace render (dibujo) del gato.
void Juego::render() {
	m_window.limpiar();
	m_gato.render(*m_window.getWindow());
	m_window.desplegar();
}
//metodo que mantiene el juego uno contra uno en accion, por ejemplo 
//el reiniciar la partida y manejar la entrada.
void Juego::iniciar() {
	m_gato.matriz();
	while (!m_window.haTerminado()) {
		manejarEntrada();
		actualizar();
		if (m_gato.vuelveJugar == true) {
			iniciar();
		}
		render();
	}
}
//se encarga del modo de juego uno contra uno, actualiza los turnos jugados y verifica la victoria 
//en caso de que exista.
void Juego::actualizar() {
	m_window.actualizar();
	m_gato.verificaVictoria();

	m_gato.actualizar();
	m_gato.cambiarNumApretado(numApretado::no);
}
//metodo encargado de mantener el jugador vs computadora en accion
//maneja el reinicio del juego y la entrada, asi como el actualizar.
void Juego::iniciarCompu(){
	m_gato.matriz();
	while (!m_window.haTerminado()) {
		manejarEntrada();
		actualizarCompu();
		if (m_gato.vuelveJugar == true) {
			iniciarCompu();
		}
		render();
	}
}
//se encarga del modo de juego jugador vs computadora, actualiza los turnos, maneja los eventos
//y verifica victoria en caso de que exista.
void Juego::actualizarCompu() {
	m_window.actualizar();
	m_gato.verificaVictoria();
	m_gato.actualizarCompu();
	m_gato.cambiarNumApretado(numApretado::no);
}