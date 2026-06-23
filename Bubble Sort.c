#include <stdio.h>
#include <stdlib.h>

/*	Criacao do tipo logic e suas constantes	*/

typedef char logic;
const logic false = 0, true = 1;

/*	Criacao do tipo vetor	*/

typedef int vetor[50];

/*	Cabecalho e declarações locais	*/

int main ()
{
    int n, i, p, aux;
    logic trocou;
    vetor V;
    /*	Leitura do vetor a ser ordenado	*/

    printf ("Ordenacao de numeros pelo Bubble-Sort\n\n");
    printf ("\tNumero de elementos: ");
    scanf ("%d",&n);
    printf ("\n\tElementos: ");
    for (i = 0; i < n; i++)
        scanf ("%d", &V[i]);

    /*	Escrita do vetor desordenado	*/

    printf ("\n\nVetor desordenado:\n\n");
    for (i = 0; i < n; i++)
        printf ("%4d", V[i]);

    /*	Aplicação do metodo bubble-sort	*/

    for (trocou = true, p = n-2; p >= 0 && trocou == true; p--)
        for (trocou = false, i = 0; i <= p; i++)
            if (V[i] > V[i+1])
            {
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                trocou = true;
            }

    /*	Escrita do vetor ordenado	*/

    printf ("\n\nVetor ordenado:\n\n");
    for (i = 0; i < n; i++)
        printf ("%4d", V[i]);
    /*	Fechamento da tela		*/

    printf ("\n\n");
    system ("pause");
    return 0;
}

