#include<stdio.h>
#include<stdlib.h>

const int TRUE = 1;
const int FALSE = 0;
int primo(int p)
{
    int resposta = TRUE;
    for(int div = 2; div <= p/2; div++)
        if(p % div == 0)
            resposta = FALSE;
    return resposta;
}
int main()
{
    int LimInf, LimSup, n, achou, i;
    printf("Digite o intervalo inferior e o superior: ");
    scanf("%d%d", &LimInf, &LimSup);
    if(LimInf % 2 == 0)
        n = LimInf;
    else
        n = LimInf + 1;
    printf("\nNo intervalo de [%5d,%5d], todo par eh a soma de dois primos:\n", LimInf, LimSup);
    while(n <= LimSup)
    {
        achou = FALSE;
        for(i = 2; i < n && achou == FALSE; i++)
        {
            if(primo(i) == TRUE)
                if(primo(n-i) == TRUE)
                {
                    printf("\n%5d = %5d + %5d", n, i, n-i);
                    achou = TRUE;
                }
        }
        n = n + 2;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
