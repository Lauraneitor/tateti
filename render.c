#include <stdio.h>

#include "model.c"

void render() {
  system("cls");
  dibujar_tablero();
  mostrar_resultado();
}

void dibujar_tablero() {
  printf(" %c | %c | %c \n", casilla1, casilla2, casilla3);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casilla4, casilla5, casilla6);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casilla7, casilla8, casilla9);
}

void mostrar_resultado() {
  if (ganador == ' ') {
    printf("\nJugador actual: %c\n", jugador_actual);
  } else if (ganador == '-') {
    printf("\nEmpate!\n");
  } else {
    printf("\nGanador: %c\n", ganador);
  }
}
