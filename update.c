#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#include "model.c"

bool update() {
  char entrada;
  scanf(" %c", &entrada);
  if ('1' == entrada) {
    casilla1 = jugador_actual;
  } else if ('2' == entrada) {
    casilla2 = jugador_actual;
  } else if ('3' == entrada) {
    casilla3 = jugador_actual;
  } else if ('4' == entrada) {
    casilla4 = jugador_actual;
  } else if ('5' == entrada) {
    casilla5 = jugador_actual;
  } else if ('6' == entrada) {
    casilla6 = jugador_actual;
  } else if ('7' == entrada) {
    casilla7 = jugador_actual;
  } else if ('8' == entrada) {
    casilla8 = jugador_actual;
  } else if ('9' == entrada) {
    casilla9 = jugador_actual;
  }
  if (jugador_actual == 'X') {
    jugador_actual = 'O';
  } else {
    jugador_actual = 'X';
  }

  return '0' == entrada;
}