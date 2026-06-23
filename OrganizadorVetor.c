#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, vet[100], aux[100], repetido = 0, a = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    printf("Digite o vetor: ");
    for(i = 0; i < n; scanf("%d", &vet[i]), i++);
    for(i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(vet[i] = vet[j])
            {
                repetido++;
                for(a = j; a < n - repetido; a++)
                    vet[a] = vet[a+1];
            }

        }
    }
    printf("Vetor sem duplicatas: ");
    for(a = 0; a < n - repetido; a++)
        printf("%3d", vet[a]);
    printf("\n\n");
    system("pause");
    return 0;
}
