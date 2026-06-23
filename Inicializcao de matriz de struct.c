struct complexo
{
    float real, imag;
};
typedef struct complexo complexo;
int main()
{
    int i, j;
    complexo A[3][3] =
    {
        {{1.0, -0.1},{2.0, -0.2},{3.0, 4.3}},
        {{4.0, -3.4},{5.0, 4.1},{6.0, -2.6}}
    };
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf ("(%5.1f) + i(%5.1f)   ", A[i][j].real, A[i][j].imag);
        printf ("\n");
    }
    printf("\n\n");
    system("pause");
    return 0;
}
