#include<stdio.h>
#include<stdlib.h>

int main()
{
    int A[50][50], m, n, par, j = 0;
    printf("Digite as dimensoes da matriz: ");
    scanf("%d %d", &m, &n);
    printf("A matriz ziguezage eh dada por:\n");
    for(int i = 0; i < m; i++)
    {
        par = (i) % 2;

        for(int cont = 1; cont <= n; cont++)
        {
            switch(par)
            {
            case 0:
                j++;
                printf("%4d", j);
                break;
            case 1:
                printf("%4d", j);
                j--;
                break;
            }
        }
        j = j + n;
        printf("\n");

    }
    system("pause");
    return 0;

}
