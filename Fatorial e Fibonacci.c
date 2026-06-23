#include<stdio.h>
#include<stdlib.h>

int main()
{
        /*
    int  fatorial[20], termo[100];
    termo[0] = 0, termo[1] = 1;
    fatorial[1] = 1;
    for(int i = 2; i < 100; i++)
    {
        termo[i] = termo[i-1] + termo[i-2];
    }
    for(int i = 1; i <= fatorial; i++)
    {
        fatorial[i] = i * fatorial[i-1];
    }
    */


    int fatorial = 1, termoA = 0, termoB = 1;
    printf("Fatorial:\n");
    for(int i = 1; i < 8; i++) //este teto é defino pelo teto da variável int
    {
        fatorial = fatorial * i;
        printf("%d\n", fatorial);
    }
    printf("\n\nFibonacci:\n");
    for(int i = 1; i < 13; i++)
    {
        printf("%d\n%d\n", termoA, termoB);
        termoA = termoA + termoB;
        termoB = termoA + termoB;

    }
    system("pause");
    return 0;
}
