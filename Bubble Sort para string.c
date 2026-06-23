#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Criacao do tipo logic e suas constantes

typedef char logic;
const logic false = 0, true = 1;

//Criacao do tipo nome

typedef char nome[15];

//Cabecalho e declaracoes locais

int main()
{
    int n, i, p; logic trocou;
    nome V[50], aux;
    //Leiturado vetor de nomes a ser ordenado
    printf("Ordenacao de nomes pelo Bubble-Sort\n\n");
    printf("\tNumero de nomes do vetor: "); scanf("%d", &n);
    printf("\n\tNomes: ");
    for(i = 0; i < n; i++) scanf("%s", V[i]);

    //Esccrita do vetor desordenado

    printf("\n\nVetor desordenado:\n");
    for(i=0;i<n;i++) printf("\n%s", V[i]);

    //Aplicacao do metodo bubble-sorte

    for(trocou = true, p = n-2; p>=0 && trocou == true; p--)
    {
        for(trocou = false, i = 0; i<= p;i++)
        if(strcmp(V[i],V[i+1])>0)
           {
               strcpy(aux,V[i]);
               strcpy(V[i],V[i+1]);
               strcpy(V[i+1],aux);
           }
    }

    //Escrita do vetor ordenado

    printf("\n\nVetor ordenado:\n");
    for(i=0;i<n;i++)printf("\n%s", V[i]);

    printf("\n\n");
    system("pause");
    return 0;

}
