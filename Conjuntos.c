#include <stdio.h>

typedef char logic;
const logic FALSE = 0, TRUE = 1;
typedef int vetor[40];
typedef struct conj conj;
struct conj
{
	vetor v;
	int n;
};
//void imprimir (conj);
conj universo =
{
	.n = 20,
	.v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
};
conj ordenar (conj *X)
{
	int i, p, temp; logic trocou;
    p = X->n-2; trocou = TRUE;
    while (p>=0 && trocou) {
        trocou = FALSE; i = 0;
        while (i <= p) {
            if (X->v[i] > X->v[i+1]) {
                temp = X->v[i]; X->v[i] = X->v[i+1];
                X->v[i+1] = temp; trocou = TRUE;
            }
            i = i+1;
        }
        p = p-1;
    }
	conj aux;
	aux.v[0] = X->v[0];
	aux.n = 1;
	for(i=0;i<X->n;i++)
	{
		for(p=0, trocou = TRUE;p < aux.n && trocou == TRUE; p++)
			if(X->v[i]  == aux.v[p])
				trocou = FALSE;
		if(trocou == TRUE)
		{
			aux.v[aux.n] = X->v[i];
			aux.n++;
		}
	}
	return aux;
}

conj inter (conj X, conj Y)
{
	conj aux;
	aux.n = 0;
	for(int i = 0; i < X.n; i++)
		for(int k = 0; k < Y.n; k++)
			if(X.v[i] == Y.v[k])
			{
				aux.v[aux.n] = X.v[i];
				aux.n++;
			}
	aux = ordenar(&aux);
	return aux;
}

conj uniao (conj X, conj Y)
{
	int i, j, k;
	conj aux;
	aux.n = X.n + Y.n;
    for (i = j = k = 0; i < X.n && j < Y.n; k++)
        if (X.v[i] < Y.v[j]) {
            aux.v[k] = X.v[i]; i++;
        }
        else {
            aux.v[k] = Y.v[j]; j++;
        }
    for (; i < X.n; i++, k++) aux.v[k] = X.v[i];
    for (; j < Y.n; j++, k++) aux.v[k] = Y.v[j];

	aux = ordenar(&aux);
	return aux;
}

conj complementar(conj X)
{
	logic novo = FALSE;
	int i, m;
	conj aux;
	aux.n = 0;
	for(i = 0; i < universo.n; i++)
	{
		for(m = 0, novo = FALSE; m < X.n && novo == FALSE; m++)
			if(universo.v[i] == X.v[m])
				novo = TRUE;
		if(novo == FALSE)
		{
			aux.v[aux.n] = universo.v[i];
			aux.n++;
		}
	}
	return aux;
}
void imprimir (conj X)
{
	printf("\nNumero de elementos: %d\n\t{", X.n);
	if(X.n == 0)
		printf("conjunto vazio}\n");
	else
	{
		for(int i = 0; i < X.n; i++)
			printf("%4d", X.v[i]);
		printf("}\n");
	}
}
int main ()
{
	conj A, B, C, D, E, F;
	printf("Digite o numero de elementos conjunto A: ");
	scanf("%d", &A.n);
	printf("Digite os elementos do conjunto A: ");
	for(int i = 0; i < A.n; i++)
		scanf("%d",  &A.v[i]);
	A = ordenar(&A);
	printf("Digite o numero de elementos conjunto B: ");
	scanf("%d", &B.n);
	printf("Digite os elementos do conjunto B: ");
	for(int i = 0; i < B.n; i++)
		scanf("%d",  &B.v[i]);
	B = ordenar(&B);
	printf("\nConjunto A ordenado: ");
	imprimir(A);
	printf("\nConjunto B ordenado: ");
	imprimir(B);
	printf("\nConjunto uniao:");
	C = uniao(A, B);
	imprimir(C);
	printf("\nConjunto interseccao: ");
	D = inter(A, B);
	imprimir(D);
	printf("\nConjunto complementar de A: ");
	E = complementar(A);
	imprimir(E);
	printf("\nConjunto complementar de B: ");
	F = complementar(B);
	imprimir(F);
	
	printf("\n\n");
	return 0;
}
