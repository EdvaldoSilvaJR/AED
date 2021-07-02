#include <stdio.h>
#include <stdlib.h>
#define N 10

//----------------------STRUCTS----------------------------------------------------
 typedef struct
 {
    int RA;
    int prox;

 }reserva;

 typedef struct
 {
     int tamanhoLista;
     int primeiro;
     int ultimo;
     reserva listareserva[N];
     int posLivre[N];
 }listaEEreserva;

//----------------------FUNCOES------------------------------------------------------
void InicializaListaReserva(listaEEreserva *lista)
{
    int i;
    lista->tamanhoLista=0;
    lista->primeiro=-1;
    lista->ultimo=-1;
    for(i=0;i<N;i++)
    {
        lista->listareserva[i].RA=0;
        lista->listareserva[i].prox=-1;
        lista->posLivre[i]=0;
    }
}
int PosLivre(listaEEreserva *lista)
{
    int i;
    for(i=0;i<lista->tamanhoLista+1;i++)
    {
        if(lista->posLivre[i]==0)
            {
                //printf("POSICAO ENCONTRADA PARA INSERCAO:%d\n",i);
            return i;
            }

    }
    return -1;
}
void InsereReserva(listaEEreserva *lista,int RA,int posicao)
{
    if(lista->tamanhoLista==0)
    {
        lista->listareserva[posicao].RA=RA;
        lista->posLivre[posicao]=1;
        lista->primeiro=posicao;
        lista->ultimo=posicao;
        lista->tamanhoLista++;
    }
    else if(lista->tamanhoLista<N)
    {
        lista->listareserva[posicao].RA=RA;
        lista->posLivre[posicao]=1;
        printf("POSSIVEL PROBLEMA:POSICAO %d ULTIMO:%d\n",posicao,lista->ultimo);
        lista->listareserva[lista->ultimo].prox=posicao;
        if(lista->ultimo==posicao)
            lista->listareserva[posicao].prox=-1;
        lista->tamanhoLista++;
        lista->ultimo=posicao;
    }
    else
        printf("lista cheia");

}
int EncontraPosicaoRemocao(listaEEreserva *lista,int RA)
{
    int i;
    for(i=0;i<lista->tamanhoLista;i++)
    {
        if(lista->listareserva[i].RA==RA)

            return i;
    }

}
void RemoveReserva(listaEEreserva *lista,int posicao)
{
    int i,anterior=0;
    for(i=0;i<N;i++)
    {
        if(lista->listareserva[lista->listareserva[i].prox].RA==lista->listareserva[posicao].RA)
            anterior=i;
    }
    printf("ANTERIOR AO VALOR A SER REMOVIDO:%d\n",anterior);
    lista->listareserva[posicao].RA=0;
    if(lista->ultimo==posicao)
    {
        lista->listareserva[anterior].prox=-1;
        lista->listareserva[posicao].prox=-1;
        lista->posLivre[posicao]=0;
        lista->ultimo=anterior;
        lista->tamanhoLista--;
    }
    else if(lista->primeiro==posicao)
    {
        lista->primeiro=lista->listareserva[posicao].prox;
        lista->listareserva[posicao].prox=-1;
        lista->posLivre[posicao]=0;
        lista->tamanhoLista--;
    }
    else
    {
        lista->listareserva[anterior].prox=lista->listareserva[posicao].prox;
        lista->listareserva[posicao].prox=-1;
        lista->posLivre[posicao]=0;
        lista->tamanhoLista--;
    }
}
void Imprimir(listaEEreserva *lista,int posicao)
{
    if(posicao!=-1)
    {
        printf("POSICAO:%d RA:%d PROX:%d\n",posicao,lista->listareserva[posicao],lista->listareserva[posicao].prox);
        Imprimir(lista,lista->listareserva[posicao].prox);
    }
    else
        printf("TAMANHO DA LISTA:%d PRIMEIRO:%d ULTIMO:%d",lista->tamanhoLista,lista->primeiro,lista->ultimo);
}
void ImprimirTudo(listaEEreserva *lista)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("POSICAO:%d RA:%d PROXIMO:%d \n",i,lista->listareserva[i].RA,lista->listareserva[i].prox);
    }
            printf("TAMANHO DA LISTA:%d PRIMEIRO:%d ULTIMO:%d\n",lista->tamanhoLista,lista->primeiro,lista->ultimo);

}
int VerificaAno(listaEEreserva *lista,int RA)
{
    int ano=0,casa=0,cont=0,auxRA;
    do
    {
        casa=ano/10;
        cont++;
    }while(casa>0)
    if(cont==5)
        auxRA=RA/5;
    else if(cont==6)
        auxRA=RA/6;
    switch(ano)
    {
        case(ano==66)
    }
}
int main()
{
    int i,vezes,posicao,RA,opcao,remocao,anos[8];
    listaEEreserva lista;
    InicializaListaReserva(&lista);
    scanf("%d",&vezes);
    for(i=0;i<vezes;i++)
    {
        scanf("%d %d",&opcao,&RA);
        if(opcao==1)
        {
            InsereReserva(&lista,RA,PosLivre(&lista));
            ImprimirTudo(&lista);
        }
        else if(opcao==2)
        {
            remocao=EncontraPosicaoRemocao(&lista,RA);
            if(remocao!=-1)
            {
                RemoveReserva(&lista,remocao);
                ImprimirTudo(&lista);
            }
        }
    }
    Imprimir(&lista,lista.primeiro);
return 0;
}
