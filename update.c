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

char* seleccionar_casilla(char jugada) {
  if ('1' == jugada) {
    return (&casilla1);
  } else if ('2' == jugada) {
    return (&casilla2);
  } else if ('3' == jugada) {
    return (&casilla3);
  } else if ('4' == jugada) {
    return (&casilla4);
  } else if ('5' == jugada) {
    return (&casilla5);
  } else if ('6' == jugada) {
    return (&casilla6);
  } else if ('7' == jugada) {
    return (&casilla7);
  } else if ('8' == jugada) {
    return (&casilla8);
  } else if ('9' == jugada) {
    return (&casilla9);
  }
  return NULL;
}

#define VALIDA true
#define INVALIDA false

bool intentar_jugar(char jugada) {
  char* casilla = seleccionar_casilla(jugada);
  if (casilla == NULL) {
    return INVALIDA;
  }
  if (*casilla == ' ') {
    *casilla = jugador_actual;
    return VALIDA;
  }
  return INVALIDA;
}

bool hay_ganador() {
  if (casilla1 != ' ' && casilla1 == casilla2 && casilla2 == casilla3) {
    ganador = jugador_actual;
    return true;
  } else if (casilla4 != ' ' && casilla4 == casilla5 && casilla5 == casilla6) {
    ganador = jugador_actual;
    return true;
  } else if (casilla7 != ' ' && casilla7 == casilla8 && casilla8 == casilla9) {
    ganador = jugador_actual;
    return true;
  } else if (casilla1 != ' ' && casilla1 == casilla4 && casilla4 == casilla7) {
    ganador = jugador_actual;
    return true;
  } else if (casilla2 != ' ' && casilla2 == casilla5 && casilla5 == casilla8) {
    ganador = jugador_actual;
    return true;
  } else if (casilla3 != ' ' && casilla3 == casilla6 && casilla6 == casilla9) {
    ganador = jugador_actual;
    return true;
  } else if (casilla1 != ' ' && casilla1 == casilla5 && casilla5 == casilla9) {
    ganador = jugador_actual;
    return true;
  } else if (casilla3 != ' ' && casilla3 == casilla5 && casilla5 == casilla7) {
    ganador = jugador_actual;
    return true;
  } else {
    return false;
  }
}

bool hay_empate() {
  if (casilla1 != ' ' && casilla2 != ' ' && casilla3 != ' ' &&
      casilla4 != ' ' && casilla5 != ' ' && casilla6 != ' ' &&
      casilla7 != ' ' && casilla8 != ' ' && casilla9 != ' ') {
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