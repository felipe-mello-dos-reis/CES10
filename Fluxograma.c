#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, somaimp, quoc,dig;
    printf("Soma dos digitos impares:\n\n");
    printf("Digite um numero positivo:\n");
    scanf("%d", &num);
    while(num >= 0)
    {
        somaimp = 0;
        quoc = num;
        while(quoc > 0)
        {
            dig = quoc % 10;
            if(dig % 2 != 0) //se sig é impar
                somaimp = somaimp + dig;
            quoc = quoc/10;
        }
        printf("A soma dos digitos impares de %d eh: %d\n", num, somaimp);
        printf("Digite um numero positivo:\n");
        scanf("%d", &num);
    }
    system("pause");
    return 0;
}
