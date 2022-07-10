#include <unistd.h>

//poner fin de linea y tal
void    putchar(char spray){
    write(1, &spray , 1);
}