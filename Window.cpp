// window.cpp
// Contiene la implementaci�n de las funciones de la clase "Window"

#include "Window.h"


// Constructor - Por defecto
Window::Window() {
	configuracion("Ventana", sf::Vector2u(640, 480));
}

// Constructor - Toma los par�metros b�sicos de la ventana, como el t�tulo y tama�o
Window::Window(const std::string& titulo, const sf::Vector2u& tam) {
	configuracion(titulo, tam);
}

// Destructor
Window::~Window() {
	destruir();
}

// Retorna el tama�o de la ventana
sf::Vector2u Window::getTamVentana() {
	return m_windowTam;
}

// Retorna una referencia al objeto ventana actual
sf::RenderWindow* Window::getWindow() {
	return &m_window;
}

// Inicializa la ventana
void Window::limpiar() {
	m_window.clear(sf::Color::Black);
}

// Despliega la ventana y todos los elementos que contiene en el monitor. No es sino hasta este m�todo
// que el resultado de los cambios realizados se visualiza
void Window::desplegar() {
	m_window.display();
}

// Actualiza el estado de la ventana de acuerdo a los eventos 
void Window::actualizar() {
	sf::Event evento;
	while (m_window.pollEvent(evento)) {
		if (evento.type == sf::Event::Closed)
			m_haTerminado = true;
		else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::Escape)
			m_haTerminado = true;
	}
}

// Dibuja el elemento dentro de la ventana. �nicamente lo dibuja en memoria, es necesario llamar a la funci�n
// 'desplegar()' para mostrar el elemento en pantalla
void Window::dibujar(sf::Drawable& elemento) {
	m_window.draw(elemento);
}

// Establece si el usuario seleccion� cerrar la ventana
bool Window::haTerminado() {
	return m_haTerminado;
}

// Establece los par�metros de configuraci�n de la ventana, como el t�tulo y el tama�o;
void Window::configuracion(const std::string& titulo, const sf::Vector2u& tam) {
	m_windowTitulo = titulo;
	m_windowTam = tam;
	m_haTerminado = false;
	crear();
}

// Crea la ventana con todos los par�metros de configuraci�n previamente establecidos
void Window::crear() {
	m_window.create({ m_windowTam.x, m_windowTam.y, 32 }, m_windowTitulo, sf::Style::Default);
}

// Destruye y elimina la ventana de la pantalla
void Window::destruir() {
	m_window.close();
}