#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Declarações sobre um time e sobre uma tabela de times */

typedef char cadeia[31];
typedef struct time time;
struct time
{
    cadeia nome;
    int pontos, vitorias, golspro, golscontra, saldogols;
};

typedef struct tabelatimes tabelatimes;
struct tabelatimes
{
    time VetorTimes[30];
    int ntimes;
};

/* Variaveis globais */

tabelatimes TabTimes;
FILE *filein, *fileout;

/* Prototipos das funcoes auxiliares */

void InicializarArquivos (void);
void LerArmazenarTimes (void);
void EscreverTimes (void);
void LerArmazenarJogos (void);
void EscreverJogos (void);
void PreencherTabTimes(void);
void EscreverTabTimes (void);


/* Funcao main: Abre e inicializa os arquivos de entrada e saida,
	le os times, armazenando-os, e escreve o conteudo da tabela de times */

//Montagem de uma atriz ocm os resultados dos jogos do campeonato

typedef struct resultado resultado;
struct resultado
{
    int local, visitante;
};
resultado Jogos[30][30];

int main ()
{
    InicializarArquivos ();
    LerArmazenarTimes ();
    EscreverTimes ();
    LerArmazenarJogos ();
    EscreverJogos ();
    PreencherTabTimes ();
    EscreverTabTimes ();
    printf ("\n\n");
    system ("pause");
    return 0;
}
/* Funcao InicializarArquivos: escreve avisos no video, abre os
    arquivos de entrada e saida e escreve titulo no arquivo de
    saida */

void InicializarArquivos ()
{
    printf ("RESULTADOS DE UM CAMPEONATO\n\n");
    printf ("Entrada de dados no arquivo CampeonatoInput.txt\n\n");
    printf ("Relatorio dos Resultados no arquivo CampeonatoOutput.txt\n\n");
    filein = fopen ("CampeonatoInput.txt", "r");
    fileout = fopen ("CampeonatoOutput.txt", "w");
    fprintf (fileout,
             "R E S U L T A D O S   D E   U M   C A M P E O N A T O\n\n");
}
/* Funcao LerArmazenarTimes: le os times do campeonato e
    os armazena na tabela de times, inicializando os dados
    sobre eles */

void LerArmazenarTimes ()
{
    int i, len;
    char lixo;
    fscanf (filein, "%d%c", &TabTimes.ntimes, &lixo);
    for (i = 0; i <= TabTimes.ntimes-1; i++)
    {
        fgets (TabTimes.VetorTimes[i].nome, 25, filein);
        len = strlen(TabTimes.VetorTimes[i].nome);
        TabTimes.VetorTimes[i].nome[len-1] = '\0';
        TabTimes.VetorTimes[i].pontos =
            TabTimes.VetorTimes[i].vitorias =
                TabTimes.VetorTimes[i].golspro =
                    TabTimes.VetorTimes[i].golscontra =
                        TabTimes.VetorTimes[i].saldogols = 0;
    }
}
// Funcao EscreverTimes

void EscreverTimes()
{
    int i;
    fprintf(fileout, "Listagem dos times:\n\n%22s", "Time\n");
    fprintf(fileout, "----------------------\n");
    for(i=0; i < TabTimes.ntimes; i++)
        fprintf(fileout, "%22s\n", TabTimes.VetorTimes[i].nome);

}

// Funcao LerArmazenarJogos

void LerArmazenarJogos ()
{
    int i, j;
    for(i=0; i < TabTimes.ntimes; i++)
        for(j=0; j < TabTimes.ntimes; j++)
            if(i != j)
                fscanf(filein, "%d%d", &Jogos[i][j].local, &Jogos[i][j].visitante);
}

// Funcao EscreverJogos

void EscreverJogos ()
{
    int i, j;
    fprintf(fileout, "\n\nResultado dos jogos:\n\n                      ");
    for(i=0; i < TabTimes.ntimes; i++)
        fprintf(fileout, "%7.3s ", TabTimes.VetorTimes[i].nome);
    for(i=0; i < TabTimes.ntimes; i++)
    {
        fprintf(fileout, "\n%22s", TabTimes.VetorTimes[i].nome);
        for(j=0; j < TabTimes.ntimes; j++)
            if(i != j)
                fprintf(fileout, "   %d x %d", Jogos[i][j].local, Jogos[i][j].visitante);
            else
                fprintf(fileout, "   #####");
    }
}

// Funcao PreencherTabTimes

void PreencherTabTimes ()
{
    int i, j;
    for(i=  0; i < TabTimes.ntimes; i++)

        if(i != j)
            for(j = 0; j < TabTimes.ntimes; j++)
            {
                if(Jogos[i][j].local > Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].pontos += 3;
                    TabTimes.VetorTimes[i].vitorias++;
                }
                if(Jogos[i][j].local < Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[j].pontos += 3;
                    TabTimes.VetorTimes[j].vitorias++;
                }
                if(Jogos[i][j].local == Jogos[i][j].visitante)
                {
                    TabTimes.VetorTimes[i].pontos++;
                    TabTimes.VetorTimes[j].pontos++;
                }
                TabTimes.VetorTimes[i].golspro += Jogos[i][j].local;
                TabTimes.VetorTimes[i].golscontra += Jogos[i][j].visitante;
                TabTimes.VetorTimes[i].saldogols = TabTimes.VetorTimes[i].golspro - TabTimes.VetorTimes[i].golscontra;
                TabTimes.VetorTimes[j].golspro += Jogos[i][j].visitante;
                TabTimes.VetorTimes[j].golscontra += Jogos[i][j].local;
                TabTimes.VetorTimes[j].saldogols = TabTimes.VetorTimes[j].golspro - TabTimes.VetorTimes[j].golscontra;

            }
}


/* Funcao EscreverTabTimes: escreve todo o conteudo
    da tabela de times */

void EscreverTabTimes ()
{
    int i;
    fprintf (fileout, "\n\nTabela de desempenho dos times:\n\n");

    /* Cabecalho da tabela */

    fprintf (fileout, "%22s | %9s | %9s | %9s | %9s | %9s\n",
             "Time", "Pontos", "Vitorias", "G Pro", "G Contra",
             "Saldo G");
    fprintf (fileout, "----------------------------------------------------------------------------------\n");

    /* Escrita das informacoes sobre os times */

    for (i = 0; i <= TabTimes.ntimes-1; i++)
        fprintf (fileout, "%22s | %9d | %9d | %9d | %9d | %9d\n",
                 TabTimes.VetorTimes[i].nome,
                 TabTimes.VetorTimes[i].pontos,
                 TabTimes.VetorTimes[i].vitorias,
                 TabTimes.VetorTimes[i].golspro,
                 TabTimes.VetorTimes[i].golscontra,
                 TabTimes.VetorTimes[i].saldogols);
}
