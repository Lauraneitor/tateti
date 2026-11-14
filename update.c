#include <stdbool.h>
#include <stdio.h>

#include "model.c"

void cambiar_jugador() {
  if (modelo.jugador_actual == 'X') {
    modelo.jugador_actual = 'O';
  } else {
    modelo.jugador_actual = 'X';
  }
}

#define VALIDA true
#define INVALIDA false

bool intentar_jugar(char jugada) {
  int indice = jugada - '1';
  if (indice < 0 || indice > 8) {
    return INVALIDA;
  }
  if (modelo.casillas[indice] == ' ') {
    modelo.casillas[indice] = modelo.jugador_actual;
    return VALIDA;
  }
  return INVALIDA;
}

bool hay_ganador() {
  for (int i = 0; i < 8; i++) {
    int a = COMBINACIONES_GANADORAS[i][0];
    int b = COMBINACIONES_GANADORAS[i][1];
    int c = COMBINACIONES_GANADORAS[i][2];

    if (modelo.casillas[a] != ' ' && modelo.casillas[a] == modelo.casillas[b] &&
        modelo.casillas[b] == modelo.casillas[c]) {
      modelo.ganador = modelo.jugador_actual;
      return true;
    }
  }
  return false;
}

bool hay_empate() {
  for (int i = 0; i < 9; i++) {
    if (modelo.casillas[i] == ' ') {
      return false;
    }
  }
  modelo.ganador = '-';
  return true;
}

#define CONTINUAR_JUEGO true
#define SALTEAR_JUGADA true
#define FIN_JUEGO false

bool update() {
  char jugada = getchar();
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
