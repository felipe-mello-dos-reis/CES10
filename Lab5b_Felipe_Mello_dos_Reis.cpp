#include <stdio.h>
#include <stdlib.h>

/* Cabecalho, declaracao de variaveis e leitura do numero de cadeias */

int main()  //  Inicio da funcao main
{
    int i, n, estado = 1;
    char c, lixo;
    printf("AUTOMATO RECONHECEDOR DE CONSTANTE NUMERICAS EM C\n\n");
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
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 3;
                    break;
                case '+':
                case '-':
                    estado = 2;
                    break;
                case '.':
                    estado = 4;
                    break;
                default:
                    estado = 9;
                }
                break;

            case 2:
                switch(c)
                {
                case '.':
                    estado = 4;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 3;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 3:
                switch(c)
                {
                case 'E':
                case 'e':
                    estado = 6;
                    break;
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 3;
                    break;
                case '.':
                    estado = 5;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 5:
                switch(c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 5;
                    break;
                case 'E':
                case 'e':
                    estado = 6;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 6:
                switch(c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 8;
                    break;
                case '+':
                case '-':
                    estado = 7;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 7:
                switch(c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 8;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 8:
                switch(c)
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    estado = 8;
                    break;
                default:
                    estado = 9;
                }
                break;
            case 9:     /*Estado ERRO*/
                estado = 9;
                break;
            }
        }

        //Escrita do resultado do teste da cadeia

        if(estado == 3 || estado == 5 || estado == 8)
            printf("\n\tCadeia aprovada!\n");
        else
            printf("\n\tCadeia reprovada!\n");
    }

    /*Encerramento da tela*/

    printf("\n\n");
    system("pause");
    return 0;
}       //Fim da funcao main e tambem fim do programa
