#include<stdio.h>
#include<conio.h>
#include<conio2.h>

int main()
{
    int col, lin, i, cor, demora =  20000000;
    char c, lixo;
    printf("Maxime a tela e digite algo: ");
    getche(); clrscr();
    printf("Deseja exibir animcao? (s/n) ");
    for(c = getche(); c == 's' || c == 'S'; textcolor(WHITE), printf("Deseja exibir animacao? (s/n)"), c = getche())
    {
        clrscr();
        printf("Escolha a cor da animacao: \n\tVERMELHO = 1\n\tAZUL =     2;\n\tVERDE =    3;\n\tAMARELO =  4;\n\tBRANCO =   5;");
        gotoxy(28,1);
        scanf("%d", &cor);
        for(gotoxy(1,7); cor < 1 || cor > 5; scanf("%d%c", &cor, &lixo))
            printf("\nOpcao invalida, digite novamente: ");
        clrscr();
        switch (cor) //escolha da cor
        {
        case 1:
            textcolor(RED); break;
        case 2:
            textcolor(BLUE); break;
        case 3:
            textcolor(GREEN); break;
        case 4:
            textcolor(YELLOW); break;
        case 5:
            textcolor(WHITE); break;
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


        for(int j = 0; j <= demora*demora; j++);
        for(int j = 0; j <= demora*demora; j++); // tempo de espera para a visualizacao
        clrscr();
        gotoxy(1,1);
    }
    printf("\r                                       \rDigite algo para encerrar: ");
    getch();
    return 0;
}

