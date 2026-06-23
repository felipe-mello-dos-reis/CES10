#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE*ff;
    ff = fopen("txt","r");


    fclose (ff);

    system("pause");
    return 0;

}
