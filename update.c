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

bool jugar(char entrada) {
  if ('1' == entrada) {
    if (casilla1 == ' ') {
      casilla1 = jugador_actual;
    } else {
      return true;
    }
  } else if ('2' == entrada) {
    if (casilla2 == ' ') {
      casilla2 = jugador_actual;
    } else {
      return true;
    }
  } else if ('3' == entrada) {
    if (casilla3 == ' ') {
      casilla3 = jugador_actual;
    } else {
      return true;
    }
  } else if ('4' == entrada) {
    if (casilla4 == ' ') {
      casilla4 = jugador_actual;
    } else {
      return true;
    }
  } else if ('5' == entrada) {
    if (casilla5 == ' ') {
      casilla5 = jugador_actual;
    } else {
      return true;
    }
  } else if ('6' == entrada) {
    if (casilla6 == ' ') {
      casilla6 = jugador_actual;
    } else {
      return true;
    }
  } else if ('7' == entrada) {
    if (casilla7 == ' ') {
      casilla7 = jugador_actual;
    } else {
      return true;
    }
  } else if ('8' == entrada) {
    if (casilla8 == ' ') {
      casilla8 = jugador_actual;
    } else {
      return true;
    }
  } else if ('9' == entrada) {
    if (casilla9 == ' ') {
      casilla9 = jugador_actual;
    } else {
      return true;
    }
  }
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

#define FIN_JUEGO false

bool update() {
  char entrada;
  scanf(" %c", &entrada);

  // FIX: resolver superpociciones de casillas
  jugar(entrada);

  if (hay_ganador() || hay_empate()) {
    return FIN_JUEGO;
  }

  cambiar_jugador();

  return '0' != entrada;
}