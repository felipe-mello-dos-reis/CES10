#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef char cadeia[30];

//Declaracao da struct numero
typedef struct numero numero;
struct numero
{
    cadeia valnabase;
    int valdecimal;
    logic valido;
};

int main()
{
    numero num;
    int i, n, base;
    char lixo;
    printf("Digite a base: ");
    scanf("%d%c", &base, &lixo);
    while(base < 1)
    {
        printf("\nBase invalida, digite novamente: ");
        scanf("%d%c", &base, &lixo);
    }
    printf("\nDigite um numero na base %d: ", base);
    scanf("%s", num.valnabase);
    num.valido = TRUE;
    n = strlen (num.valnabase);

    //Verificacao da correcao do numero binario
    if(base<=10)
        for(i=0; i < n && num.valido == TRUE; i++)
            if(num.valnabase[i] < 48 || num.valnabase[i] > 47 + base)
                num.valido = FALSE;

   /* if(base > 10)
        for(i=0; i < n && num.valido == TRUE; i++)
            if(num.valnabase[i] < 48  num.valnabase[i] > 47 + base)
                num.valido = FALSE;
    */
    if (num.valido == TRUE)
    {
        if(num.valnabase[i] <= 48 && num.valnabase[i] < 48 + base)
            for(i=0, num.valdecimal = 0; i<n; i++)
            {
                num.valdecimal = base*num.valdecimal + (num.valnabase[i] - '0');
                printf("\n%c = %d - %d", num.valnabase[i], num.valnabase[i], '0');
            }
        if(num.valnabase[i] >= 65 && num.valnabase[i] <= 65 + base - 10)
            for(i=0, num.valdecimal = 0; i<n; i++)
            {
                num.valdecimal = base*num.valdecimal + (num.valnabase[i] - 'A' + 10);
                printf("\n%c = %d - %d + 10", num.valnabase[i], num.valnabase[i], 'A');
            }
        printf("\n\t(%s)%d = (%d)10", num.valnabase, base, num.valdecimal);

    }
    else
        printf("\n\t(%s) nao representa um numero na base %d", num.valnabase, base);

    printf("\n\n");
    system("pause");
    return 0;
}
