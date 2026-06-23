#include <stdio.h>
#include <stdlib.h>

/* Cabecalho, declaracao de variaveis e leitura do numero de cadeias */

int main()  //  Inicio da funcao main
{
    int i, n, estado = 1;
    char c, lixo;
    printf("  AUTOMATO RECONHECEDOR DE CADEIAS BINARIAS\nCONTENDO SOMENTE DIGITOS 0's E 1's ALTERNADOS\n\n");
    printf ("\n\nNumero de cadeias a serem testadas: ");
    scanf ("%d%c", &n, &lixo);
    for (i = 1; i <= n; i++)
    {

        // Leitura da cadeia a ser analisada

        printf ("\n\nDigite a %da cadeia encerrada por <enter>: ", i);

        /* Percurso no automato usando os caracteres da cadeia */

        for (estado = 1, scanf ("%c", &c); c != '\n';
                scanf ("%c", &c))
        {
            switch(estado)      //Teste do caractere nos caminhos possiveis
            {
            case 1:
                switch(c)
                {
                case '1':
                    estado = 2;
                    break;
                case '0':
                    estado = 3;
                    break;
                default:
                    estado = 0;
                }
                break;
            case 2:
                switch(c)
                {
                case '0':
                    estado = 3;
                    break;
                default:
                    estado = 0;
                }
                break;
            case 3:
                switch(c)
                {
                case '1':
                    estado = 2;
                    break;
                default:
                    estado = 0;
                }
                break;
            case 0:     /*Estado Erro*/
                estado = 0;
                break;
            }
        }

        //Escrita do resultado do teste da cadeia

        if(estado == 2 || estado == 3)
            printf("\n\tCadeia aprovada!\n");
        else
            printf("\n\tCadeia reprovada!\n");
    }

    /*Encerramento da tela*/

    printf("\n\n");
    system("pause");
    return 0;
}       //Fim da funcao main e tambem fim do programa
