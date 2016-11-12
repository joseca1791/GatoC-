#ifndef JUEGO_H
#define JUEGO_H

#include "Window.h"
#include "Gato.h"

class Juego {
public: 
	Juego();
	~Juego();

	Window* getWindow();	
	void manejarEntrada();
	void iniciar();
	void render();
	void actualizar();

	void iniciarCompu();
	void actualizarCompu();


private:
	Window m_window;
	Gato m_gato;

};
#endif // !JUEGO_H

