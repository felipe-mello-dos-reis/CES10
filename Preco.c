#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; float preco;
    printf("Numero de cadernos:");
    scanf("%d",&n);
    printf("Preco do caderno:");
    scanf("%f",&preco);
    printf("O preco de %d cadernos eh %g", n,n*preco);
    printf("\n\n");
    system("pause");
    return 0;
    }
