#include <stdio.h>
#include <stdlib.h>

typedef char nome[16];
typedef struct noh noh;
typedef noh *lista;
typedef noh *posicao;
struct noh
{
	int elem;
	noh /**prev,*/ *prox;
};

int main ()
{
	lista celula,  sentinela;
	sentinela = celula;
	for(int i = 1; i < 10; i++)
	{
		celula->prox = (noh *) malloc(sizeof(noh));
		celula->elem = i;
		celula = celula->prox;
	}
	celula->prox = (noh *) malloc(sizeof(noh));
	celula->elem = 10;
	celula->prox = sentinela;
	for(int i = 0; i <= 10; i++)
	{
		printf("Celula %d\n", celula->elem);
		celula = celula->prox;
	}
	return 0;
}
