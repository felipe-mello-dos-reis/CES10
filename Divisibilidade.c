#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char testar;
    int dvdo, dvsor;
    printf ("DIVISIBILIDADE");
    printf ("\n\nTestar divisibilidade? (s/n): ");
    scanf ("%c", &testar);
    setbuf(stdin,NULL);
    while (testar == 's' || testar == 'S')
    {
        printf ("\n\tDigite o dividendo seguido do divisor e de <enter>: ");
        scanf ("%d%d", &dvdo, &dvsor);
        if(dvsor != 0)
        {
            if (dvdo % dvsor == 0)
                printf ("\n\t%d eh divisivel por %d", dvdo, dvsor);
            else
                printf ("\n\t%d nao eh divisivel por %d", dvdo, dvsor);
            printf ("\n\nTestar divisibilidade? (s/n): ");
            scanf ("%c", &testar);
            setbuf(stdin,NULL);
        }
        else
        {
            printf("ERRO! Nao eh possivel dividir por zero\n");
            printf ("\n\nTestar divisibilidade? (s/n): ");
            scanf ("%c", &testar);
            setbuf(stdin,NULL);
        }
    }
    printf ("\n\n");
    system ("pause");
    return 0;
}
