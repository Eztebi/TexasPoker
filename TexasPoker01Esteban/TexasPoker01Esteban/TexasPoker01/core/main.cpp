#include "../raylib/raylib.h"
#include "../Game/Carta.h"
#include <random>
#include <thread>
#include <string>
#include <iostream>
void Acomodar(Carta Tcarta[6]) {
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 6; j++) {
            if (Tcarta[i].valor > Tcarta[j].valor) {
                // Intercambiar las cartas si están en el orden incorrecto
                Carta temp = Tcarta[i];
                Tcarta[i] = Tcarta[j];
                Tcarta[j] = temp;
            }
        }
    }
}

bool Escalera(Carta Tcarta[6]) {
    Acomodar(Tcarta);  // Ordena las cartas por valor para poder saber si van de corrido
    bool esEscalera = true;
    // Verificar si las cartas forman una escalera
    for (int i = 0; i < 5; i++) {
        if (Tcarta[i].valor == Tcarta[i + 1].valor - 1) {
            
        }
        else
        {
            esEscalera = false;
        }
    }
    
    if (esEscalera == true) {
        std::string mensaje = "Es una Escalera";
        DrawText(mensaje.c_str(), 360, 370, 10, BLACK);
        return true;
    }
    else
    {
        return false;
    }
}
void CartaMayor(Carta Tcartas[6]) {//Va viendo si la siguiente carta es mayor, si no se remplaza con la que sigue
    Carta cartamayor=Tcartas[0];
    for (int i = 0; i < 5; i++) {
        
        if (cartamayor.valor > Tcartas[i + 1].valor) {
            
        }
        else if (cartamayor.valor < Tcartas[i + 1].valor) {
            cartamayor = Tcartas[i + 1];
        }
        else
        {
           
        }
    }
    std::string mensaje = "La carta más alta es " + std::to_string(cartamayor.valor) ;
    DrawText(mensaje.c_str(), 360, 390, 10, BLACK);
}
bool FlushCarta(Carta Tcartas[6]) {
    bool flushVoF = true;
    for (int i = 0; i < 5; i++) {
        if (Tcartas[i].tipo == Tcartas[i + 1].tipo) {
            flushVoF = true;
        }
        if (Tcartas[i].tipo != Tcartas[i + 1].tipo) {
            flushVoF = false;

        }
        if (flushVoF == false) { //Si no se repite el mismo color se sale del ciclo
           // DrawText("No es un Flush ", 360, 410, 10, BLACK);
            return false;
            break;
        }
    }
    if (flushVoF == true) {
        DrawText("Es un Flush ", 360, 410, 10, BLACK);
        return true;
    }
}

bool Trio(Carta Tcartas[6]) {
    int totalTrios = 0;
    int valor1 = 0, valor2 = 0;
    bool triosContados[6] = { false };  // Para marcar qué cartas ya han sido contadas

    for (int i = 0; i < 6; i++) {
        if (!triosContados[i]) {
            int contadorTrio = 0;
            for (int j = i + 1; j < 6; j++) {
                if (Tcartas[i].valor == Tcartas[j].valor) {
                    contadorTrio++;
                    triosContados[j] = true;  // Marca la carta como contada
                }
                if (contadorTrio == 2) {

                    if (valor1 == 0) {
                        valor1 = Tcartas[i].valor;
                    }
                }
            }
                if (contadorTrio == 2) {  //si hay 3 cartas solamente se agrega 
                    totalTrios++;

                }
            }
        }

        if (totalTrios > 0) {

            std::string mensaje = "Hay " + std::to_string(totalTrios) + " trio." + " El trio es de " + std::to_string(valor1);
            DrawText(mensaje.c_str(), 360, 370, 10, BLACK);
            return true;
        }
        else {
            // DrawText("No hay pares", 360, 370, 10, BLACK);
            return false;
        }
    }

bool Par(Carta Tcartas[6]) {
    int totalPares = 0;
    int valor1=0, valor2=0, valor3=0;
    bool paresContados[6] = { false };  // Para marcar qué cartas ya han sido contadas

    for (int i = 0; i < 6; i++) {
        if (!paresContados[i]) {
            int contadorPar = 0;
            for (int j = i + 1; j < 6; j++) {
                if (Tcartas[i].valor == Tcartas[j].valor) {
                    contadorPar++;
                    paresContados[j] = true;  // Marca la carta como contada
                    
                }
                if (contadorPar == 1) {

                    if (valor1 == 0) {
                        valor1 = Tcartas[i].valor;
                    }
                    else if (valor2 == 0) {
                        valor2 = Tcartas[i].valor;
                    }
                    else if (valor3 == 0) {
                        valor3 = Tcartas[i].valor;
                    }
                }
               
            }
            if (contadorPar == 1) {  // Solo cuenta si hay exactamente 1 par
                totalPares++;
                //valor1 = Tcartas[i].valor;
            }
           
        }
    }

    if (totalPares == 1) {

        std::string mensaje = "Hay " + std::to_string(totalPares) + " pares." + " El par es de " + std::to_string(valor1);
        DrawText(mensaje.c_str(), 360, 370, 10, BLACK);
        return true;
    }
    else if (totalPares == 2) {
        if (valor1 < valor2) {
            std::string mensaje = "Hay " + std::to_string(totalPares) + " pares." + " El par es de " + std::to_string(valor1) + " y " + std::to_string(valor2)+". El valor mas alto es " + std::to_string(valor2);
            DrawText(mensaje.c_str(), 360, 380, 10, BLACK);
            return true;
        }
        else{
            std::string mensaje = "Hay " + std::to_string(totalPares) + " pares." + " El par es de " + std::to_string(valor1) + " y " + std::to_string(valor2) + ". El valor mas alto es " + std::to_string(valor1);
            DrawText(mensaje.c_str(), 360, 380, 10, BLACK);
            return true;
        }
    }
       
    
    else if (totalPares == 3) {
        std::string mensaje = "Hay " + std::to_string(totalPares) + " pares." + " El par es de " + std::to_string(valor1) + ", " + std::to_string(valor2) + "y " + std::to_string(valor3);
        DrawText(mensaje.c_str(), 360, 380, 10, BLACK);
        return true;
    }
    else {
       // DrawText("No hay pares", 360, 370, 10, BLACK);
        return false;
    }
}
int main(void)
{
 
  const int screenWidth = 900;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "TexasPoker Esteban");

  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int>dist1(30, 770);
  std::uniform_int_distribution<int>dist2(30, 420);
  std::uniform_int_distribution<int>cartaAleatorio(0, 51);
  Carta cartas[52];
  Carta TotalCartas[6];
  Carta anverso = llenarAnverso();
  llenarTodo(cartas);
  Texture2D texture = LoadTexture("resources/CoraA.png");

  SetTargetFPS(60);
  bool isDrawing = false;
  int contadorCarta = 0;
  int img = 0;
  int cartasAcomodadas = 0;
 
  //para pruebas con trio mas alto
  int Carta1 = 0;
  int Carta2 = 13;
  int Carta3 = 26;
  int Carta4 = 1;
  int Carta5 = 14;
  int Carta6 = 27;
  //pruebas trio 
  /*
  int Carta1 = 0;
  int Carta2 = 13;
  int Carta3 = 26;
  int Carta4 = 1;
  int Carta5 = 2;
  int Carta6 = 3;*/
  //Crea una carta y si no se repite con la anterior crea otra
  /*
  int Carta1 = cartaAleatorio(mt);
   int Carta2 = cartaAleatorio(mt);
   while (Carta2 == Carta1) {
       Carta2 = cartaAleatorio(mt);
   }
   int Carta3 = cartaAleatorio(mt);
   while (Carta3 == Carta1 || Carta3==Carta2) {
       Carta3 = cartaAleatorio(mt);
   }
   int Carta4 = cartaAleatorio(mt);
   while (Carta4 == Carta1 || Carta4 == Carta2 || Carta4 == Carta3) {
       Carta4 = cartaAleatorio(mt);
   }
   int Carta5 = cartaAleatorio(mt);
   while (Carta5 == Carta1 || Carta5 == Carta2 || Carta5 == Carta3 || Carta5 == Carta4) {
       Carta5 = cartaAleatorio(mt);
   }
   int Carta6 = cartaAleatorio(mt);
   while (Carta6 == Carta1 || Carta6 == Carta2 || Carta6 == Carta3 || Carta6 == Carta4 || Carta6==Carta5) {
       Carta6 = cartaAleatorio(mt);
   }
  */
 
  TotalCartas[0] = cartas[Carta1];
  TotalCartas[1] = cartas[Carta2];
  TotalCartas[2] = cartas[Carta3];
  TotalCartas[3] = cartas[Carta4];
  TotalCartas[4] = cartas[Carta5];
  TotalCartas[5] = cartas[Carta6];

  // Main game loop
  while (!WindowShouldClose())
  {

    
    //----------------------------------------------------------------------------------
    BeginDrawing();

    ClearBackground(DARKGREEN);
    
    cartas[Carta1].imagen.height = 110;
    cartas[Carta1].imagen.width = 80;
    cartas[Carta2].imagen.height = 110;
    cartas[Carta2].imagen.width = 80;
    cartas[Carta3].imagen.height = 110;
    cartas[Carta3].imagen.width = 80;
    cartas[Carta4].imagen.height = 110;
    cartas[Carta4].imagen.width = 80;
    cartas[Carta5].imagen.height = 110;
    cartas[Carta5].imagen.width = 80;
    cartas[Carta6].imagen.height = 110;
    cartas[Carta6].imagen.width = 80;
    anverso.imagen.height = 110;
    anverso.imagen.width = 80;

    int Ax = 300;
    int Ay = 200;
    int Bx = 400;
    int By = 200;
    int Cx = 500;
    int Cy = 200;
    int Dx = 600;
    int Dy= 200;
    
    int Ey = 50;
    int Fy = 50;
    int Gy = 50;
    DrawTexture(cartas[Carta1].imagen,Ax,Ay, WHITE);
    DrawTexture(cartas[Carta2].imagen,Bx, By, WHITE);
    DrawTexture(cartas[Carta3].imagen,Cx, Cy, WHITE);
    DrawTexture(anverso.imagen, Ax, Ey, WHITE);
    DrawTexture(anverso.imagen, Bx, Fy, WHITE);
    DrawTexture(anverso.imagen, Cx, Gy, WHITE);

   
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && contadorCarta!=3)
    {
        contadorCarta++;
    }

    if (contadorCarta == 1) {
        DrawTexture(cartas[Carta4].imagen, Ax, Ey, WHITE);
        DrawTexture(anverso.imagen, Bx, Fy, WHITE);
        DrawTexture(anverso.imagen, Cx, Gy, WHITE);
    }
    
    if (contadorCarta == 2) {
        DrawTexture(cartas[Carta4].imagen, Ax, Ey, WHITE);
        DrawTexture(cartas[Carta5].imagen, Bx, Fy, WHITE);
        DrawTexture(anverso.imagen, Cx, Gy, WHITE);
    }
    if (contadorCarta == 3) {
        DrawTexture(cartas[Carta4].imagen, Ax, Ey, WHITE);
        DrawTexture(cartas[Carta5].imagen, Bx, Fy, WHITE);
        DrawTexture(cartas[Carta6].imagen, Cx, Gy, WHITE);
        if (Trio(TotalCartas)) {
            Trio(TotalCartas);
        }
        else if (Par(TotalCartas)) {
            Par(TotalCartas);
       }
        else if (FlushCarta(TotalCartas)) {
            FlushCarta(TotalCartas);
            if (Escalera(TotalCartas))Escalera(TotalCartas);
        }
        else if(Escalera(TotalCartas))
        {
            Escalera(TotalCartas);
        }
        else {
            CartaMayor(TotalCartas);
        }

       
    }
    
   
    EndDrawing();
    
    //----------------------------------------------------------------------------------
  }
  UnloadTexture(texture);

  CloseWindow();

  return 0;
}