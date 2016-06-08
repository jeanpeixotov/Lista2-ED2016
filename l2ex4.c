/*
	Autores:    Felipe Luiz Soares 0030481511012
		    			Jean Vitor  0030481511019

	Exercício 4 da lista 2.
*/
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

 void ImprimeArvoreA(TArvoreA *RaizA){
     if(RaizA==NULL)
      return;
     printf(" %d",RaizA->valor);
     ImprimeArvoreA(RaizA->esq);
     ImprimeArvoreA( RaizA->dir);
 }

 TArvoreA *MaiorDireita(TArvoreA **no){
    if((*no)->dir != NULL)
       return MaiorDireita(&(*no)->dir);
    else{
       TArvoreA *aux = *no;
       if((*no)->esq != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esq;
       else
          *no = NULL;
       return aux;
       }
}
void remover(TArvoreA **pRaiz, int valor){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       return;
    }
    if(valor < (*pRaiz)->valor)
       remover(&(*pRaiz)->esq, valor);
    else
       if(valor > (*pRaiz)->valor)
          remover(&(*pRaiz)->dir, valor);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          TArvoreA *pAux = *pRaiz;
          if (((*pRaiz)->esq == NULL) && ((*pRaiz)->dir == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL;
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esq == NULL){
                (*pRaiz) = (*pRaiz)->dir;
                pAux->dir = NULL;
                free(pAux); pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->dir == NULL){
                    (*pRaiz) = (*pRaiz)->esq;
                    pAux->esq = NULL;
                    free(pAux);
                    pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito do filho esq
                   pAux = MaiorDireita(&(*pRaiz)->esq);
                   pAux->esq = (*pRaiz)->esq;
                   pAux->dir = (*pRaiz)->dir;
                   (*pRaiz)->esq = (*pRaiz)->dir = NULL;
                   free((*pRaiz));
                    *pRaiz = pAux;
                    pAux = NULL;
                   }
                }
             }
          }
}

int main(){
    int x=0,y=0;
    TArvoreA *RaizA =NULL;
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
      remover(&RaizA,y);
    }

    printf("\nArvore em ordem:\n");
    ImprimeArvoreA(RaizA);
    printf("\n\n");
    return 0;
}
