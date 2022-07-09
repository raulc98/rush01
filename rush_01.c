#include <stdio.h>
#include <unistd.h>
#include "ft_putchar.c"

//método para pintar los caracteres
void  pintarCosas(int ancho,int largo, int maxAncho, int maxLargo);

//método del rush
void rush(int ancho,int largo)
{
    int maxAncho;
    int maxLargo;
    if(ancho > 0 && largo > 0)
    {
        //recuperamos la longitud maxima del ancho y largo del cuadrado
        maxAncho = ancho;
        maxLargo = largo;
        //contador para el while vertical
        int contLargo = 1;
        while(largo >= contLargo){
            //contador y while del ancho del cuadrado
            int contAncho = 1;
            while(ancho >= contAncho){
                //entramos en las condiciones para que pinte una cosa u otra.
                pintarCosas(contAncho,contLargo,maxAncho,maxLargo);
                contAncho ++;
            }
        contLargo ++;
        }
    }
}

//Método que pinta los caracteres
void     pintarCosas(int ancho, int largo, int maxAncho, int maxLargo)
{
    //recoge el valor del char a imprimir por pantalla
    char spray;
    //variable que controla si es final de línea para poner un salto de línea
    int esFinal;
    
    //CÓDIGO DE CONTROL DEL PINTADO
    //------------
    //ESQUINAS
    //Esquina superior izquierda.
    if(ancho == 1 && largo == 1)
    {
        spray = 'A';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //Esquina inferior izquierda.
    else if(ancho == 1 && largo == maxLargo)
    {
        spray = 'C';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //Esquina superior derecha
    else if(ancho == maxAncho && largo == 1)
    {
        spray = 'C';
        esFinal = 1;
        pintar(spray,esFinal);
    }
    //Esquina inferior derecha
    else if(ancho == maxAncho && largo == maxLargo)
    {
        spray = 'A';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //BORDES
    //------------
    //borde top
    else if(ancho != 1 && ancho != maxAncho && largo == 1)
    {
        spray = 'B';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //Borde izquierdo
    else if(ancho == 1 && largo != 1 && largo != maxLargo)
    {
        spray = 'B';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //Borde abajo
    else if(ancho != 1 && ancho != maxAncho && largo == maxLargo)
    {
        spray = 'B';
        esFinal = 0;
        pintar(spray,esFinal);
    }
    //Borde derecho
    else if(ancho == maxAncho && largo != 1 && largo != maxLargo)
    {
        spray = 'B';
        esFinal = 1;
        pintar(spray,esFinal);
    }
    //RESTO
    else{
        spray = ' ';
        esFinal = 0;
        pintar(spray,esFinal);
    }
}


