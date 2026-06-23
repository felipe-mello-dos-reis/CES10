#include<stdio.h>
#include<stdlib.h>
#define max(x,y) ((x) >= (y))? (x) : (y)
#define media(x,y) (((x)+(y))/2)

int main()
{
    int n, i = 0;
    float aux, A[100], B[100], C[100], D[100];
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);
    printf("Digite o vetor A: ");
    for(i = 0; i < n; scanf("%f", &aux), A[i] = aux, i++);
    printf("Digite o vetor B: ");
    for(i = 0; i < n; scanf("%f", &aux), B[i] = aux, i++);
    for(i = 0; i < n; i++)
    {
        C[i] = max((A[i]),(B[i]));
        D[i] = media((A[i]),(B[i]));
    }
    for(i = 0, printf("\n\nVETOR A: "); i < n; printf("%5.2f", A[i]), i++);
    for(i = 0, printf("\n\nVETOR B: "); i < n; printf("%5.2f", B[i]), i++);
    for(i = 0, printf("\n\nVETOR C: "); i < n; printf("%5.2f", C[i]), i++);
    for(i = 0, printf("\n\nVETOR D: "); i < n; printf("%5.2f", D[i]), i++);
    printf("%\n\n");
    system("pause");
    return 0;
}
