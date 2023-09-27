/******************************************************************************
LISTA ENCADEADA ORDENADA COM NÓ CABEÇA
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int chave;
  struct lista *ant;
  struct lista *prox;
} lista;

void
insert (lista * l, int valor)
{
  printf ("valor entrando %d \n", valor);
  lista *novo = malloc (sizeof (lista));
  novo->chave = valor;
  if (l->prox == NULL)
    {
      l->prox = novo;
      novo->ant = l;
      return;
    }

  lista *aux = l->prox;
  while (aux != NULL)
    {
      printf ("valor %d \n", aux->chave);
      if (aux->chave == valor)
	{
	  break;
	}

      if (aux->chave > valor)
	{
	  break;
	}
      aux = aux->prox;
    }

  novo->prox = aux;
  novo->ant = aux->ant;
  aux->ant->prox = novo;
  aux->ant = novo;



}


int
main ()
{

  lista *l;
  if (l == NULL)
    {
      l = malloc (sizeof (lista));
      l->prox = NULL;
      l->ant = NULL;
    }
  insert (l, 4);
  insert (l, 3);
  insert (l, 1);
  insert(l,2);
  lista *aux = l;
  while (aux != NULL)
    {
      printf ("Number %d \n", aux->chave);
      aux = aux->prox;
    }

  free (l);
  free (aux);

  return 0;
}
