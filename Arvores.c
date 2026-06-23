#include <stdio.h>
#include <stdlib.h>
/*
typedef char nome[16];
typedef struct noh noh;
typedef noh *lista;
typedef noh *posicao;
struct noh {
        nome elem; noh *prev, *prox;
};
*/
typedef struct celula celula;
typedef celula *noh;
typedef celula *arvore;
struct celula {char info; noh pai, fesq, idir;};
/*
noh n1, n2, n3;
arvore A1, A2, A3;
*/   
int main()
{
   arvore A; noh x, y;
   A = (noh) malloc (sizeof (celula));
   A->info = 'A'; A->pai = A->idir = NULL;
   A->fesq = (noh) malloc (sizeof (celula));
   x = A->fesq;
   x->info = 'B'; x->pai = A;
   x->fesq = (noh) malloc (sizeof (celula));
   x->idir = (noh) malloc (sizeof (celula));
   x->fesq->info = 'E';
   x->fesq->pai = x;
   x->fesq->fesq = x->fesq->idir = NULL;
   x = x->idir;
   x->info = 'C';
   x->pai = A;
   x->idir = NULL;
   x->fesq = (noh) malloc (sizeof (celula));
   y = x->fesq;
   y->info = 'F';
   y->pai = x;
   y->fesq = NULL;
   y->idir = (noh) malloc (sizeof (celula));
   y->idir->info = 'G';
   y->idir->pai = x;
   y->idir->fesq = y->idir->idir = NULL;

   return 0;
}
