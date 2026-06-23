#include<stdio.h>
#include<conio.h>
#include<conio2.h>

int main()
{
    int col, lin;
    char c, peca;
    printf("\rDeseja analisar o tabuleiro? (s/n) ");
    for(c = getche(), clrscr(); c == 's' || c == 'S'; gotoxy(11,21), printf("Deseja analisar o tabuleiro? (s/n) "), c = getche(), clrscr())
    {
        printf("\rEscolha uma peca:                  \n\tRAINHA = R;\n\tTORRE  = T;\n\tBISPO  = B;\n\tCAVALO = C;");
        gotoxy(19,1);
        for(peca = getche(); peca != 'R' && peca != 'T' && peca != 'B' && peca != 'C' && peca != 'r' && peca != 't' && peca != 'b' && peca != 'c'; gotoxy(1,7), printf("\nEntrada invalida, digite novamente: "), peca = getche());
        clrscr();
        printf("Digite a linha: ");
        scanf("%d", &lin);
        printf("Digite a coluna: ");
        scanf("%d", &col);
        col+=10;
        lin+=10;
        //construção do tabuleiro
        gotoxy(11,11);
        printf(" ABCDEFGH");
        for(int i = 1; i <= 8; gotoxy(11,11+i), textcolor(RED), printf("%d--------\n", i),i++, textcolor(GREEN));
        switch(peca)
        {
        case 't':
            peca = 'T';
        case 'T':
        {
            for(int i = 12; i <= 19; i++)
            {
                gotoxy(col+1,i);
                printf("*");

            }
            for(int j = 12; j <= 19; j++)
            {
                gotoxy(j,lin+1);
                printf("*");

            }
            textcolor(WHITE);
            gotoxy(col+1,lin+1);
            printf("T");
            break;
        }
        case 'b':
            peca = 'B';
        case 'B':
        {
            for(int i = 0; i <= 7; i++)
            {

                gotoxy(col+1+i,lin+1+i);
                printf("*");
                gotoxy(col+1-i,lin+1+i);
                printf("*");
                gotoxy(col+1-i,lin+1-i);
                printf("*");
                gotoxy(col+1+i,lin+1-i);
                printf("*");


                /** //Outra maneira de executar
                    int  x, y, z, w;
                    x = col +1 +i;
                    y = col +1 -i;
                    z = lin +1 +i;
                    w = lin +1 -i;

                    gotoxy(x,z); printf("*");
                    gotoxy(y,z); printf("*");
                    gotoxy(x,w); printf("*");
                    gotoxy(y,w); printf("*");
                **/

            }
            textcolor(WHITE);
            gotoxy(col+1,lin+1);
            printf("B");
            break;
        }
        case 'c':
            peca = 'C';
        case 'C':
        {
            gotoxy(col+3,lin+2);
            printf("*");
            gotoxy(col+3,lin);
            printf("*");
            gotoxy(col-1,lin+2);
            printf("*");
            gotoxy(col-1,lin);
            printf("*");
            gotoxy(col+2,lin+3);
            printf("*");
            gotoxy(col,lin+3);
            printf("*");
            gotoxy(col+2,lin-1);
            printf("*");
            gotoxy(col,lin-1);
            printf("*");
            textcolor(WHITE);
            gotoxy(col+1,lin+1);
            printf("C");
            break;
        }
        case 'r':
            peca = 'R';
        case 'R':
        {
            for(int i = 12; i <= 19; i++)
            {
                gotoxy(col+1,i);
                printf("*");

            }
            for(int j = 12; j <= 19; j++)
            {
                gotoxy(j,lin+1);
                printf("*");

            }
            for(int i = 0; i <= 7; i++)
            {
                gotoxy(col+1+i,lin+1+i);
                printf("*");
                gotoxy(col+1-i,lin+1+i);
                printf("*");
                gotoxy(col+1-i,lin+1-i);
                printf("*");
                gotoxy(col+1+i,lin+1-i);
                printf("*");
            }
            textcolor(WHITE);
            gotoxy(col+1,lin+1);
            printf("R");
        }

        }
        //construção das maergens
        gotoxy(1,11);
        printf("           ABCDEFGH               ");
        for(int i = 1; i <= 8; i++)
        {
            gotoxy(1,11+i);
            printf("          %d", i);
        }
        for(int i = 1; i <= 15; i++)
        {
            gotoxy(20,11+i);
            printf("                   ");
        }
        for(int i = 20; i <= 30; i++)
        {
            gotoxy(1,i);
            printf("                                                 ");
        }
        for(int i = 1; i < 9; i++)
        {
            gotoxy(1,2+i);
            printf("                               ");
        }
        gotoxy(1,4);
        printf("%c-%d-%d", peca, lin-10, col-10);
    }
    return 0;
}


