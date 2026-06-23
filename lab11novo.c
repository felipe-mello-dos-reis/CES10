#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definicoes iniciais
typedef struct celula celula;
typedef celula *pont;
struct celula
{
	int num;
	pont prox;
};

//Inicializacao das funcoes

pont NovoEncadeamento (void);
void EscreverEncadeamento (pont);
pont SomarEncadeamento (pont, pont);
pont MultiplicarEncadeamento (pont, pont);
int max (int, int);

//Chamada da funcao main

int main ()
{
	//Declaracao de variaveis
	pont n1, n2, soma, mult;
	printf("Digite o primeiro numero seguido de <enter>: ");
	n1 = NovoEncadeamento();
	EscreverEncadeamento (n1);
	printf("Digite o segundo numero seguido de <enter>: ");
	n2 = NovoEncadeamento();
	EscreverEncadeamento (n2);
	printf("Soma dos numero: ");
	soma = SomarEncadeamento(n1,n2);
	EscreverEncadeamento(soma);
	printf("Multiplicacao dos numeros: ");
	mult = MultiplicarEncadeamento(n1,n2);
	EscreverEncadeamento(mult);
	//Encerramento
	printf("\n\n");
	return 0;
}

pont NovoEncadeamento (void)
{
	char aux[101], NumAux[101];
	pont p, L;
	scanf("%s", NumAux);
	int n, j, i;
	n = strlen(NumAux);
	NumAux[n] = '\0';
	
	//Eliminando zeros a esquerda

	while(NumAux[0] == '0')
	{
		for(int i = 0; i < n; i++)
			NumAux[i] = NumAux[i+1];
		n--;
	}
	L = (celula *) malloc (sizeof(celula));
	p = L;
	while(n > 0)
	{
		p->prox = (celula *) malloc (sizeof(celula));
		p = p->prox;
		for(i = max(n-4,0), j = 0; i <= n; i++, j++)
			aux[j] = NumAux[i];
		p->num = atoi (aux);
		n = n-4;
		if(n>=0)
			NumAux[n] = '\0';
	}
	p->prox = NULL;
	return L;
}

void EscreverEncadeamento (pont p)
{
	int len = 0;
	pont q;
	printf("\nEncadeamento: ");
	for(q = p->prox; q != NULL; q = q->prox)
	{
		printf("%04d.", q->num);
		len++;
	}
	printf("\nBig num: ");
	for(int i = 0; i < len; i++)
	{
		q = p->prox;
		for(int j = 1; j < len - i; j++)
		{
			q = q->prox;
		}
		if(q->prox == NULL)
			printf("%4d.", q->num);
		else
			printf("%04d.", q->num);
	}
	printf("\n\n");
}

pont SomarEncadeamento(pont p1, pont p2)
{
	pont soma, L, q1 = p1->prox, q2 = p2->prox;
	int carry = 0;
	soma = (celula *) malloc(sizeof(celula));
	L = soma;
	while(q1 != NULL || q2 != NULL || carry == 1)
	{
		soma->prox = (celula *) malloc(sizeof(celula));
		soma = soma->prox;
		soma->num = carry;
		if(q1 != NULL)
		{
			soma->num += q1->num;
			q1 = q1->prox;
		}
		if(q2 != NULL)
		{
			soma->num += q2->num;
			q2 = q2->prox;
		}
		if(soma->num >= 10000)
		{
			carry = 1;
			soma->num -= 10000;
		}
		else
			carry = 0;
	}
	soma->prox = NULL;
	return L;
}

pont MultiplicarEncadeamento(pont p1, pont p2)
{
	pont L, q1, q2;
	int contador = 0, carry = 0;
	L = (celula *) malloc(sizeof(celula));
	L->prox = (celula *) malloc(sizeof(celula));
	L->prox->num = 0;
	L->prox->prox = NULL;
	pont aux, SentinelaAux;
	aux = (celula *) malloc(sizeof(celula));
	SentinelaAux = aux;
	for(q1 = p1->prox; q1 != NULL || carry > 0; contador++, q1 = q1->prox)
	{
		aux = SentinelaAux;
		for(int i = 0; i < contador; i++)
		{
			aux->prox = (celula *) malloc(sizeof(celula));
			aux = aux->prox;
			aux->num = 0;
		}
		carry = 0;
		for(q2 = p2->prox; q2 != NULL || carry > 0;)
		{
			aux->prox = (celula *) malloc(sizeof(celula));
			aux = aux->prox;
			aux->num = carry;
			if(q2 != NULL)
			{
				aux->num += (q1->num * q2->num);
				q2 = q2->prox;
			}
			carry = aux->num / 10000;
			aux->num = aux->num % 10000;
		}
		aux->prox = NULL;
		L = SomarEncadeamento(L, SentinelaAux);
	}
	return L;
}


int max(int a, int b)
{
	int A;
	A = (a >= b)? a : b;
	return A;
}
