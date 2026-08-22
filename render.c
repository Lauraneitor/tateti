#include <stdio.h>

#include "model.c"

void render() {
  system("cls");
  printf(" %c | %c | %c \n", casilla1, casilla2, casilla3);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casilla4, casilla5, casilla6);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casilla7, casilla8, casilla9);

  printf("\nJugador actual: %c\n", jugador_actual);
}