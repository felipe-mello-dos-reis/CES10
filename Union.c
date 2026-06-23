#include<stdio.h>
#include<stdlib.h>

//Declaracoes dos diversos tipos

typedef enum escolaridade escolaridade;
enum escolaridade {nenhuma, basica, media, superior};

typedef struct infozeroa3 infozeroa3;
struct infozeroa3
{
    int nmamads;
};

typedef struct info4a11 info4a11;
struct info4a11
{
    escolaridade esc;
    int nbrinq
};

typedef struct info12a17 info12a17;
struct info12a17
{
    escolaridade esc;
    int nlivros;
    char Passatempo[20];
};

typedef struct info18oumais info18oumais;
struct info18oumais
{
    escolaridade esc;
    char Profissao[20], Conjuge[30];
    char ehcasado;
    int nfilhos;
};

typedef union infoadicionais infoadicionais;
union infoadicionais
{
    infozeroa3 Info03;
    info4a11 Info411;
    info12a17 Info1217;
    info18oumais Info18;
};

typedef struct morador morador;
struct morador
{
    char Nome[30];
    int andar, nap, idade;
    infoadicionais InfoAdic;
};

typedef struct cadastro cadastro;
struct cadastro
{
    int nmor;
    morador Moradores[10]
};


/* Cabecalho e declaracoes das variaveis  */

int main ()
{
    cadastro Cad;
    int i;
    char c;

    /* Inicio da entrada de dados  */

    printf ("CADASTRO DE MORADORES DE UM PREDIO");
    printf ("\n\nNumero de moradores: ");
    scanf ("%d", &Cad.nmor);
    for (i = 0; i < Cad.nmor; i++)
    {

        /* Leitura das informacoes comuns a cada morador  */

        printf ("\n\nMorador n.o %d:", i+1);
        printf ("\n\tNome: ");
        setbuf (stdin, NULL);
        gets (Cad.Moradores[i].Nome);
        printf ("\tAndar: ");
        scanf ("%d", &Cad.Moradores[i].andar);
        printf ("\tApto: ");
        scanf ("%d", &Cad.Moradores[i].nap);
        printf ("\tIdade: ");
        scanf ("%d", &Cad.Moradores[i].idade);
        /* Leitura das informacoes dos moradores com idade de zero a 3 anos  */

        if (Cad.Moradores[i].idade >= 0 && Cad.Moradores[i].idade <= 3)
        {
            printf ("\tNumero de Mamadeiras: ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info03.nmamads);
        }

        /* Leitura das informacoes dos moradores com idade de 4 a 11 anos  */

        else if (Cad.Moradores[i].idade >= 4 && Cad.Moradores[i].idade <= 11)
        {
            printf ("\tEscolaridade ");
            printf ("(0 - Nenhuma, 1 - Basica, 2 - Media, 3 - Superior): ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info411.esc);
            printf ("\tNumero de Brinquedos: ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info411.nbrinq);
        }
        /* Leitura das informacoes dos moradores com idade de 12 a 17 anos  */

        else if (Cad.Moradores[i].idade>=12 && Cad.Moradores[i].idade<=17)
        {
            printf ("\tEscolaridade ");
            printf ("(0 - Nenhuma, 1 - Basica, 2 - Media, 3 - Superior): ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info1217.esc);
            printf ("\tNumero de Livros Lidos: ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info1217.nlivros);
            printf ("\tPassatempo Predileto: ");
            setbuf (stdin, NULL);
            gets (Cad.Moradores[i].InfoAdic.Info1217.Passatempo);
        }
        /* Leitura das informacoes dos moradores com idade de 18 anos ou mais  */

        else
        {
            printf ("\tEscolaridade ");
            printf ("(0 - Nenhuma, 1 - Basica, 2 - Media, 3 - Superior): ");
            scanf ("%d", &Cad.Moradores[i].InfoAdic.Info18.esc);
            printf ("\tProfissao: ");
            setbuf (stdin, NULL);
            gets (Cad.Moradores[i].InfoAdic.Info18.Profissao);
            printf ("\tEh casado? (s/n): ");
            c = Cad.Moradores[i].InfoAdic.Info18.ehcasado = getche ();
            if (c == 's' || c == 'S')
            {
                printf ("\n\tNome do conjuge: ");
                setbuf (stdin, NULL);
                gets (Cad.Moradores[i].InfoAdic.Info18.Conjuge);
                printf ("\tNumero de Filhos: ");
                scanf ("%d", &Cad.Moradores[i].InfoAdic.Info18.nfilhos);
            }
            else
                printf ("\n");
        }
    }
    /* Listagem das informacoes digitadas  */

    printf ("\nListagem dos Moradores:\n");
    for(i = 0; i < Cad.nmor; i++)
    {

        /* Informacoes comuns  */

        printf("\n%d) Nome: %-21s; Andar: %4d; Apto: %5d; Idade: %4d", i+1,
               Cad.Moradores[i].Nome, Cad.Moradores[i].andar, 			Cad.Moradores[i].nap, Cad.Moradores[i].idade);

        /* Moradores de zero a 3 anos  */

        if (Cad.Moradores[i].idade >= 0 && Cad.Moradores[i].idade <= 3)
        {
            printf ("\n\tMamadeiras: %d;", 							Cad.Moradores[i].InfoAdic.Info03.nmamads);
        }
        /* Moradores de 4 a 11 anos  */

        else if (Cad.Moradores[i].idade >= 4 && Cad.Moradores[i].idade <= 11)
        {
            printf ("\n\tEscolaridade: %d; Brinquedos: %d",
                    Cad.Moradores[i].InfoAdic.Info411.esc,
                    Cad.Moradores[i].InfoAdic.Info411.nbrinq);
        }

        /* Moradores de 12 a 17 anos  */

        else if (Cad.Moradores[i].idade>=12 && Cad.Moradores[i].idade<=17)
        {
            printf ("\n\tEscolaridade: %d; Livros: %d; Passatempo: %s",
                    Cad.Moradores[i].InfoAdic.Info1217.esc,
                    Cad.Moradores[i].InfoAdic.Info1217.nlivros,
                    Cad.Moradores[i].InfoAdic.Info1217.Passatempo);
        }
        /* Moradores de 18 anos ou mais  */

        else
        {
            printf ("\n\tEscolaridade %d; Profissao %s; Casado: %c;",
                    Cad.Moradores[i].InfoAdic.Info18.esc,
                    Cad.Moradores[i].InfoAdic.Info18.Profissao,
                    Cad.Moradores[i].InfoAdic.Info18.ehcasado);
            c = Cad.Moradores[i].InfoAdic.Info18.ehcasado;
            if (c == 's' || c == 'S')
            {
                printf ("\n\tConjuge: %s, Filhos: %d",
                        Cad.Moradores[i].InfoAdic.Info18.Conjuge,
                        Cad.Moradores[i].InfoAdic.Info18.nfilhos);
            }
        }
    }

    /* Fechamento da tela  */

    printf ("\n\n");
    system ("pause");
    return 0;
}

