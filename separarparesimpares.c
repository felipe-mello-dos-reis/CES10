#include <stdio.h>
#include <stdlib.h>

typedef struct noh noh;
typedef noh *lista;
typedef noh *posicao;
struct noh {
    int elem;
    noh *prox;
};
void SepararParesImpares (lista, lista, lista);
int main () {
    lista L, ListPar, ListImpar;
//    - - - - -
      SepararParesImpares (L, ListPar, ListImpar);
//    - - - - -
}
void SepararParesImpares (lista L, lista L1, lista L2) {
    posicao p, q;
      p = L1; q = L2;
      while (L->prox != NULL) {
       if (L->prox->elem % 2 == 0) {
          p->prox = L->prox;
            p = p->prox;
      }
      else {
          q->prox = L->prox;
             q = q->prox;
      }
      L->prox = L->prox->prox;
      }
      p->prox = q->prox = NULL;
}

