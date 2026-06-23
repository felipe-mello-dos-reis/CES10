#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char logic;
const logic TRUE = 1, FALSE = 0;
typedef char cadeia[30];

//Declaracao da struct numero
typedef struct numero numero;
struct numero {
    cadeia valnabase;
    int valdecimal;
    logic valido;
};

int main() {
    numero num;
    int i, n, base;
    char lixo;
    printf("Digite a base: ");
    scanf("%d%c", &base, &lixo);
    num.valdecimal = 0;
    while (base < 1) {
        printf("\nBase invalida, digite novamente: ");
        scanf("%d%c", &base, &lixo);
    }
    printf("\nDigite um numero na base %d: ", base);
    scanf("%s", num.valnabase);
    num.valido = TRUE;
    n = strlen(num.valnabase);

    //Verificacao da correcao do numero binario
    if (base <= 10)
        for (i = 0; i < n && num.valido == TRUE; i++)
            if (num.valnabase[i] < 48 || num.valnabase[i] > 47 + base)
                num.valido = FALSE;

    if (base > 10)
        for (i = 0; i < n && num.valido == TRUE; i++)
            if (num.valnabase[i] < 48 || (num.valnabase[i] > 47 + base && num.valnabase[i] < 65) ||
                num.valnabase[i] > 65 + base - 10)
                num.valido = FALSE;

    if (num.valido == TRUE) {
        for (i = 0; i < n; i++)
            if (num.valnabase[i] >= 48 && num.valnabase[i] < 47 + base)
                num.valdecimal = base * num.valdecimal + (num.valnabase[i] - '0');

        for (i = 0; i < n; i++)
            if (num.valnabase[i] >= 65 && num.valnabase[i] <= 65 + base - 10)
                num.valdecimal = base * num.valdecimal + (num.valnabase[i] - 'A' + 10);

        printf("\n\t(%s)%d = (%d)10", num.valnabase, base, num.valdecimal);
    } else
        printf("\n\t(%s) nao representa um numero na base %d", num.valnabase, base);

    printf("\n\n");
    system("pause");
    return 0;
}
