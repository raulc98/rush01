#include <unistd.h>

//poner fin de linea y tal
void    pintar(char a, int esFinal){
    //write lo que sea
    write(1, &a , 1);

    if(esFinal == 1){
        printf("\n");
    }
}