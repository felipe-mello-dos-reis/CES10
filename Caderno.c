#include <stdio.h>
#include <stdlib.h>

int main(){
    int aluno,numalunos,numcadernos;
    float preco;
    printf("Digite o numero de alunos:");
    scanf("%d",&numalunos);
    printf("\n");
    aluno=1;
    while(aluno<numalunos+1){
        printf("Aluno %d: \n\n\tPreco do caderno:",aluno);
        scanf("%f",&preco);
        printf("\tNumero de cadernos:"); scanf("%d",&numcadernos);
        printf("\tAluno %d: %d cadernos a R$%g cada; gasto total: RS%g\n\n", aluno,numcadernos,preco,numcadernos*preco);
        aluno++;
        }
    printf("\n\n"); system("pause"); return 0;
}
