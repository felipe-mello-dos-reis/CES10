#include <stdio.h>
#include <stdlib.h>
#include <math.h>    //inclui a função sqrt, log, pow
int main(){

    int x, n;
    printf("Determine os limites superior e inferior da tabela:");
    scanf("%d %d", &x, &n);
    printf("\n\n");
    printf("\t\t\t\t**********************************************************************************\n");
    printf("\t\t\t\t*        x  *         x^4-20x^2+5 *          sin<x> *                  x^7/ln<x> *\n");
    printf("\t\t\t\t* ------------------------------------------------------------------------------ *\n");

    while(x <= n){
        if(x > 0 && x != 1){
            printf("\t\t\t\t*%9d  *%20d *%16.7f *  %25.7f *\n", x, x*x*x*x - 20*x*x + 5, sin(x*3.14159/180), pow(x,7)/log(x));   //escreve em 15 espaços, com 8 casas deccimais
        }
        else{
            printf("\t\t\t\t*%9d  *%20d *%16.7f *  %25s *\n", x, x*x*x*x - 20*x*x + 5, sin(x*3.14159/180), "----------");   //escreve em 15 espaços, com 8 casas deccimais
        }
        x++;
    }
    printf("\t\t\t\t**********************************************************************************\n");
    printf("\n\n");


    system("pause");
    return 0;
    }
