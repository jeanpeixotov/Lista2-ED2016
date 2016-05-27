#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct regNo	{	struct regNo *esq;
					int valor;
					struct regNo *dir;
				};
typedef struct regNo TArvore;

TArvore * AchaPai(TArvore *r, int v)
{	if(r == NULL)
	/* Arvore vazia */
		return NULL;
	else
		if(v <= r->valor)
		/* Novo noh deve ficar a esquerda de r */
			if(r->esq == NULL)
				return r;
			else
				return AchaPai(r->esq, v);
		else
		/* Novo noh deve ficar a direita de r */
			if(r->dir == NULL)
				return r;
			else
				return AchaPai(r->dir, v);
}

void ImprimeArvore(TArvore*r){
  printf("<");
  if(r != NULL){
    printf("%d", r->valor);
    ImprimeArvore(r->esq);
    ImprimeArvore(r->dir);
  }
  printf(">");
}

int main()
{	TArvore *raiz, *aux, *pai;
	int vInfo;

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
  printf("\n");
  return 0;
}
