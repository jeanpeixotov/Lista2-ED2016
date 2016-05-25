#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DESLOC "   "
typedef struct arvoreA{
    int valor;
    struct arvoreA *esq;
    struct arvoreA *dir;
}TArvoreA;
typedef struct arvoreB{
    int valor;
    struct arvoreB *esq;
    struct arvoreB *dir;
}TArvoreB;
void inserirA(TArvoreA **pRaiz, int x){
    if(*pRaiz == NULL){
        *pRaiz = (TArvoreA *) malloc(sizeof(TArvoreA));
        (*pRaiz)->esq = NULL;
        (*pRaiz)->dir = NULL;
        (*pRaiz)->valor = x;
    }else{
        if(x < (*pRaiz)->valor)
            inserirA(&(*pRaiz)->esq, x);
        if(x > (*pRaiz)->valor)
            inserirA(&(*pRaiz)->dir, x);
    }
}
void inserirB(TArvoreB **pRaiz, int y){
    if(*pRaiz == NULL){
        *pRaiz = (TArvoreB *) malloc(sizeof(TArvoreB));
        (*pRaiz)->esq = NULL;
        (*pRaiz)->dir = NULL;
        (*pRaiz)->valor = y;
    }else{
        if(y < (*pRaiz)->valor)
            inserirB(&(*pRaiz)->esq, y);
        if(y > (*pRaiz)->valor)
            inserirB(&(*pRaiz)->dir, y);
    }
}
 void ImprimeArvoreA(TArvoreA *RaizA){
     if(RaizA==NULL)
      return;
     printf(" %d",RaizA->valor);
     ImprimeArvoreA(RaizA->esq);
     ImprimeArvoreA( RaizA->dir);
 }
 void ImprimeArvoreB(TArvoreB *RaizB){
     if(RaizB==NULL)
      return;
     printf(" %d",RaizB->valor);
     ImprimeArvoreB(RaizB->esq);
     ImprimeArvoreB( RaizB->dir);
 }
int contaNoA(TArvoreA *RaizA)
{   if(RaizA == NULL)
   		return 0;
   	else
   		return 1+contaNoA(RaizA->dir)+contaNoA(RaizA->esq);
 }
int contaNoB(TArvoreB *RaizB)
{ if(RaizB == NULL)
   		return 0;
   	else
   		return 1+contaNoB(RaizB->dir)+contaNoB(RaizB->esq);
 }
int espelho(TArvoreA* RaizA,TArvoreB* RaizB){
  if(RaizA==NULL || RaizB==NULL)
      return 0;
  else if(RaizA->valor==RaizB->valor){
      espelho(RaizA->esq,RaizB->esq);
      espelho(RaizA->dir,RaizB->dir);
      return 1;
 }
  else
      return 0;
 }

int main(){
    int x=0,y=0;
    TArvoreA *RaizA =NULL;
		TArvoreB *RaizB =NULL;
    while(1){
			printf("Informe o numero: ");
			scanf(" %d",&x);
			if(x == -999)
				break;
      inserirA(&RaizA,x);
    };
		while(1){
			printf("Informe o numero: ");
			scanf(" %d",&y);
			if(y == -999)
				break;
			inserirB(&RaizB,y);
		};

    if(RaizA==NULL && RaizB==NULL)
      printf("\nAmbas arvores estão vazias\n");
    x=espelho(RaizA,RaizB);
    if(x==1 && (contaNoA(RaizA)==contaNoB(RaizB)))
      printf("\nAs arvores são completamente iguais\n");
    else
        printf("\nAs arvores não são iguais\n");

    printf("\nArvore em ordem:\n");
    ImprimeArvoreA(RaizA);
    printf("\n\n");
		ImprimeArvoreB(RaizB);
		printf("\n\n");
    return 0;
}
