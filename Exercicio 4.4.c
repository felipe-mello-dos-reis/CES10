#include <stdio.h>
int main ()
{
    long a, b, c, d, e, f, g;
    scanf("%d", &a);
    b = 0;
    g = 0;

    f = a / 10;
    e = a;
    c=0;
    d=0;
    while(d<10)
    {

        c=c+b;
        d=d+1;

        for (c=0, d=0; d<10; d=d+1, e=e-f)
        {
            c = c + b;
        }
        b = e + c;
        a = f;
        g = g + e;
        printf("%d\t%d\n", e, g);
        while (a != 0)
        {
            f = a / 10;
            e = a;
            for (c=0, d=0; d<10; d=d+1, e=e-f)
            {
                c = c + b;
            }
            b = e + c;
            a = f;
            g = g + e;
            printf("%d\t%d\n", e, g);
        }
    }
    printf("%d\n", b);
    printf ("\n\n");
    system ("pause");
    return 0;
}
