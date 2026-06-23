#include <stdio.h>
#include <stdlib.h>

int main(){
    int aluno,numalunos,numcadernos,numcanetas,numlapis,numborrachas;
    float precaderno,precaneta,prelapis,preborracha;

    printf("Digite o numero de alunos:");
    scanf("%d",&numalunos);
    printf("\n");
    aluno = 1;
    while(aluno<=numalunos){
        printf("Aluno %d: \n\n\tNumero de cadernos:",aluno); scanf("%d",&numcadernos);
        printf("\tPreco do caderno:"); scanf("%f", &precaderno);
        printf("\n\n");

        printf("\tNumero de canetas:"); scanf("%d",&numcanetas);
        printf("\tPreco da caneta:"); scanf("%f", &precaneta);
        printf("\n\n");


        printf("\tNumero de lapis:"); scanf("%d",&numlapis);
        printf("\tPreco do lapos:"); scanf("%f", &prelapis);
        printf("\n\n");


        printf("\tNumero de borracha:"); scanf("%d",&numborrachas);
        printf("\tPreco da borracha:"); scanf("%f", &preborracha);
        printf("\n\n");

        printf("\tAluno %d \n",aluno);
        printf("\t\t%d cadernos a R$%g cada\n",numcadernos,precaderno);
        printf("\t\t%d canetas a R$%g cada\n",numcanetas,precaneta);
        printf("\t\t%d lapis a R$%g cada\n",numlapis,prelapis);
        printf("\t\t%d borrachas a R$%g cada\n",numborrachas,preborracha);


        printf("\tGasto total:%g",numcadernos*precaderno + numcanetas*precaneta + numlapis*prelapis + numborrachas*preborracha);
        printf("\n\n");

        aluno=aluno+1;
        }
    printf("\n\n----------------FIM----------------\n\n\n"); system("pause"); return 0;
    }


