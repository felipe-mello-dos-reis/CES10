#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, achou;
    char c;
    printf("DIVISORES DE VARIOS NUMEROS MAIORES QUE 1\n\n");
    do
    {
        printf("Divisores de um numero?(s/n)\n");
        do
        {

            scanf("%c", &c);
            fflush (stdin);

            if(c != 's' && c != 'S' && c != 'n' && c != 'N')
            {
                printf("Entrada invalida; digite novamente:\n");
            }
        }
        while(c != 's' && c != 'S' && c != 'n' && c != 'N');

        if(c == 's' || c == 'S')
        {
            printf("Digite um numero maior que 1:\n");
            scanf("%d", &n);
            while(n < 2)
            {
                printf("Numero improprio; digite novamente:\n");
                scanf("%d", &n);
            }
            printf("Divisores de %d:\n", n);
            i = 2;
            achou = 0;
            while(i <= n/2)
            {
                if(n % i == 0)
                {
                    printf("%d\n", i);
                    achou = 1;
                }
                i = i + 1;
            }
            if(achou == 0)
                printf("%d eh primo\n", n);

        }

        fflush (stdin);
    }
    while(c == 's' || c == 'S');
    system("pause");
    return 0;

}
