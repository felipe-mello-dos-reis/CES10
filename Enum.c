#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum diasemana diasemana;
enum diasemana {domingo, segunda, terca, quarta, quinta, sexta, sabado};
typedef char nome[10];

int main()
{
    diasemana hoje, ontem, amanha;
    char c;
    int achou;
    nome cadhoje, NomeDia[7] = {"domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"};

    printf("Deseja conhecer dia de ontem e de amanha? (s/n): ");
    scanf("%c", &c);

    while(c=='s' ||  c=='S')
    {
        printf("\n\tDigite o dia de hoje: ");
        scanf("%s", cadhoje);
        achou=0;

        hoje = domingo;
        while(hoje <= sabado && achou == 0)
        {
            if (strcmp (cadhoje, NomeDia[hoje]) == 0)
                achou = 1;
            else
                hoje++;
        }

        if(hoje > sabado)
            printf("\n\thoje: erro de digitacao\n\n");

        //Determicnacao dos dias de ontem e de amananha
        else
        {
            ontem = (hoje+6)%7;
            amanha = (hoje+1)%7;
            printf("\n\thoje = %s; ontem = %s; amanha = %s;\n\n", NomeDia[hoje], NomeDia[ontem], NomeDia[amanha]);
            //Desejo de nova execucao

            printf("Conhecer dia dde ontem e de amanha: (s/n) ");
            fflush(stdin);
            scanf("%c", &c);
        }
        printf("\n\n");
        system("pause");
        return 0;
    }

}
