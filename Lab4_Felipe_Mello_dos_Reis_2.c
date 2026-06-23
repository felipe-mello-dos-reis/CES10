#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, i, a, b, ma, mb, mmc;
    printf("MMC ENTRE VARIOS PARES DE NUMEROS\n\n");
    printf("Digite quantos pares de numeros: ");
    scanf("%d", &n);
    i = 1;
    while(i <= n)
    {
        printf("Digite o par %d: ", i);
        scanf(" %d %d", &a, &b);
        printf("MMC (%d,%d) = ", a, b);
        if(a == 0 || b == 0)
            mmc = 0;
        else
        {
            a = fabs(a);
            b = fabs(b);
            ma = a;
            mb = b;
            while(ma != mb)
            {
                if(ma < mb)
                    ma = ma + a;
                else
                    mb = mb + b;
            }
            mmc = ma;

        }
        printf("%d\n\n", mmc);
        i= i + 1;
    }
    system("pause");
    return 0;

}
