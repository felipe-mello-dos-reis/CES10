#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, j, n, primo[100], vet[100], aux, p = 0, achou, igual = 0, mmc = 1;
    printf("Digite a quantidade de numeros a serem analisados: ");
    scanf("%d", &n);
    printf("Digite os numeros: ");
    for(i = 0; i < n; i++)
        scanf("%d", &vet[i]);
    while(igual != n)
    {
        for(i = 0, igual = 0; i < n; i++)
        {
            if(vet[i] == 1)
                igual++;
        }

        for(i = 0; i < n; i++)
            printf("%5d", vet[i]);

        //Determinação dos números primos

        i = 0;
        achou = 0;
        while(i < n && achou == 0)

        {
            aux = 2;
            while(aux <= vet[i] && achou == 0)
            {
                if(vet[i] % aux == 0)
                {
                    achou = 1;
                    primo[p] = aux;
                    p++;
                }
                else
                    aux++;
            }
            i++;
        }
        if(igual != n)
            printf("    |    %d\n", aux);
        else
            printf("    |\n\n");

        for(i = 0; i < n; i++)
        {
            if(vet[i] % aux == 0)
                vet[i] = vet[i]/aux;
        }
    }
    printf("\n\nMMC= ");
    for(i = 0; i < p; i++)
    {
        if(i != (p-1))
        printf(" %d *", primo[i]);
        else
            printf(" %d ", primo [i]);
        mmc *= primo[i];
    }
    printf(" = %d\n\n", mmc);
    system("pause");
    return 0;
}
