#include <stdio.h>
#include <stdlib.h>

int main(){

    int i,n;
    printf("Digite o limite superior:\n");
    scanf("%d", &n);
    printf("\t\t\t\t*************************\n");
    printf("\t\t\t\t*   x  |       x^2      *\n");
    printf("\t\t\t\t*-----------------------*\n");
    i=1;
    while(i <= n){
        printf("\t\t\t\t*%4d  |%10d      *\n", i, i*i);
        i++;
    }
    printf("\t\t\t\t*************************\n");
    printf("\t\t\t\t\n\n");


    system("pause");
    return 0;
    }
