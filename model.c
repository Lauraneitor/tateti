#pragma once

char COMBINACIONES_GANADORAS[8][3] = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Filas
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Columnas
    {0, 4, 8}, {2, 4, 6}              // Diagonales
};
char casillas[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char jugador_actual = 'X';
char ganador = ' ';
