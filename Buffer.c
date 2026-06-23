#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char let;
    float x;
    printf("Digite um inteiro: ");
    scanf("%d", &n);
    printf("Digite uma letra: ");
    scanf("%c", &let);
    printf("Digite um real: ");
    scanf("%f", &x);

    /*
    scanf("%c", &let) = getchar()
    soluções
    1) limpar o buffer biblioteca <stdio.h>
    fflush (stdin);
    2) executar mais um getchar() para tirar o <enter>
    3) colocar um espaço em branco  dentro do scanf que ignoraa os espaços e <enter>
    scanf(" %c", &let)
    */
    getchar();
    return 0;

}
