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
        switch (cor)
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
        for(col = 40, lin = 5; lin < 14; lin++  )
        {
            gotoxy(col,lin);
            printf("######");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 29, lin = 14; lin < 19; lin++)
        {
            gotoxy(col,lin);
            printf("############################");
            for(int j = 0; j <= demora; j++);
        }
        for(col = 40, lin = 19; lin < 35; lin++)
        {
            gotoxy(col,lin);
            printf("######");
            for(int j = 0; j <= demora; j++);
        }
        for(int j = 0; j <= demora*demora; j++);
        clrscr();
        gotoxy(1,1);
    }
    printf("\r                                       \rDigite algo para encerrar: ");
    getch();
    return 0;
}
