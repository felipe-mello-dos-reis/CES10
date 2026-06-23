#include<stdio.h>
#include<stdlib.h>

//Definicao dos tipos

typedef int QUEST[20];
typedef struct alternativa alternativa;
typedef struct aluno aluno;
//Definicao do tipo enumerativo



//Definicao das estruturas
/*
struct endereco
{
    char lograd[26], bairro[20];
    int numero;
};
*/
struct alternativa
{
    char resposta[2];
};
struct aluno
{
    char nome[31];
    alternativa quest[20];
    float nota;
    int posicao;
};

//Vetor com os nomes dos estados civis
char EstadoCivil[][12] = {"solteiro", "casado", "viuvo", "desquitado", "divorciado"};

int main()
{
    int i,j,n;
    char c, lixo;
    aluno Cadastro[10];
    aluno QUESTAO[20];
    FILE*filein;
    filein=fopen("Gabarito.txt","r");

    // Leitura do numero de emrpegados
    fscanf(filein, "%d", &n);
    fscanf(filein, "%c", &lixo);
    printf("Repostas:\n");
    //Leitura do gabarito
    for(i=0; i<20; i++)
    {
        fgets(QUESTAO[i].quest[i].resposta, 2, filein);
        printf("%2.2d. %s  ", i+1,  QUESTAO[i].quest[i].resposta);
        if(i == 9)
            printf("\n");
    }
    fscanf(filein, "%c", &lixo);

    printf("\n\n%-15s%-18s%-40s Nota  Estado", "Classificacao", "Nome","Respostas");
    //Leitura do cadastro
    for(j=0; j<n; j++)
    {
        fgets(Cadastro[j].nome, 16, filein);
        Cadastro[j].nota = 0;
        Cadastro[j].posicao = 1;
        for(i=0; i<20; i++)
        {
            fgets(Cadastro[j].quest[i].resposta, 2, filein);
            if(strcmp(Cadastro[j].quest[i].resposta, QUESTAO[i].quest[i].resposta) == 0)
                Cadastro[j].nota += 0.5;
        }
        fscanf(filein, "%c", &lixo);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(Cadastro[i].nota < Cadastro[j].nota)
                Cadastro[i].posicao++;
    for(j=0; j<n; j++)
    {
        printf("\n%-15d%s", Cadastro[j].posicao, Cadastro[j].nome);
        for(i=0; i<20; i++)
            printf("%s ", Cadastro[j].quest[i].resposta);
        printf("%5.1f", Cadastro[j].nota);
        if(Cadastro[j].nota >= 7)
            printf("\tAPROVADO");
        else
            printf("\tREPROVADO");
    }
    printf("\n\n");
    system("pause");
    return 0;
}
