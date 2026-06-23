/*	Diretivas de preprocessamanto e declaracoes	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char logic;
const logic false = 0, true = 1;
typedef char nome[15];

int main ()
{
    int n, i, inf, sup, med;
    nome V[50], nome;
    logic achou, erro;
    char c;
    /*		Leitura dos elementos do vetor			*/

    printf ("PROCURA BINARIA EM VETORES DE NOMES\n\n");
    printf ("Numero de nomes do vetor: ");
    scanf ("%d", &n);
    printf ("\nNomes: ");
    for (i = 0; i < n; i++)
        scanf ("%s", V[i]);

    /*		Verificacao da ordenacao do vetor		*/

    for (i = 0, erro = false; i < n-1 && erro == false; i++)
        if (strcmp(V[i], V[i+1]) > 0)
            erro = true;
    if (erro == true)
        printf ("\n\tRelacao desordenada: nao havera procuras\n");
    /*		Secao de procuras				*/

    else
    {
        clrscr ();
        printf ("Secao de Procuras:\n\n");
        printf ("Procurar nome (s/n)?: ");
        do
            c = getche();
        while (c != 's' && c != 'n' && c != 's' && c != 'n');
        while (c == 's' || c == 'S')
        {
            printf ("\n\n\tNome: ");
            scanf ("%s", nome);
            /*		Procura de um numero no vetor				*/

            achou = false;
            inf = 0;
            sup = n - 1;
            do
            {
                med = (inf + sup) / 2;
                if (strcmp(nome, V[med]) == 0)
                    achou = true;
                else if (strcmp(nome, V[med]) < 0)
                    sup = med - 1;
                else
                    inf = med + 1;
            }
            while (!achou && inf <= sup);

            /*Emissao do resultado da procura */

                if (achou)
                    printf ("\n\t%s estah na posicao %d da relacao\n\n",
                            nome, med);
                else
                    printf ("\n\t%s nao estah na relacao\n\n",nome);
            printf ("Procurar outro numero (s/n)?: ");
            do
                c = getche();
            while (c != 's' && c != 'n' && c != 's' && c != 'n');
        }
    }

    /*	Fechamento da tela		*/

    printf ("\n\n");
    system ("pause");
    return 0;
}



