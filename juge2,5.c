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
     int anos[8];
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
        if(i<8)
            lista->anos[i]=0;
    }
}
/*
int encontraPosicaoInsere(listaEEreserva *lista,int RA)
{
    int i;
    if(lista->tamanhoLista==0)
        return 0;
    else if(lista->tamanhoLista==N)
        printf("lista de reserva cheia\n");
    else
    {
        for(i=0;i<lista->tamanhoLista;i++)
        {
            if(lista->listareserva[i].RA>RA)
        }
    }
}*/
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
int *VerificaAno(listaEEreserva *lista,int RA)
{
    int ano=0,cont=0,i;
    ano=RA/1000;
    switch(ano)
    {
        case 66:
            lista->anos[0]=lista->anos[0]+1;
            ano=ano-55;
        break;
        case 76:
            lista->anos[1]=lista->anos[1]+1;
            ano=ano-65;
        break;
        case 86:
            lista->anos[2]=lista->anos[2]+1;
            ano=ano-75;
        break;
        case 96:
            lista->anos[3]=lista->anos[3]+1;
            ano=ano-85;
        break;
        case 106:
            lista->anos[4]=lista->anos[4]+1;
            ano=ano-95;
        break;
        case 116:
            lista->anos[5]=lista->anos[5]+1;
            ano=ano-105;
        break;
        case 126:
            lista->anos[6]=lista->anos[6]+1;
            ano=ano-115;
        break;
        case 136:
            lista->anos[7]=lista->anos[7]+1;
            ano=ano-125;
        break;
    }
}
void InsereReserva(listaEEreserva *lista,int RA)
{
    int i,posicao;
        //PEGA A PROXIMA POSICAO LIVRE
    posicao=PosLivre(lista);
        //CASO A LISTA ESTEJA VAZIA
    if(lista->tamanhoLista==0)
    {
        lista->listareserva[posicao].RA=RA;
        lista->posLivre[posicao]=1;
        lista->primeiro=posicao;
        lista->ultimo=posicao;
        lista->tamanhoLista++;
        VerificaAno(lista,RA);
    }
        //CASO A LISTA ESTEJA CHEIA
    else if(lista->tamanhoLista==N)
        printf("lista cheia\n");
    else
    {
        //INSERE O RA NA POSICAO VAZIA
        lista->listareserva[posicao].RA=RA;
        lista->tamanhoLista++;
        lista->posLivre[posicao]=1;
        VerificaAno(lista,RA);
            //ENCONTRA CADA CASO DE INSERÇÃO PARA ORDENAR
                //CASO 1: O PRIMEIRO ELEMENTO SEJA MAIOR QUE O NOVO
            if(lista->listareserva[lista->primeiro].RA>RA)
            {
                lista->listareserva[posicao].prox=lista->primeiro;
                lista->primeiro=posicao;
            }
                //CASO 2 ULTIMO MENOR QUE O NOVO VALOR
            else if(lista->listareserva[lista->ultimo].RA<RA)
            {
                lista->listareserva[lista->ultimo].prox=posicao;
                lista->ultimo=posicao;
            }
            else
            {
                    //CASO 3 NOVO VALOR INSERIDO NO MEIO
                for(i=0;i<lista->tamanhoLista;i++)
                {
                    if((lista->listareserva[i].RA<RA)&&(lista->listareserva[lista->listareserva[i].prox].RA>RA))
                    {
                        lista->listareserva[posicao].prox=lista->listareserva[i].prox;
                        lista->listareserva[i].prox=posicao;
                    }
                }
            }
    }
}
void Imprimir(listaEEreserva *lista,int posicao)
{
    if(posicao!=-1)
    {
        printf("%d ",lista->listareserva[posicao].RA);
        Imprimir(lista,lista->listareserva[posicao].prox);
    }
    else
        printf("\n",lista->tamanhoLista,lista->primeiro,lista->ultimo);
}
void RemoveReserva(listaEEreserva *lista,int RA)
{
    int i,posicao=-1;
    for(i=0;i<lista->tamanhoLista;i++)
    {
        if(lista->listareserva[i].RA==RA)
        {
            posicao=i;
            break;
        }
    }
    if(posicao==-1)
        printf("nao existe\n");
    else
    {
        lista->posLivre[posicao]=0;
        if(posicao==lista->primeiro)
        {
            lista->listareserva[lista->primeiro].RA=0;
            lista->primeiro=lista->listareserva[posicao].prox;
        }
        else if(posicao==lista->ultimo)
        {
            lista->listareserva[lista->ultimo].RA=0;
            for(i=0;i<lista->tamanhoLista;i++)
            {
                if(lista->listareserva[i].prox==posicao)
                    lista->ultimo=i;
            }
            lista->listareserva[posicao].prox=-1;
        }
        else
        {
            for(i=0;i<lista->tamanhoLista;i++)
            {
                if(lista->listareserva[i].prox==posicao)
                {
                    lista->listareserva[i].prox=lista->listareserva[posicao].prox;
                    lista->listareserva[posicao].prox=-1;
                }
            }
        }
        lista->tamanhoLista--;
    }
}
 int main()
 {
    int i,vezes,opcao, RA,ano=1;
    listaEEreserva lista;
    InicializaListaReserva(&lista);
    scanf("%d",&vezes);
    if((vezes>=1)&&(vezes<=100))
    {
        for(i=0;i<vezes;i++)
        {
            scanf("%d %d",&opcao,&RA);
            if(opcao==1)
            {
                InsereReserva(&lista,RA);
            }
            else if(opcao==2)
            {
                RemoveReserva(&lista,RA);
            }
             Imprimir(&lista,lista.primeiro);
        }

    }

    for(i=0;i<8;i++)
    {
        printf("201%d: %d\n",ano,lista.anos[i]);
        ano++;
    }
 return 0;
 }
