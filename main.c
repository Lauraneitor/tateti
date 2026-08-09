#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

char casilla1 = ' ';
char casilla2 = ' ';
char casilla3 = ' ';
char casilla4 = ' ';
char casilla5 = ' ';
char casilla6 = ' ';
char casilla7 = ' ';
char casilla8 = ' ';
char casilla9 = ' ';


void render(){
    system("cls");  
    printf(" %c | %c | %c \n", casilla1, casilla2, casilla3);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", casilla4, casilla5, casilla6);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", casilla7, casilla8, casilla9);
}
bool update(){
    char entrada;
    scanf(" %c", &entrada);
    if ('1'==entrada) {
        casilla1 = 'X';
    }else if ('2' == entrada){
    casilla2='X';
    }else if ('3' == entrada){
    casilla3='X';
    }else if ('4' == entrada){
    casilla4='X';
    }else if ('5' == entrada){
    casilla5='X';
    }else if ('6' == entrada){
    casilla6='X';
    }else if ('7' == entrada){
    casilla7='X';
    }else if ('8' == entrada){
    casilla8='X';
    }else if ('9' == entrada){
    casilla9='X';
    }
    return '0'==entrada;
}

int main() {
    do render();
    while (!update());
}


