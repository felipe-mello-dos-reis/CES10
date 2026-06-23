/*    Declaracoes globais      */

#include <stdio.h>
#include <stdlib.h>
typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef int vetor[20];

/*    Prototipos das funcoes auxiliares    */

void LerVetor (vetor, int*);
void EscreverVetor (vetor, int);
void BubbleSort (vetor, int);
void MergeSort (vetor, vetor, vetor, int, int, int*);
int main () {
    int m, n, p;
    vetor V1, V2, V3;
      printf ("FUSAO DE DOIS VETORES ORDENADOS");

/*    Leitura dos dois vetores    */

    printf ("\n\nLeitura do vetor V1: \n");
      LerVetor (V1, &m);
    printf ("\nLeitura do vetor V2: \n");
      LerVetor (V2, &n);

/*    Escrita dos dois vetores lidos    */

      printf ("\n\nVetor V1 inicial: \n\n");
    EscreverVetor (V1, m);
      printf ("\n\nVetor V2 inicial: \n\n");
    EscreverVetor (V2, n);
/*    Ordenacao e escrita dos dois vetores ordenados  */

    BubbleSort (V1, m);
    BubbleSort (V2, n);
      printf ("\n\nVetor V1 ordenado: \n\n");
    EscreverVetor (V1, m);
      printf ("\n\nVetor V2 ordenado: \n\n");
    EscreverVetor (V2, n);

/*    Fusao dos dois vetores num terceiro */

    MergeSort (V1, V2, V3, m, n, &p);
/*    Escrita do vetor resultado da fusao      */

      printf ("\n\nFusao V3 dos vetores V1 e V2:\n\n");
    EscreverVetor (V3, p);

/*    Fechamento da tela      */

    printf ("\n\n");  return 0;
}
/*    Funcao LerVetor para ler os elementos de um vetor  */

void LerVetor (vetor V, int *n) {
      int i;
    printf ("\n\tNumero de elementos: ");
    scanf ("%d", n);
    printf ("\n\tSeus %d elementos: ", *n);
    for (i = 0; i <= *n-1; i++)
        scanf ("%d", &V[i]);
}

/*    Funcao EscreverVetor para escrever os elementos de um vetor  */

void EscreverVetor (vetor V, int n) {
    int i;
    for (i = 0; i <= n-1; i++)
        printf ("%4d", V[i]);
}
/*    Funcao BubbleSort para ordenar os elementos de um vetor   */

void BubbleSort (vetor V, int n) {
    int i, p, aux; logic trocou;
    p = n-2; trocou = TRUE;
    while (p>=0 && trocou) {
        trocou = FALSE; i = 0;
        while (i <= p) {
            if (V[i] > V[i+1]) {
                aux = V[i]; V[i] = V[i+1];
                V[i+1] = aux; trocou = TRUE;
            }
            i = i+1;
        }
        p = p-1;
    }
}
/*    Funcao MergeSort para fundir dois vetores
    ordenados num terceiro tambem ordenado            */

void MergeSort (vetor V1, vetor V2, vetor V3, int m, 
    int n, int *p) {
    int i, j, k;
      *p = m + n;
    for (i = j = k = 0; i < m && j < n; k++)
        if (V1[i] < V2[j]) {
            V3[k] = V1[i]; i++;
        }
        else {
            V3[k] = V2[j]; j++;
        }
    for (; i < m; i++, k++) V3[k] = V1[i];
    for (; j < n; j++, k++) V3[k] = V2[j];
}
