#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef char cadeia[30];

//Declaracao da struct binario
typedef struct binario binario;
struct binario
{
    cadeia valbinario; int valdecimal; logic valido;
};

int main()
{
    binario bin; int i, n;
    printf("Digite um numero binario: ");
    scanf("%s", bin.valbinario);
    bin.valido = TRUE;
    n = strlen (bin.valbinario);

    //Verificacao da correcao do numero binario
    for(i=0;i<n &&bin.valido == TRUE; i++)
        if(bin.valbinario[i] != 48 && bin.valbinario[i] != 49)
            bin.valido = FALSE;
    if (bin.valido == TRUE)
    {
        for(i=0, bin.valdecimal = 0; i<n;i++)
            {bin.valdecimal = 2*bin.valdecimal + (bin.valbinario[i] - '0');
            printf("\n%c = %d - %d", bin.valbinario[i], bin.valbinario[i], '0');}
        printf("\n\t(%s)2 = (%d)10", bin.valbinario, bin.valdecimal);
    }
    else
        printf("\n\t%s nao representa um binario", bin.valbinario);
    printf("\n\n");
    system("pause");
    return 0;
}
