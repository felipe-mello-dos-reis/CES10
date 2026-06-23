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
	printf("\n1o Encadeamento: ");
	EscreverEncadeamento(n1);
	printf("\nDigite o segundo numero seguido de <enter>: ");
	n2 = NovoEncadeamento();
	printf("\n2o Encadeamento: ");
	EscreverEncadeamento(n2);
	printf("\nSoma dos numero: ");
	soma = SomarEncadeamento(n1,n2);
	EscreverEncadeamento(soma);
	printf("\nMultiplicacao dos numeros: ");
	mult = MultiplicarEncadeamento(n1,n2);
	EscreverEncadeamento(mult);

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
		if(NumAux[1] == '\0')
			break;
		else
		{
			for(int i = 0; i < n; i++)
				NumAux[i] = NumAux[i+1];
			n--;
		}
	}
	L = (celula *) malloc (sizeof(celula));
	p = L;
	while(n > 0)
	{
		p->prox = (celula *) malloc (sizeof(celula));
		p = p->prox;
		for(i = max(n-4,0), j = 0; i <= n; i++, j++)
		{
			//Verificando a existencia de caracteres nao digitos
			if((NumAux[i] >= '0' && NumAux[i] <= '9') || NumAux[i] == '\0')
			{
				aux[j] = NumAux[i];
			}
			else
			{
				L->prox->num = -1;
				L->prox->prox = NULL;
				return L;
			}
		}
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
	char buffer[101];
	char* cadeia = buffer;
	for(q = p->prox; q != NULL; q = q->prox)
		len++;
	for(int i = 0; i < len; i++)
	{
		q = p->prox;
		for(int j = 1; j < len - i; j++)
		{
			q = q->prox;
		}
		if(q->prox == NULL)
			cadeia += sprintf(cadeia, "%d", q->num);
		else
			cadeia += sprintf(cadeia, "%.4d", q->num);
	}
	
	//Eliminando zeros a esquerda
	int n = strlen(buffer);
	buffer[n] = '\0';
	while(buffer[0] == '0')
	{
		if(buffer[1] == '\0')
			break;
		else
		{
			for(int i = 0; i < n; i++)
				buffer[i] = buffer[i+1];
			n--;
		}
	}

	printf("%s\n", buffer);
}

pont SomarEncadeamento(pont p1, pont p2)
{
	pont soma, L, q1 = p1->prox, q2 = p2->prox;
	int carry = 0;
	soma = (celula *) malloc(sizeof(celula));
	L = soma;
	//Verificando a existencai de numeros irregulares
	if(p1->prox->num == -1 || p2->prox->num == -1)
	{
		L->prox = (celula *) malloc(sizeof(celula));
		L->prox->num = -1;
		L->prox->prox = NULL;
		return L;
	}
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
	//Verificando a existencia de numeros irregulares
	if(p1->prox->num == -1 || p2->prox->num == -1)
	{
		L->prox->num = -1;
		L->prox->prox = NULL;
		return L;
	}
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
	return (a >= b)? a : b;
}
