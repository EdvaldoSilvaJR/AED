#include<stdlib.h>
#include<stdio.h>

//------------------------------------------STRUCT------------------------------------------------------------

struct elemento
{
    int info;
    struct elemento *prox;
    struct elemento *ant;
};
typedef struct elemento Tipoelemento;
typedef struct
{
    Tipoelemento *primeiro;
    Tipoelemento *ultimo;
    int tamanho;
}listaDDE;

//------------------------------------------FUNCOES------------------------------------------------------------
void InicializaLista(listaDDE *lista)
{
    lista->primeiro=NULL;
    lista->ultimo=NULL;
    lista->tamanho=0;
}

void InsereElementoFinal(listaDDE *lista,int valor)
{
    Tipoelemento *novo;
    novo=(Tipoelemento*)malloc(sizeof(Tipoelemento));
    novo->info=valor;
    novo->prox=NULL;
    novo->ant=NULL;
    if(lista->tamanho==0)
    {
        lista->primeiro=novo;
        lista->ultimo=novo;
    }
    else
    {
        lista->ultimo->prox=novo;
        novo->ant=lista->ultimo;
        lista->ultimo=novo;
        lista->primeiro->ant=novo;
        novo->prox=lista->primeiro;
    }
    lista->tamanho++;
}

void ImprimeLista(listaDDE *lista)
{
    int i;
    Tipoelemento *aux;
    aux=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
        printf("%d ",aux->info);
        aux=aux->prox;
    }
    printf("\n");
}
void InsereMeio(listaDDE *lista,int valor,int posicao)
{
    int i;
    Tipoelemento *novo,*aux;
    novo=(Tipoelemento*)malloc(sizeof(Tipoelemento));
    novo->info=valor;
    novo->prox=NULL;
    novo->ant=NULL;
    aux=lista->primeiro;
    if(posicao==0)
    {
        lista->primeiro->ant=novo;
        novo->prox=lista->primeiro;
        lista->primeiro=novo;
        novo->ant=lista->ultimo;
        lista->ultimo->prox=novo;
    }
    else if(posicao==lista->tamanho)
        InsereElementoFinal(lista,valor);
    else
    {
        for(i=0;i<posicao;i++)
            aux=aux->prox;
        novo->ant=aux->ant;
        aux->ant->prox=novo;
        novo->prox=aux;
        aux->ant=novo;
    }

    lista->tamanho++;
}

void RemoveInicio(listaDDE *lista)
{
    Tipoelemento *aux;
    if(lista->primeiro!=NULL)
    {
        aux=lista->primeiro;
        lista->primeiro=aux->prox;
        lista->primeiro->ant=lista->ultimo;
        lista->ultimo->prox=lista->primeiro;
        free(aux);
        lista->tamanho--;
    }
    else
        printf("LISTA NAO POSSUI PRIMEIRO\n");
}
void RemoveFinal(listaDDE *lista)
{
    int i;
    Tipoelemento *aux;
    if(lista->ultimo!=NULL)
    {
        aux=lista->ultimo;
        lista->ultimo=aux->ant;
        lista->ultimo->prox=lista->primeiro;
        free(aux);
        lista->tamanho--;
    }
    else
        printf("LISTA NAO POSSUI PRIMEIRO\n");
}
void RemoveLD(listaDDE *lista,Tipoelemento *posicao)
{
    int i;
    if(posicao==lista->primeiro)
        RemoveInicio(lista);
    else if(posicao==lista->ultimo)
        RemoveFinal(lista);
    else
    {
        posicao->ant->prox=posicao->prox;
        posicao->prox->ant=posicao->ant;
        free(posicao);
        lista->tamanho--;
    }
}
void VerificaTripla(listaDDE *lista)
{
    int i=0;
    Tipoelemento *aux;
    aux=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
            if((aux->info)+(aux->prox->info)+(aux->ant->info)==10)
            {
                RemoveLD(lista,aux->ant);
                RemoveLD(lista,aux->prox);
                RemoveLD(lista,aux);
                i=0;
                aux=lista->primeiro;
            }
            aux=aux->prox;
    }
}
void Esvazia(listaDDE *lista)
{
    int i;
    Tipoelemento *aux;
    aux=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
        RemoveInicio(lista);
        aux=aux->prox;
    }
}
int main()
{
    int i,valor,posicao;
    listaDDE lista;
    InicializaLista(&lista);
    for(i=0;i<10;i++)
    {
        scanf("%d",&valor);
        InsereElementoFinal(&lista,valor);
    }
    for(i=0;i<5;i++)
    {
        scanf("%d %d",&valor,&posicao);
        InsereMeio(&lista,valor,posicao);
        VerificaTripla(&lista);
        ImprimeLista(&lista);
    }
    if(lista.tamanho==0)
        printf("ganhou\n");
    else
    {
        printf("perdeu\n");
        Esvazia(&lista);
    }
return 0;
}
