#include <stdio.h>
#include <stdlib.h>

typedef char nome[16];
typedef struct noh noh;
typedef noh *lista;
typedef noh *posicao;
struct noh
{
	int elem;
	noh *prev, *prox;
};

// Invertendo a cadeia;
void inverter (noh* sentinela)
{
	lista reserva;
	for(int i = 0; i < 10; i++)
	{
		reserva = sentinela->prox;
		sentinela->prox = sentinela->prev;
		sentinela->prev = reserva;
		sentinela = reserva;
	}
}		
int main ()
{
	noh ficha;
	lista celula, sentinela, reserva;
	celula = &ficha;
	celula->prox = (noh *) malloc(sizeof(noh));
	sentinela = celula;
	for(int i = 1; i <= 10; i++)
	{
		celula->prox = (noh *) malloc(sizeof(noh));
		celula->elem = i;
		reserva = celula;
		if(i == 10)
			celula->prox = sentinela;
		celula = celula->prox;
		celula->prev = reserva;
	}
	printf("INDO\n");
	for(int i = 1; i <= 20; i++)
	{
		printf("Celula %d\n", celula->elem);
		celula = celula->prox;
	}
	celula = celula->prev;
	printf("\n\nVOLTANDO\n");
	for(int i = 1; i <= 20; i++)
	{
		printf("Celula %d\n", celula->elem);
		celula = celula->prev;
	}
	printf("\n\n");
	inverter(celula);
	printf("\n\nINVERTIDA\n");
	for(int i = 1; i <= 20; i++)
	{
		printf("Celula %d\n", celula->elem);
		celula = celula->prox;
	}

	//Testando se realmente inverteu
	printf("\nTestando a inverção:\n");
	for(int i = 1; i <= 10; i++)
	{
		printf("cel = %2d, sent = %2d ", celula->elem, sentinela->elem);
		if(sentinela->prev->elem == celula->elem)
			printf("--- Celula %2d: TRUE\n", i);
		else
			printf("--- Celula %2d: FALSE\n", i);
		sentinela = sentinela->prev;
		celula = celula->prox;
	}
	return 0;
}
