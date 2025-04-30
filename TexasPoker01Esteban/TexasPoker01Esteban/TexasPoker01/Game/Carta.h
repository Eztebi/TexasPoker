#pragma once
#include "../raylib/raylib.h"

struct Carta {
	int tipo;
	int valor;
	Texture2D imagen;
}; 

Carta llenarCarta(int tipo, int valor, const char nombre[32] = { 0 });
Carta llenarAnverso();
void llenarTodo(Carta miscartas[52]);
void borrarTodo(Carta miscartas[51]);
