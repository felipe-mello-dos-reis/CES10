#include<stdio.h>
#include<stdlib.h>

//Definicao dos tipos

typedef int data[3];
typedef enum estcivil civil;
typedef struct endereco endereco;
typedef struct empregado empregado;

//Definicao do tipo enumerativo

enum estcivil {solt,cas,viuvo,desq,divorc};

//Definicao das estruturas

struct endereco
{
    char lograd[26], bairro[20];
    int numero;
};
struct empregado
{
    char nome[31];
    endereco ender;
    civil estciv;
    data nasc;
    int salario;
};

//Vetor com os nomes dos estados civis
char EstadoCivil[][12] = {"solteiro", "casado", "viuvo", "desquitado", "divorciado"};

int main()
{
    int i, n;
    char c;
    empregado Cadastro[10];
    FILE*filein;
    filein=fopen("Empregados.txt","r");

    //tamanho da estrutura empregados (curiosidade)
    printf("Tamanho da estrutura empregado: %d bytes", sizeof(empregado));

    //leitura do cadastro dos empregados
    fscanf(filein, "%d", &n); // Leitura do numero de emrpegados

    for(i=0;i<n;i++){
        fscanf(filein, "%c", &c); //eliminacao do enter do arquivo
        fgets(Cadastro[i].nome, 31, filein);
        fgets(Cadastro[i].ender.lograd, 26, filein);
        fscanf(filein, "%d", &Cadastro[i].ender.numero);
        fgets(Cadastro[i].ender.bairro, 21, filein);
        fscanf(filein, "%d", &Cadastro[i].estciv);
        fscanf(filein,"%d%d%d", &Cadastro[i].nasc[0], &Cadastro[i].nasc[1], &Cadastro[i].nasc[2]);
        fscanf(filein, "%d", &Cadastro[i].salario);
    }

    //Escrita do cadastro dos epregados
    printf("\n\n\nLiatagem dos empregados");
    for(i=0;i<n;i++)
    {
        printf("\n\n%d)\nNome: %s", i+1, Cadastro[i].nome);
        printf("\nEndereco: %s", Cadastro[i].ender.lograd);
        printf(", %7d", Cadastro[i].ender.numero);
        printf(", %s", Cadastro[i].ender.bairro);
        printf("\nEstado Civil: %s", EstadoCivil[Cadastro[i].estciv]);
        printf("\nData de Nascimento: %2.2d/%2.2d/%d", Cadastro[i].nasc[0], Cadastro[i].nasc[1], Cadastro[i].nasc[2]);
        printf("\nSalario: %d", Cadastro[i].salario);
    }

    printf("\n\n");
    system("pause");
    return 0;
}
