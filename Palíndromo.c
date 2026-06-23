#include <stdio.h>
#include <string.h>


int main()
{
    int n, aux, mem;
    char c, lixo;
    printf("TESTADOR DE NUMEROS PALINDROMOS\n\nDeseja testar? (s/n) ");
    scanf("%c%c", &c, &lixo);
    while(c == 's' || c == 'S')
    {
        aux = 0;
        printf("Digite o numero: ");
        scanf("%d", &n);
        mem = n;
        while(n>0)
        {
            aux = aux*10 + (n % 10);
            n = n/10;
        }
        printf("\n\tO palindromo de %d eh % d\n\nDeseja testar? (s/n) ", mem, aux);
        fflush (stdin);
        scanf("%c%c", &c, &lixo);
    }
    system("pause");
    return 0;
}
