#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#include "model.c"

void cambiar_jugador() {
  if (jugador_actual == 'X') {
    jugador_actual = 'O';
  } else {
    jugador_actual = 'X';
  }
}

#define VALIDA true
#define INVALIDA false

bool intentar_jugar(char jugada) {
  int indice = jugada - '1';
  if (indice < 0 || indice > 8) {
    return INVALIDA;
  }
  if (casillas[indice] == ' ') {
    casillas[indice] = jugador_actual;
    return VALIDA;
  }
  return INVALIDA;
}

bool hay_ganador() {
  if (casillas[0] != ' ' && casillas[0] == casillas[1] &&
      casillas[1] == casillas[2]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[3] != ' ' && casillas[3] == casillas[4] &&
             casillas[4] == casillas[5]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[6] != ' ' && casillas[6] == casillas[7] &&
             casillas[7] == casillas[8]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[0] != ' ' && casillas[0] == casillas[3] &&
             casillas[3] == casillas[6]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[1] != ' ' && casillas[1] == casillas[4] &&
             casillas[4] == casillas[7]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[2] != ' ' && casillas[2] == casillas[5] &&
             casillas[5] == casillas[8]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[0] != ' ' && casillas[0] == casillas[4] &&
             casillas[4] == casillas[8]) {
    ganador = jugador_actual;
    return true;
  } else if (casillas[2] != ' ' && casillas[2] == casillas[4] &&
             casillas[4] == casillas[6]) {
    ganador = jugador_actual;
    return true;
  } else {
    return false;
  }
}

bool hay_empate() {
  if (casillas[0] != ' ' && casillas[1] != ' ' && casillas[2] != ' ' &&
      casillas[3] != ' ' && casillas[4] != ' ' && casillas[5] != ' ' &&
      casillas[6] != ' ' && casillas[7] != ' ' && casillas[8] != ' ') {
    ganador = '-';
    return true;
  } else {
    return false;
  }
}

#define CONTINUAR_JUEGO true
#define SALTEAR_JUGADA true
#define FIN_JUEGO false

bool update() {
  char jugada;
  scanf(" %c", &jugada);
  if (jugada == '0') {
    return FIN_JUEGO;
  }

  if (intentar_jugar(jugada) == INVALIDA) {
    return SALTEAR_JUGADA;
  }

  if (hay_ganador() || hay_empate()) {
    return FIN_JUEGO;
  }

  cambiar_jugador();

  return CONTINUAR_JUEGO;
}