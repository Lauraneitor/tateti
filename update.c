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

bool jugar_casilla(char* casilla) {
  if (*casilla == ' ') {
    *casilla = jugador_actual;
  } else {
    return INVALIDA;
  }
  return VALIDA;
}

bool jugar(char casilla) {
  if ('1' == casilla) {
    return jugar_casilla(&casilla1);
  } else if ('2' == casilla) {
    return jugar_casilla(&casilla2);
  } else if ('3' == casilla) {
    return jugar_casilla(&casilla3);
  } else if ('4' == casilla) {
    return jugar_casilla(&casilla4);
  } else if ('5' == casilla) {
    return jugar_casilla(&casilla5);
  } else if ('6' == casilla) {
    return jugar_casilla(&casilla6);
  } else if ('7' == casilla) {
    return jugar_casilla(&casilla7);
  } else if ('8' == casilla) {
    return jugar_casilla(&casilla8);
  } else if ('9' == casilla) {
    return jugar_casilla(&casilla9);
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
#define FIN_JUEGO false

bool update() {
  char entrada;
  scanf(" %c", &entrada);
  if (entrada == '0') {
    return FIN_JUEGO;
  }

  if (jugar(entrada) == INVALIDA) {
    return CONTINUAR_JUEGO;
  }

  if (hay_ganador() || hay_empate()) {
    return FIN_JUEGO;
  }

  cambiar_jugador();

  return CONTINUAR_JUEGO;
}