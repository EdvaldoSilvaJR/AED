#include <stdio.h>
#include <stdlib.h>
#define N 10

//-----------------------------------------STRUCTS-----------------------------------------

typedef struct{
    int valor;
    int prox;
}Tipoinfo;

typedef struct{
    int tamanholista;
    int primeiro;
    int ultimo;
    int posLivre[N];
    Tipoinfo elementos[N];
}ListaEE;

//-----------------------------------------FUNCOES-----------------------------------------
void Inicializalista(ListaEE *listaEE)
{
    int i;
    listaEE->tamanholista=0;
    listaEE->primeiro=-1;
    listaEE->ultimo=-1;
        //zerando os valores da lista de elementos
    for(i=0;i<N;i++)
    {
        listaEE->elementos[i].valor=0;
        listaEE->elementos[i].prox=-1;
        listaEE->posLivre[i]=1;
    }
}
void InsereElementoFinal(ListaEE *listaEE,int posicao)
{
    if(posicao!=-1)
    {
        scanf("%d",&listaEE->elementos[posicao].valor);
        if(listaEE->tamanholista==0)
            listaEE->primeiro=posicao;
        else
            listaEE->elementos[listaEE->ultimo].prox=posicao;
        listaEE->elementos[posicao].prox=-1;
        listaEE->tamanholista++;
        listaEE->ultimo=posicao;
        listaEE->posLivre[posicao]=0;
    }
}
void InsereElemento(ListaEE *lista,int posicao)
{
    int i;
    if(posicao!=-1)
    {

        scanf("%d",&lista->elementos[lista->ultimo+1].valor);
        lista->elementos[lista->ultimo+1].prox=lista->elementos[posicao-1].prox;
        lista->elementos[posicao-1].prox=lista->ultimo+1;
        lista->elementos[posicao].prox=-1;
        lista->posLivre[lista->ultimo+1]=0;
    }
}
void Imprimir(ListaEE *lista,int posicao)
{
    //do
    //{
        if(posicao==0)
        {
            printf("POSICAO:%d VALOR:%d \n",posicao,lista->elementos[posicao].valor);
            posicao++;
            Imprimir(lista,posicao);
        }
        else if(lista->elementos[posicao].prox!=-1)
        {
            printf("POSICAO:%d VALOR:%d \n",posicao,lista->elementos[lista->elementos[posicao-1].prox].valor);
            posicao++;
            Imprimir(lista,posicao);
        }
    //}while(lista->elementos[i].prox!=-1);
    if(posicao==lista->tamanholista)
        printf("PRIMEIRO:%d ULTIMO:%d TAMANHO:%d\n",lista->primeiro,lista->ultimo,lista->tamanholista);
}
int main()
{
    int numerotestes,i;
    ListaEE lista;
    Inicializalista(&lista);
    scanf("%d",&numerotestes);
    for(i=0;i<numerotestes;i++)
    {

        InsereElementoFinal(&lista,i);
    }
    Imprimir(&lista,0);

return 0;
}
