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
  for (int i = 0; i < 8; i++) {
    int a = COMBINACIONES_GANADORAS[i][0];
    int b = COMBINACIONES_GANADORAS[i][1];
    int c = COMBINACIONES_GANADORAS[i][2];

    if (casillas[a] != ' ' && casillas[a] == casillas[b] &&
        casillas[b] == casillas[c]) {
      ganador = jugador_actual;
      return true;
    }
  }
  return false;
}

bool hay_empate() {
  for (int i = 0; i < 9; i++) {
    if (casillas[i] == ' ') {
      return false;
    }
  }
  ganador = '-';
  return true;
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
