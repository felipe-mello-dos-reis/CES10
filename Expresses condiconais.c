#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x=25, y=20, z=14;
    int min, max;
    min = (x<y)?((x<z)?x:z):((y<z)?y:z);
    max = (x>y)?((x>z)?x:z):((y>z)?y:z);
    printf("min = %d\nmax = %d\n\n", min, max);
    system("pause");
    return 0;

}
