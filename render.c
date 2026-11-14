#include <stdio.h>

#include "model.c"

void dibujar_tablero() {
  printf(" %c | %c | %c \n", modelo.casillas[0], modelo.casillas[1],
         modelo.casillas[2]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", modelo.casillas[3], modelo.casillas[4],
         modelo.casillas[5]);
  printf("---|---|---\n");
  printf(" %c | %c | %c \n", modelo.casillas[6], modelo.casillas[7],
         modelo.casillas[8]);
}

void mostrar_resultado() {
  if (modelo.ganador == ' ') {
    printf("\nJugador actual: %c\n", modelo.jugador_actual);
  } else if (modelo.ganador == '-') {
    printf("\nEmpate!\n");
  } else {
    printf("\nGanador: %c\n", modelo.ganador);
  }
}

void render() {
  system("cls");
  dibujar_tablero();
  mostrar_resultado();
}
