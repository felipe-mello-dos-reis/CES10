#include <stdio.h>
#include <stdlib.h>

typedef struct matquadrada matquadrada;
struct matquadrada
{
	int n;
	float elem[10][10];
};

void LerMatQuadrada (matquadrada *);
void EscreverMatQuadrada (matquadrada *);
matquadrada MenorComplementar (matquadrada *, int a, int b);
int Det (matquadrada *, int n);
int somasub = 0;
int mult = 0;


int pot (int x, int n)
{
        int p=1;
        if(n != 0)
                p = x * pot(x, n-1);
        return p;
}

int main()
{
	matquadrada A, B;
	int i, j;
	LerMatQuadrada (&A);
	printf("\nMatriz A: \n\n");
	EscreverMatQuadrada (&A);
	printf("\nMatriz Menor Complementar (i, j) de A:\n\n");
	printf("Digite i e j: ");
	scanf("%d%d", &i, &j);
	printf("\nMatriz B: \n\n");
	B = MenorComplementar (&A, i, j);
	EscreverMatQuadrada (&B);
	printf("\nCalculo do determinante de A:\n Det(A) = %d", Det(&A, A.n));
	printf("\n\n");
	return 0;
}

void LerMatQuadrada (matquadrada *Mat)
{
	int i, j;
	char x;
	FILE *ff;
	ff = fopen("input.txt", "r");
	printf("Digite a dimensao n da matriz (1 <= n <= 10): ");
	scanf("%d", &Mat->n); //Mat-> equivale a (*Mat).n
	for(i = 0; i < Mat->n; i++)
	{
		for(j = 0; j < Mat->n; j++)
			fscanf(ff,"%f", &Mat->elem[i][j]);
		do
			fscanf(ff, "%c", &x);
		while (x != '\n');
	}
}

void EscreverMatQuadrada (matquadrada *Mat)
{
	int i, j;
	for(i = 0; i < Mat->n; i++)
	{
		printf("|");
		for(j = 0; j < Mat->n; j++)
			printf("%5.0f", Mat->elem[i][j]);
		printf(" |\n");
	}
}

matquadrada MenorComplementar (matquadrada *Mat, int a, int b)
{
	matquadrada B;
	B.n = Mat->n -1;
	int i, j;
	for(i=0;i< Mat->n - 1;i++)
	{
		for(j=0;j<Mat->n - 1;j++)
		{
			if(i>=a && j>=b)
				B.elem[i][j] = Mat->elem[i+1][j+1];
			else
				if(i>=a && j <b)
			 		B.elem[i][j] = Mat->elem[i+1][j];
				else
					if(i<a && j>=b)
						B.elem[i][j] = Mat->elem[i][j+1];
					else
						B.elem[i][j] = Mat->elem[i][j];
		}
	}
	return B;
}
			
int Det (matquadrada *Mat, int n)
{
	matquadrada aux;
	int i, det = 0;
	if(n>0)
		switch(n)
		{
			case 1:
				det = Mat->elem[0][0];
				return det;
				break;
			case 2:
				det = Mat->elem[0][0]*Mat->elem[1][1] - Mat->elem[1][0]*Mat->elem[0][1];
				somasub+=1;
				mult+=2;
				return det;
				break;
			case 3:
				det = Mat->elem[0][0]*Mat->elem[1][1]*Mat->elem[2][2] + Mat->elem[0][1]*Mat->elem[1][2]*Mat->elem[2][0] + Mat->elem[0][2]*Mat->elem[1][0]*Mat->elem[2][1] - Mat->elem[0][1]*Mat->elem[1][0]*Mat->elem[2][2] - Mat->elem[0][0]*Mat->elem[1][2]*Mat->elem[2][1] - Mat->elem[0][2]*Mat->elem[1][1]*Mat->elem[2][0];
				somasub+=5;
				mult+=12;
				return det;
				break;
			default:
				for(i=0;i<n;i++)
				{
					aux = MenorComplementar(Mat,0,i);
					det = det + pot(-1,i)*Mat->elem[0][i]*Det(&aux, n-1);
					somasub+=1;
					mult+=3;
				}
				return det;
				break;
		}
	else
		return 99999;
}
