#include "Carta.h"

Carta llenarCarta(int tipo, int valor, const char nombre[32])
{
	Carta retCarta;
	retCarta.tipo = tipo;
	retCarta.valor = valor;
	retCarta.imagen=LoadTexture(nombre);
	return retCarta;
}
 Carta llenarAnverso() {
	
	return llenarCarta(5,0,"resources/Anverso.png");
}
void llenarTodo(Carta miscartas[52]) {
	miscartas[0] = llenarCarta(1, 1, "resources/CoraA.png");
	miscartas[1] = llenarCarta(1, 2, "resources/Cora2.png");
	miscartas[2] = llenarCarta(1, 3, "resources/Cora3.png");
	miscartas[3] = llenarCarta(1, 4, "resources/Cora4.png");
	miscartas[4] = llenarCarta(1, 5, "resources/Cora5.png");
	miscartas[5] = llenarCarta(1, 6, "resources/Cora6.png");
	miscartas[6] = llenarCarta(1, 7, "resources/Cora7.png");
	miscartas[7] = llenarCarta(1, 8, "resources/Cora8.png");
	miscartas[8] = llenarCarta(1, 9, "resources/Cora9.png");
	miscartas[9] = llenarCarta(1, 10, "resources/Cora10.png");
	miscartas[10] = llenarCarta(1, 11, "resources/Cora11.png");
	miscartas[11] = llenarCarta(1, 12, "resources/Cora12.png");
	miscartas[12] = llenarCarta(1, 13, "resources/Cora13.png");

	miscartas[13] = llenarCarta(2, 1, "resources/DiaA.png");
	miscartas[14] = llenarCarta(2, 2, "resources/Dia2.png");
	miscartas[15] = llenarCarta(2, 3, "resources/Dia3.png");
	miscartas[16] = llenarCarta(2, 4, "resources/Dia4.png");
	miscartas[17] = llenarCarta(2, 5, "resources/Dia5.png");
	miscartas[18] = llenarCarta(2, 6, "resources/Dia6.png");
	miscartas[19] = llenarCarta(2, 7, "resources/Dia7.png");
	miscartas[20] = llenarCarta(2, 8, "resources/Dia8.png");
	miscartas[21] = llenarCarta(2, 9, "resources/Dia9.png");
	miscartas[22] = llenarCarta(2, 10, "resources/Dia10.png");
	miscartas[23] = llenarCarta(2, 11, "resources/Dia11.png");
	miscartas[24] = llenarCarta(2, 12, "resources/Dia12.png");
	miscartas[25] = llenarCarta(2, 13, "resources/Dia13.png");

	miscartas[26] = llenarCarta(3, 1, "resources/PicasA.png");
	miscartas[27] = llenarCarta(3, 2, "resources/Picas2.png");
	miscartas[28] = llenarCarta(3, 3, "resources/Picas3.png");
	miscartas[29] = llenarCarta(3, 4, "resources/Picas4.png");
	miscartas[30] = llenarCarta(3, 5, "resources/Picas5.png");
	miscartas[31] = llenarCarta(3, 6, "resources/Picas6.png");
	miscartas[32] = llenarCarta(3, 7, "resources/Picas7.png");
	miscartas[33] = llenarCarta(3, 8, "resources/Picas8.png");
	miscartas[34] = llenarCarta(3, 9, "resources/Picas9.png");
	miscartas[35] = llenarCarta(3, 10, "resources/Picas10.png");
	miscartas[36] = llenarCarta(3, 11, "resources/Picas11.png");
	miscartas[37] = llenarCarta(3, 12, "resources/Picas12.png");
	miscartas[38] = llenarCarta(3, 13, "resources/Picas13.png");
	
	miscartas[39] = llenarCarta(4, 1, "resources/TreA.png");
	miscartas[40] = llenarCarta(4, 2, "resources/Tre2.png");
	miscartas[41] = llenarCarta(4, 3, "resources/Tre3.png");
	miscartas[42] = llenarCarta(4, 4, "resources/Tre4.png");
	miscartas[43] = llenarCarta(4, 5, "resources/Tre5.png");
	miscartas[44] = llenarCarta(4, 6, "resources/Tre6.png");
	miscartas[45] = llenarCarta(4, 7, "resources/Tre7.png");
	miscartas[46] = llenarCarta(4, 8, "resources/Tre8.png");
	miscartas[47] = llenarCarta(4, 9, "resources/Tre9.png");
	miscartas[48] = llenarCarta(4, 10, "resources/Tre10.png");
	miscartas[49] = llenarCarta(4, 11, "resources/Tre11.png");
	miscartas[50] = llenarCarta(4, 12, "resources/Tre12.png");
	miscartas[51] = llenarCarta(4, 13, "resources/Tre13.png");
}
void borrarTodo(Carta miscartas[51])
{
	for (size_t i = 0; i < 51; i++)
		{
		UnloadTexture(miscartas[i].imagen);
		}
	
}

//corazones 1
//diamantes 2
//picas 3
//treboles 4
