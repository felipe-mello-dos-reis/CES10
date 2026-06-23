#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Decclaracao dos tipos e ccnstantes logicas edo tipo cadeia

typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef char cadeia[50];

//Cabecalho e declaracoes locais

int main()
{
    int n, i; logic erro;
    cadeia cad;
    FILE *fin, *fout;

    //Abertura dos arquivos de entrada e de saida
    fin = fopen("textoin.dat", "r");
    fout = fopen ("textout.dat", "w");

    //Leitura de uma cadeia do arquivo de entrada e teste de fim de arquivo

    while(fscanf(fin, "%s", cad) == 1)
    {
        erro = FALSE;
        //Se o primeiro caractere da cadeia for letra, os outros tambem deve ser
        if(isalpha (cad[0]))
        {
            for(i, n = strlen(cad); i<n && !erro; i++)
                if(!isalpha (cad[i]))
                    erro = TRUE;
        }
        //Se o primeiro caarctere da ccadeia for digito, os outros tambem devem ser
        else if(isdigit(cad[0]))
        {
            for(i=1, n = strlen(cad);i<n && !erro;i++)
                if(!isdigit (cad[i])) erro = TRUE;
        }

        //Se o primeiro caractere da cadeia nao for letra nem digito: erro
        else erro = TRUE;

        //Se nao ha erro na cadeia, escreve-la no arquivo de saida
        if(! erro) fprintf(fout, "%s", cad);
    }
    printf("\n\n"); system("pause"); return 0;

    }



