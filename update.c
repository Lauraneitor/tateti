#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

#include "model.c"

bool update() {
  char entrada;
  scanf(" %c", &entrada);
  if ('1' == entrada) {
    casilla1 = 'X';
  } else if ('2' == entrada) {
    casilla2 = 'X';
  } else if ('3' == entrada) {
    casilla3 = 'X';
  } else if ('4' == entrada) {
    casilla4 = 'X';
  } else if ('5' == entrada) {
    casilla5 = 'X';
  } else if ('6' == entrada) {
    casilla6 = 'X';
  } else if ('7' == entrada) {
    casilla7 = 'X';
  } else if ('8' == entrada) {
    casilla8 = 'X';
  } else if ('9' == entrada) {
    casilla9 = 'X';
  }

  return '0' == entrada;
}