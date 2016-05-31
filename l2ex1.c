/*
	Autores:    Felipe Luiz Soares 0030481511012
		    			Jean Vitor  0030481511019

	Exercício 1 da lista 2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo	{	struct regNo *esq;
					int valor;
					struct regNo *dir;
				};
typedef struct regNo TArvore;

void ImprimeArvore(TArvore*r){
	if(r != NULL){
		printf("%d ",r->valor);
		ImprimeArvore(r->esq);
		ImprimeArvore(r->dir);
	}
}

TArvore * AchaPai(TArvore *r, int v)
{	if(r == NULL)
		return NULL;
	else
		if(v <= r->valor)
		  if(r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, v);
		else
			if(r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, v);
}


int Maior(TArvore *r)
{
	if((r->dir) && (r->dir->valor > r->valor))
        	return Maior(r->dir);
	else
		return r->valor;
}
int Menor(TArvore *r)
{
	if((r->esq) && (r->esq->valor < r->valor))
        	return Menor(r->esq);
	else
		return r->valor;
}
int ContaFolhas(TArvore *r)
{		if(r == NULL)
			return 0;
		else
		{	if(r->esq == NULL && r->dir == NULL)
				return 1;
			else
				return ContaFolhas(r->esq) +	ContaFolhas(r->dir);
		}
}
int Altura(TArvore *r)
{
	 int esq, dir;
	 if (r == NULL)
      return -1;
   else{
		 	esq = Altura(r->esq);
			dir = Altura(r->dir);
      if (esq < dir)
				return dir + 1;
      else
				return esq + 1;
   }
}
int busca(TArvore *r, int vBusca)
{	if(r){
    if(r ->valor == vBusca)
			return 1;
    else{
			if(r ->valor < vBusca)
        return busca(r->dir, vBusca);
      else
        return busca(r->esq, vBusca);
    }
		return 0;
  }
}

int main()
{	TArvore *raiz, *aux, *pai;
	int vInfo,vBusca;

	raiz = NULL;
	while(1)
	{	printf("Informe o numero:\n");
		scanf("%d", &vInfo);

		if(vInfo == -999)
			break;

		aux = (TArvore *) malloc(sizeof(TArvore));
		aux->valor = vInfo;
		aux->esq = NULL;
		aux->dir = NULL;

		pai = AchaPai(raiz, vInfo);
		if(pai == NULL)
			raiz = aux;
		else
			if(vInfo <= pai->valor)
				pai->esq = aux;
			else
				pai->dir = aux;
	}

	ImprimeArvore(raiz);
	printf("\nMaior valor contido na árvore: %d\n",Maior(raiz));
	printf("Menor valor contido na árvore: %d\n",Menor(raiz));
	printf("Quantas folhas tem: %d\n",ContaFolhas(raiz));
	printf("Altura: %d\n",Altura(raiz));
	printf("Digite um valor para a busca: \n");
	scanf("%d",&vBusca);
	if(busca(raiz,vBusca)==1)
		printf("VALOR ENCONTRADO\n");
	else
		printf("VALOR NÃO ENCONTRADO\n");

	return 0;
}
