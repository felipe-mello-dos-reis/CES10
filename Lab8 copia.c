
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef char cadeia[30];

//Declaracao de structs
typedef struct numero numero;
typedef struct tabela tabela;
struct numero
{
    cadeia valnabase;
    int base, valdecimal;
    logic valido;
};
struct tabela
{
    numero VetNum[51];
    int ntab;
};

//Cabecalho e inicializacoes
int main()
{
    tabela TabNum;
    int i, j, n;
    FILE *filein;
    FILE *fileout;
    filein = fopen("StructInput.txt", "r");
    fileout = fopen("StructOutput.txt", "w");
    num.valdecimal = 0;

    //Endereco dos arquivos
    printf("Arquivo de entrada em StructInout.txt\nArquivo de saida em StructOutput.txt\n");

    //Leitura da cadeia
    fscanf(filein, "%d", &TabNum.ntab);
    for(j=0; j < TabNum.ntab; j++){
    fgets(TabNum.VetNum[j].valnabase, 13, filein);

    //Tamanho da cadeia
    n=-1;
    while(TabNum.VetNum[j].valnabase[i] != ' ')
        n++;
    scanf("%s", num.valnabase);
    num.valido = TRUE;
    n = strlen(num.valnabase);

    //Verificacao da correcao do numero binario
    if (num.base > 1 && num.base <= 10)
        for (i = 0; i < n && num.valido == TRUE; i++)
            if (num.valnabase[i] < 48 || num.valnabase[i] > 47 + num.base)
                num.valido = FALSE;

    if (num.base > 10 && num.base <= 20)
        for (i = 0; i < n && num.valido == TRUE; i++)
            if (num.valnabase[i] < 48 || (num.valnabase[i] > 57 && num.valnabase[i] < 65) || num.valnabase[i] > 65 + num.base - 10)
                num.valido = FALSE;

    if (num.base <= 1 || num.base >20)
        num.valido = FALSE;

    //Conversao para a base 10

    if (num.valido == TRUE)
    {
       //Para char de valor na base inteiro
        for (i = 0; i < n; i++)
            if (num.valnabase[i] >= 48 && num.valnabase[i] < 47 + base)
                num.valdecimal = num.base * num.valdecimal + (num.valnabase[i] - '0');

        //Para char de valor na basa char
        for (i = 0; i < n; i++)
            if (num.valnabase[i] >= 65 && num.valnabase[i] <= 65 + base - 10)
                num.valdecimal = num.base * num.valdecimal + (num.valnabase[i] - 'A' + 10);

        printf("\n\t(%s)%d = (%d)10", num.valnabase, num.base, num.valdecimal);
    }
    else
        printf("\n\t(%s) nao representa um numero na base %d", num.valnabase, num.base);
    }

    //Arquivo de saida
    fprintf(fileout, "CONVERSOES DE BASES PARA A BASE 10\n\n");
    fprintf(fileout, "Foram realizadas %d conversoes:\n", n);
    for(i=0;i<n;i++)
        fprintf(fileout, "\n(%s)%d = (%d)10", num.valnabase, num.base, num.valdecimal)

    printf("\n\n");
    system("pause");
    return 0;
}
