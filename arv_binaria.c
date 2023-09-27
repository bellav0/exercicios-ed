#include <stdio.h>
#include <stdlib.h>
typedef struct no {
  struct no *esq;
  struct no *dir;
  int item;
  int sum;
} no;

no* insere ( no *arv, int num)
{
   no *novo = (no*) malloc (sizeof (no));
  novo->esq = NULL;
  novo->dir = NULL;
  novo->item = num;
  if (arv == NULL)
    {
      arv = novo;
    }
  else
    {
      int achou;
      no* aux = arv;
      achou = 0;
      while (achou == 0)
	{
	  if (novo->item < aux->item)
	    {
	      if (aux->esq == NULL)
		{
		  aux->esq = novo;
		  achou = 1;
		}
	      else
		{
		  aux = aux->esq;
		}
	    }
	  else if (novo->item >= aux->item)
	    {
	      if (aux->dir == NULL)
		{
		  aux->dir = novo;
		  achou = 1;
		}
	      else
		{
		  aux = aux->dir;
		}
	    }
	}
    }
  printf ("\nNumero inserido na arvore!\n");
  return arv;
}

void
imprime (struct no *arv)
{
  if (arv == NULL)
    return;
  printf ("item %d \n", arv->item);
  printf ("soma %d \n", arv->sum);

  imprime (arv->esq);
  imprime (arv->dir);
}
no* soma(no* arv){
  if(arv == NULL){
    return;
  }
  no* esq = soma(arv->esq);
  no* dir = soma(arv->dir);
  arv->sum = 0;
  if(esq != NULL){
    arv->sum = esq->item + esq->sum;
  } 
  if(dir != NULL) {
    arv->sum = arv->sum + dir->item + dir->sum;
  }
  return arv;
}
int busca(no* arv, int chave, int nivel){
  if(arv == NULL){
    return nivel;
  }
  if(arv->item == chave){
    return nivel;
  }
  nivel = nivel + 1;
  if(chave >= arv->item){
     nivel = busca(arv->dir, chave, nivel);
  }else{
    nivel =  busca(arv->esq, chave, nivel);
  }
  return nivel;
}

void main(){

  no* arv = NULL;
  arv = insere(arv, 5);
  arv = insere(arv,3);
  arv=insere(arv, 7);
  arv=insere(arv, 1);
  arv=insere(arv, 4);
  arv = insere(arv, 9);
  arv= soma(arv);
  imprime(arv);
  int nivel = busca(arv, 2, 1);
  printf("nivel %d \n", nivel);
  return;
};