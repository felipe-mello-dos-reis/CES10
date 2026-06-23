#include<stdio.h>
#include<stdlib.h>

int main()
{
    int f1, f2, c1, c2, estado, cont = 0;
    printf("CALCULADORA DE FORTUNAS\n\n");
    printf("Digite o valor da 1a fortuna: ");
    scanf("%d", &f1);
    while(f1 < 0)
    {
        printf("A fortuna nao pode ser um numero negativo\n");
        printf("Digite o  valor da 1a fortuna: ");
        scanf("%d", &f1);
    }
    printf("Digite o valor da 2a fortuna: ");
    scanf("%d", &f2);
    while(f2 < 0)
    {
        printf("A fortuna nao pode ser um numero negativo\n");
        printf("Digite o  valor da 2a fortuna: ");
        scanf("%d", &f2);
    }
    printf("Digite o valor do 1o crescimento anual: ");
    scanf("%d", &c1);
    while(c1 < 0)
    {
        printf("O crescimento nao pode ser um numero negativo\n");
        printf("Digite o  valor do 1o crescimento anual: ");
        scanf("%d", &c1);
    }
    printf("Digite o valor do 2o crescimento anual: ");
    scanf("%d", &c2);
    while(c2 < 0)
    {
        printf("O crescimento nao pode ser um numero negativo\n");
        printf("Digite o  valor do 1o crescimento anual: ");
        scanf("%d", &c1);
    }
    if(f1 < f2)
    {
        printf("Menor fortuna = %d\n", f1);
        printf("Maior fortuna = %d\n", f2);
        estado = 1;
    }
    if(f2 < f1)
    {
        printf("Menor fortuna = %d\n", f2);
        printf("Maior fortuna = %d\n", f1);
        estado = 2;
    }
    if(f1 == f2)
    {
        printf("Menor fortuna = %d\n", f1);
        printf("Maior fortuna = %d\n", f1);
        estado = 3;
    }
    switch(estado)
    {
    case 1:
    {
        if(c1 <= c2)
            printf("A 1a fortuna  nunca ultrapassara o valor da 2a fortuna\n");
        else
        {
            while(f1 < f2)
            {
                f1 = f1 + c1;
                f2 = f2 + c2;
                cont++;
            }
            printf("A 1a fortuna ultrapassara a 2a fortuna em %d anos\n", cont);
        }

    }
    case 2:
    {
        if(c2 <= c1)
            printf("A 2a fortuna  nunca ultrapassara o valor da 1a fortuna\n");
        else
        {
            while(f2 < f1)
            {
                f1 = f1 + c1;
                f2 = f2 + c2;
                cont++;
            }
            printf("A 2a fortuna ultrapassara a 1a fortuna em %d anos\n", cont);
        }
    }
    case 3:   //Supondo que o crescimento seja adicionado apenas apos um ano
    {
        if(c1 > c2)
            printf("A 1a fortuna ultrapassara a 2a fortuna em 1 ano \n");
        if(c2 > c1)
            printf("A 2a fortuna ultrapassara a 1a fortuna em 1 ano \n");
        if(c1 == c2)
            printf("As fortunas sempre terao valores iguais entre si\n");
    }
    }
    printf("\n\n");
    system("pause");
    return 0;

}
