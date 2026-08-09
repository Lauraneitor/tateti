#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int num =1;


void render(){
    printf("%d\n", num);
}
bool update(){
    num++;
    Sleep(1000); // Sleep for 1 second
    return num <= 10;
}

int main() {
    while (update()) render();
}
