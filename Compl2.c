#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, j, A[50], estado, erro;
    char c, B[16][50];
    printf("Digite o numero de cadeias binarias a serem analisadas: ");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        erro = 0;
        printf("Digite a %da cadeia binaria de 16 caracteres: ", i+1);
        for(j=0;j<16;j++)
            {
                scanf("%c", &B[i][j]);
                if(B[i][j] != '1' && B[i][j] != '0')
                    erro = 1;
            }

            if(erro == 1)
            {
                printf("Cadeia invalida\n");
                i--;
            }
    }

    //Analise do compl2
    for(i=0;i<n;i++)
    {
        switch(B[i][0])
        {
        case '0':
            printf("%d  em binario: ", i+1);
            for(j=0;j<16;j++)
                {
                    B[i][j]=B[i][j+1];
                    printf("%c", B[i][j]);;
                }

        }
    }

    system("pause");
    return 0;
}

