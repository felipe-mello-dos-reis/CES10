#include<stdio.h>
#include<stdlib.h>
#include<conio2.h>

int main()
{
    //Inicializacoes
    int lin, col, altura, j, demora = 20000000, k = 0;
    printf("Maxime a tele e digite algo: ");
    getch();

    //Fogo vermelho
    lin = 50;
    col = 35;
    altura = 25;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(RED);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora; i++);
    for(int i = 0; i < demora*demora; i++);

    //Fogo Azul Claro
    lin = 50;
    col = 15;
    altura = 30;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(LIGHTBLUE);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora*demora; i++);

    //Fogo verde
    lin = 50;
    col = 50;
    altura = 30;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(GREEN);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora*demora; i++);

    //Fogo Magenta
    lin = 50;
    col = 35;
    altura = 25;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(MAGENTA);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora*demora; i++);

    //Fogo Amarelo
    lin = 50;
    col = 55;
    altura = 40;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(YELLOW);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora*demora; i++);

    //Fogo Ciano
    lin = 50;
    col =35;
    altura = 20;
    clrscr();
    textcolor(WHITE);
    gotoxy(col,lin);
    printf("*");
    for(int i = 0; i < demora*demora; i++);
    gotoxy(col,lin);
    printf(" ");
    for(j = 1; j <= altura; j++)
    {
        gotoxy(col,lin-j);
        printf("^");
        gotoxy(col,lin-j+1);
        printf("|");
        gotoxy(col,lin-j+2);
        printf(" ");
        for(int i = 0; i < demora; i++);
    }
    textcolor(CYAN);
    gotoxy(col,lin-j);
    printf("*");
    gotoxy(col,lin-j+1);
    printf(" ");
    lin=lin-j;
    for(int i = 0; i < demora; i++);
    for(k = 0; k < 7; k++)
    {
        clrscr();
        gotoxy(col-k,lin);
        printf("*");
        gotoxy(col+k,lin);
        printf("*");
        gotoxy(col,lin-k);
        printf("*");
        gotoxy(col,lin+k);
        printf("*");
        gotoxy(col-k,lin+k);
        printf("*");
        gotoxy(col-k,lin-k);
        printf("*");
        gotoxy(col+k,lin-k);
        printf("*");
        gotoxy(col+k,lin+k);
        printf("*");
        for(int i = 0; i < demora; i++);
    }
    gotoxy(col-k-3,lin);
    printf("*");
    gotoxy(col+k+3,lin);
    printf("*");
    gotoxy(col,lin-k-1);
    printf("*");
    gotoxy(col,lin+k+1);
    printf("*");
    for(int i = 0; i < demora*demora; i++);

    //Escrito ita
    clrscr();

    for(int cor = 1; cor <= 7; cor++)
    {


        switch (cor) //escolha da cor
        {
        case 1:
            textcolor(WHITE);
            break;
        case 2:
            textcolor(BLUE);
            break;
        case 3:
            textcolor(GREEN);
            break;
        case 4:
            textcolor(YELLOW);
            break;
        case 5:
            textcolor(RED);
            break;
        case 6:
            textcolor(CYAN);
            break;
        case 7:
            textcolor(MAGENTA);
            break;
        }
        // Letra I
        for(col = 20, lin = 5; lin < 7; lin++  )
        {
            gotoxy(col,lin);
            printf("#######");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 22, lin = 7; lin < 14; lin++)
        {
            gotoxy(col,lin);
            printf("###");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 20, lin = 14; lin < 16; lin++)
        {
            gotoxy(col,lin);
            printf("#######");
            for(int j = 0; j <= demora; j++);
        }


        // Letra T
        for(col = 31, lin = 5; lin < 7; lin++  )
        {
            gotoxy(col,lin);
            printf("#########");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 34, lin = 7; lin < 16; lin++)
        {
            gotoxy(col,lin);
            printf("###");
            for(int j = 0; j <= demora; j++);
        }


        // Letra A
        for(col = 44, lin = 5; lin < 7; lin++  )
        {
            gotoxy(col,lin);
            printf("#######");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 44, lin = 7; lin < 10; lin++)
        {
            gotoxy(col,lin);
            printf("##   ##");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 44, lin = 10; lin < 12; lin++)
        {
            gotoxy(col,lin);
            printf("#######");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 44, lin = 12; lin < 16; lin++)
        {
            gotoxy(col,lin);
            printf("##   ##");
            for(int j = 0; j <= demora; j++);
        }

    }

    //Encerramento
    textcolor(WHITE);
    clrscr();
    printf("\n\n");
    system("pause");
    return 0;

}
