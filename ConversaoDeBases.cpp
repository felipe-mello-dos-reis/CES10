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
    int i, j, n, soma = 0;
    char lixo;
    FILE *filein;
    FILE *fileout;
    filein = fopen("input.txt", "r");
    fileout = fopen("output.txt", "w");

    //Endereco dos arquivos
    printf("Arquivo de entrada em input.txt\nArquivo de saida em output.txt\n");

    //Leitura do tamanho da tabela
    fscanf(filein, "%d", &TabNum.ntab);
    fscanf(filein, "%c", &lixo);

    //Conteudo incial dao arquivo de saida
    fprintf(fileout, "CONVERSOES DE BASES PARA A BASE 10\n\n");
    fprintf(fileout, "Foram realizadas %d conversoes:\n", TabNum.ntab);

    for(j=0; j < TabNum.ntab; j++)
    {
        //Leitura da cadeia
        fscanf(filein, "%s", TabNum.VetNum[j].valnabase);
        fscanf(filein, "%d", &TabNum.VetNum[j].base);
        fscanf(filein, "%c", &lixo);

        //Tamanho da cadeia
        n = strlen(TabNum.VetNum[j].valnabase);
        TabNum.VetNum[j].valido = TRUE;

        //Verificacao da correcao do numero binario
        if (TabNum.VetNum[j].base > 1 && TabNum.VetNum[j].base <= 10)
            for (i = 0; i < n && TabNum.VetNum[j].valido == TRUE; i++)
                if (TabNum.VetNum[j].valnabase[i] < 48 || TabNum.VetNum[j].valnabase[i] > 47 + TabNum.VetNum[j].base)
                    TabNum.VetNum[j].valido = FALSE;

        if (TabNum.VetNum[j].base > 10 && TabNum.VetNum[j].base <= 20)
            for (i = 0; i < n && TabNum.VetNum[j].valido == TRUE; i++)
                if (TabNum.VetNum[j].valnabase[i] < 48 || (TabNum.VetNum[j].valnabase[i] > 57 && TabNum.VetNum[j].valnabase[i] < 65) || TabNum.VetNum[j].valnabase[i] >= 65 + TabNum.VetNum[j].base - 10)
                    TabNum.VetNum[j].valido = FALSE;

        if (TabNum.VetNum[j].base <= 1 || TabNum.VetNum[j].base > 20)
            TabNum.VetNum[j].valido = FALSE;

        //Conversao para a base 10

        TabNum.VetNum[j].valdecimal = 0;

        if (TabNum.VetNum[j].valido == TRUE)
        {
            //A cadeia ja foi considerada valida, entao nao teremos problema com o intervalo do char
            for (i = 0; i < n; i++)
            {
                if (TabNum.VetNum[j].valnabase[i] >= 48 && TabNum.VetNum[j].valnabase[i] < 58)
                    TabNum.VetNum[j].valdecimal = TabNum.VetNum[j].base * TabNum.VetNum[j].valdecimal + (TabNum.VetNum[j].valnabase[i] - '0');
                if (TabNum.VetNum[j].valnabase[i] >= 65 && TabNum.VetNum[j].valnabase[i] <= 65 + TabNum.VetNum[j].base - 10)
                    TabNum.VetNum[j].valdecimal = TabNum.VetNum[j].base * TabNum.VetNum[j].valdecimal + (TabNum.VetNum[j].valnabase[i] - 'A' + 10);
            }
            fprintf(fileout, "\n(%s)%d = (%d)10", TabNum.VetNum[j].valnabase, TabNum.VetNum[j].base, TabNum.VetNum[j].valdecimal);

        //Calculo da soma dos numeros validos
        soma += TabNum.VetNum[j].valdecimal;
        }
        else
            fprintf(fileout, "\n(%s)%d = Dados incompativeis", TabNum.VetNum[j].valnabase, TabNum.VetNum[j].base);
    }

    fprintf(fileout,"\n\nSomatoria dos numeros validos = (%d)10", soma);

    //Encerramentos
    fclose(filein);
    fclose(fileout);
    printf("\n\n");
    system("pause");
    return 0;
}
