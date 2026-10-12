#include <stdio.h>

#include "model.c"

void dibujar_tablero() {
  printf(" %c | %c | %c \n", casillas[0], casillas[1], casillas[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casillas[3], casillas[4], casillas[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", casillas[6], casillas[7], casillas[8]);
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

void render() {
  system("cls");
  dibujar_tablero();
  mostrar_resultado();
}
