#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,n;
    printf("Digite o numero de repeticoes:\n");
    scanf("%d", &n);
    printf("\t\t\t\t*************************\n");
    printf("\t\t\t\t*   i  |  Mensagem      *\n");
    printf("\t\t\t\t*-----------------------*\n");
    i=1;
    while(i <= n){
        printf("\t\t\t\t*%4d  |  Hello world   *\n", i);
        i++;
    }
    printf("\t\t\t\t*************************\n");
    printf("\t\t\t\t\n\n");


    system("pause");
    return 0;
    }
