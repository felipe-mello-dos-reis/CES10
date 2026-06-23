#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n;
    float vet[100], media = 0, rmq = 0, s = 0;
    printf("Digite o tamanho da serie: ");
    scanf("%d", &n);
    printf("Digite os valores da serie: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%f", &vet[i]);
        media+=vet[i]/n;
        rmq+=(vet[i]*vet[i])/n;
    }
    for(int i = 0; i < n; i++)
        s+=((vet[i] - media)*(vet[i] - media))/n;
    rmq = sqrt(rmq);
    s = sqrt(s);
    //Resultado final
    printf("\nElemetos da serie: ");
    for(int i = 0; i < n; i++)
    printf("%8.3f", vet[i]);
    printf("\nMedia aritmetica: %.4f", media);
    printf("\nMedia quaratica:  %.4f", rmq);
    printf("\nDesvio padrao:    %.4f", s);
    printf("\n\n");
    system("pause");
    return 0;

}
