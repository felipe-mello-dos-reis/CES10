#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, num, maior = -32768, menor =  32767, soma3ou7 = 0, cont = 0, soma = 0, somapares = 0, fatorial = 1, termoA = 0, termoB = 1, i = 0, f = 1, m = 0;
    //maior e menor definidos pelos limites do tipo int

    printf("\nDigite um inteiro positivo: ");
    scanf("%d", &n);
    while(n <= 0)
    {
        printf("\nERRO! Numero inserido invalido! Favor inserir um inteiro positivo: ");
        scanf("%d", &n);
    }
    while(i < n)
    {
        printf("\nDigite um inteiro: ");
        scanf("%d", &num);
        soma = soma + num;
        cont = cont + 1;
        if(num % 2 == 0)
        {
            somapares = somapares + num;
        }
        if(num > 0 && (num % 3 == 0 || num % 7 == 0))
        {
            soma3ou7 = soma3ou7 + num;
        }
        if(num > maior)
        {
            maior = num;
        }
        if(num < menor)
        {
            menor = num;
        }

        while(f <= 8) //este teto é definido pelo teto da variável int
        {
            fatorial = fatorial * f;
            if(num == fatorial)
            {
                printf("\n\t%d eh o fatorial de %d\n", num, f);
            }
            f = f + 1;
        }
        while(m < 13) //este teto é definido pelo teto da variável int
        {
            if(num == termoA || num == termoB)
            {
                printf("\n\t%d eh um termo da sequencia de Fibonacci\n", num);
            }
            termoA = termoA + termoB;
            termoB = termoA + termoB;
            m = m + 1;
        }
        //restaurando as variáveis
        fatorial = 1;
        termoA = 0;
        termoB = 1;
        f = 1;
        m = 0;
        printf("\n");
        i = i + 1;
    }
    float floatsoma = soma;        //novo tipo de variavel para exibir corretamente o valor da media
    float floatcont = cont;
    float media = floatsoma / floatcont;
    printf("A media aritmetrica dos inteiros lidos eh: %.4f\n", media);
    printf("A soma dos inteiros pares lidos eh: %d\n", somapares);
    printf("A soma dos inteiros positivos multiplos de 3 ou 7 lidos eh: %d\n", soma3ou7);
    printf("O maior numero lido eh: %d\n", maior);
    printf("O menor numero lido eh: %d\n\n\n", menor);

    system("pause");
    return 0;

}
