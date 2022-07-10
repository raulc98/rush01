#include <stdio.h>
#include <unistd.h>
//#include "ft_putchar.c"


void paint_corners_a();

void paint_corners_c(int is_final);

void paint_borders(int is_final);

void paint_rest();

void     painter_controller_horizonal(int x, int y, int max_x, int max_y);

void     painter_controller_middle(int x,int y , int max_x, int max_y);

void     painter_controller_left(int y,int max_y);

void     painter_controller_rigth(int y,int max_y);

void     print_controller(int x, int y);

void rush(int x,int y)
{
    if(x > 0 && y > 0)
    {
        print_controller(x,y);
    }
}

void print_controller(int max_x, int max_y)
{
    int e_y = 1;
    while(max_y >= e_y){
            //contador y while del x del cuadrado
        int e_x = 1;
        while(max_x >= e_x){
            //entramos en las condiciones para que pinte una cosa u otra.
            painter_controller_horizonal(e_x,e_y,max_x,max_y);
            e_x ++;
        }
        e_y ++;
    }
}

//Método que pinta los caracteres
void     painter_controller_horizonal(int x, int y, int max_x, int max_y)
{
    char spray;

    if(x == 1)
    {
        painter_controller_left(y,max_y);
    }
    else if(x == max_x)
    {
        painter_controller_rigth(y,max_y);
    }
    else{
        painter_controller_middle(x,y,max_x,max_y);
    }
    
}

void painter_controller_left(int y, int max_y)
{
    int is_final;
    if(y == 1){
        paint_corners_a();
    }else if(y == max_y){
        is_final = 0;
        paint_corners_c(is_final);
    }else{
        is_final = 0;
        paint_borders(is_final);
    }
}

void painter_controller_middle(int x, int y, int max_x, int max_y)
{
    int is_final;
    if(y == 1 && x != 1 && x != max_x){
        is_final = 0;
        paint_borders(is_final);
    }else if(y == max_y && x != 1 && x != max_x){
        is_final = 0;
        paint_borders(is_final);
    }
    else{
        paint_rest();
    }
}

void painter_controller_rigth(int y, int max_y)
{
    int is_final;
    if(y == 1){
        is_final = 1;
        paint_corners_c(is_final);
    }else if(y == max_y){
        paint_corners_a();
    }
    else{
        is_final = 1;
        paint_borders(is_final);
    }
}



void paint_corners_c(int is_final)
{
    char spray;

    spray = 'C';
    putchar(spray);
    if(is_final){
        spray = '\n';
        putchar(spray);
    }
}

void paint_corners_a()
{
    char spray;

    spray = 'A';
    putchar(spray);
}

void paint_borders(int is_final)
{
    char spray;

    spray = 'B';
    putchar(spray);
    if(is_final){
        spray = '\n';
        putchar(spray);
    }
}

void paint_rest(){
    char spray;

    spray = ' ';
    putchar(spray);
}