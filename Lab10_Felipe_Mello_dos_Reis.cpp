#include <stdio.h>
#include <stdlib.h>

// Definicoes e declaracoes iniciais

typedef struct matquadrada matquadrada;
struct matquadrada
{
	int n;
	double elem[10][10];
};

void LerMatQuadrada (matquadrada *);
void EscreverMatQuadrada (matquadrada *);
matquadrada MenorComplementar (matquadrada *, int a, int b);
double Det (matquadrada *, int n);
int somasub (int n);
int multi (int n);
int pot (int x, int n);

//Inicio da funcao main

int main()
{
	matquadrada A;
	LerMatQuadrada (&A);
	printf("Calculo de determinante com instrumentacao\n\n");
	EscreverMatQuadrada(&A);
	system("pause");
	return 0;
}

//Funcao para a leitura da matriz quadrada

void LerMatQuadrada (matquadrada *Mat)
{
	int i, j;
	char x;
	FILE *ff;
	Mat->n = 10;
	ff = fopen("input.txt", "r");
	for(i = 0; i < Mat->n; i++)
	{
		for(j = 0; j < Mat->n; j++)
			fscanf(ff,"%lf", &Mat->elem[i][j]);
		do
			fscanf(ff, "%c", &x);
		while (x != '\n');
	}
	fclose (ff);
}

//Funcao para a saida na tela

void EscreverMatQuadrada (matquadrada *Mat)
{
	for (int n = 1; n <= 10; ++n)
	{
		printf("Matriz com dimensao %d:\n", n);
		
		for (int i = 0; i < n; ++i)
		{
			printf("|");
			for (int j = 0; j < n; ++j)
				printf("%5.0lf", Mat->elem[i][j]);
			printf("|\n");
		}
		printf("Valor do determinante: %20.0lf\n\n", Det(Mat, n));
	}

	printf("Numeros de somas+subtracoes e multiplicacoes:\n\n");

	for (int n = 1; n <= 10; ++n)
		printf("Dimensao: %3d %12d somas+subtracoes %8d multiplicacoes\n", n, somasub(n), multi(n));

}

//Funcao  para  determinar o menor complementar de um elemento da matriz

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

//Funcao para o calculo do determinante
		
double Det (matquadrada *Mat, int n)
{
	matquadrada aux;
	int i;
	double det = 0;
	if(n>0)
		switch(n)
		{
			case 1:
				det = Mat->elem[0][0];
				return det;
				break;
			case 2:
				det = Mat->elem[0][0]*Mat->elem[1][1] - Mat->elem[1][0]*Mat->elem[0][1];
				return det;
				break;
			case 3:
				det = Mat->elem[0][0]*Mat->elem[1][1]*Mat->elem[2][2] + Mat->elem[0][1]*Mat->elem[1][2]*Mat->elem[2][0] + Mat->elem[0][2]*Mat->elem[1][0]*Mat->elem[2][1] - Mat->elem[0][1]*Mat->elem[1][0]*Mat->elem[2][2] - Mat->elem[0][0]*Mat->elem[1][2]*Mat->elem[2][1] - Mat->elem[0][2]*Mat->elem[1][1]*Mat->elem[2][0];
				return det;
				break;
			default:
				for(i=0;i<n;i++)
				{
					aux = MenorComplementar(Mat,0,i);
					det = det + pot(-1,i)*Mat->elem[0][i]*Det(&aux, n-1);
				}
				return det;
				break;
		}
	else
		return 99999;
}

//Funcao de recorrencia para a contagem das somas+subtracoes

int somasub (int n)
{
	int contador = n;
	if(n <= 0)
		return 99999;
	else
		switch (contador)
		{
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 5;
			break;
		default:
			contador = n*(somasub(n-1) +1);
			return contador;
			break;
		}
}

//Funcao de recorrencia para a contagem das multiplicacoes

int multi (int n)
{
	int contador = n;
	if(n <= 0)
		return 99999;
	else
		switch (n)
		{
		case 1:
			return 0;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 12;
			break;
		default:
			contador = n*(multi(n-1) +1);
			return contador;		
			break;
		}
}
		
//Funcao para o calculo de potencias

int pot (int x, int n)
{
        int p=1;
        if(n != 0)
                p = x * pot(x, n-1);
        return p;
}
