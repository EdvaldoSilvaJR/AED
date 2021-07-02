#include <stdio.h>
#include <stdlib.h>

//-----------------------------------------STRUCT----------------------------------------------------
struct elemento
{
    int ID;
    int quantidade;
    float lucro;
    struct elemento *prox;
    int compra;
};
typedef struct elemento Tipoelemento;
typedef struct
{
    Tipoelemento *primeiro;
    Tipoelemento *ultimo;
    int tamanho;
}listaD;


//-----------------------------------------FUNCOES----------------------------------------------------
void InicalizaLista(listaD *lista)
{
    lista->tamanho=0;
    lista->primeiro=NULL;
    lista->ultimo=NULL;
}
void ImprimeLista(listaD *lista)
{
    Tipoelemento *aux;
    int multiplicador;
    aux=lista->primeiro;
    while(aux!=NULL)
    {
        if(aux->compra==0)
            aux->compra=1;
        printf("%d %f\n",aux->ID,aux->lucro*(aux->compra));
        aux=aux->prox;
    }
}
Tipoelemento *PosicaoInsercao(listaD *lista,float valor)
{
    int i;
    Tipoelemento *posicao;
    posicao=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
        if((posicao->lucro>=valor)&&(posicao->prox->lucro<valor))
            return posicao;
        else
            posicao=posicao->prox;
    }
}
void InsereElemento(listaD *lista,Tipoelemento produto)
{
    Tipoelemento *novo,*posicao,*aux;
    int i;
    aux=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
        if(aux->ID==produto.ID)
        {
            printf("ja existe\n");
            i=-1;
            break;
        }
        else
            aux=aux->prox;
    }
    if(i!=-1)
    {
        novo=(Tipoelemento*)malloc(sizeof(Tipoelemento));
        novo->ID=produto.ID;
        novo->quantidade=produto.quantidade;
        novo->lucro=produto.lucro;
        novo->compra=0;
        novo->prox=NULL;
        if(lista->tamanho==0)
        {
            lista->primeiro=novo;
            lista->ultimo=novo;
            lista->tamanho++;
        }
        else
        {
                //CASO O NOVO VALOR SEJA MAIOR QUE O PRIMEIRO
            if(lista->primeiro->lucro<=novo->lucro)
            {
                novo->prox=lista->primeiro;
                lista->primeiro=novo;
                lista->tamanho++;
            }
                //CASO O NOVO VALOR SEJA MENOR QUE O ULTIMO
            else if(lista->ultimo->lucro>novo->lucro)
            {
                lista->ultimo->prox=novo;
                lista->ultimo=novo;
                lista->tamanho++;
            }
            else if(lista->ultimo->lucro==novo->lucro)
            {
                aux=lista->primeiro;
                for(i=0;i<lista->tamanho;i++)
                {
                    if(aux->prox->lucro==novo->lucro)
                        break;
                    else
                        aux=aux->prox;
                }
                novo->prox=aux->prox;
                aux->prox=novo;
                lista->tamanho++;
            }
                //CASO O NOVO VALOR ESTEJA ENTRE A LISTA
            else
            {
                posicao=PosicaoInsercao(lista,novo->lucro);
                if(posicao->lucro==novo->lucro)
                {
                    aux=lista->primeiro;
                    for(i=0;i<lista->tamanho;i++)
                    {
                        if(aux->prox->lucro==novo->lucro)
                            break;
                        else
                            aux=aux->prox;
                    }
                    novo->prox=posicao;
                    aux->prox=novo;
                    lista->tamanho++;
                }
                else
                {
                    novo->prox=posicao->prox;
                    posicao->prox=novo;
                    lista->tamanho++;
                }

            }
        }
    }

}
void Esvazia(listaD *lista)
{
    int i;
    Tipoelemento *aux;
    aux=lista->primeiro;
    for(i=0;i<lista->tamanho;i++)
    {
        lista->primeiro=aux->prox;
        free(aux);
        aux=lista->primeiro->prox;
    }
    //free(aux);
    //printf("LISTA LIMPA\n");
}
void AumentaQuantidade(listaD *lista,int ID,int quantidadeMais)
{
    int i;
    Tipoelemento *aux;
    aux=lista->primeiro;
    if(lista->tamanho>0)
    {
        for(i=0;i<lista->tamanho;i++)
        {
            if(aux->ID==ID)
            {
                aux->quantidade=aux->quantidade+quantidadeMais;
                break;
            }
            else
                aux=aux->prox;
        }
    }
}
void RemoveQTD(listaD *lista,int ID)
{
    int i;
    Tipoelemento *aux;
    aux=lista->primeiro;
    if(lista->tamanho>0)
    {
        for(i=0;i<lista->tamanho;i++)
        {
            if(aux->ID==ID)
            {
                if(aux->quantidade==0)
                    printf("nao existe\n");
                else
                {
                    aux->quantidade--;
                    aux->compra++;
                }
                break;
            }
            else
                aux=aux->prox;
        }
    }
}
void RemoveProduto(listaD *lista,int ID)
{
    int i;
    Tipoelemento *aux,*aux2;
    aux=lista->primeiro;
    aux2=lista->primeiro;
    if(lista->tamanho==0)
        printf("nao existe\n");
    else if(lista->tamanho>0)
    {
            //AUX RECEBE PONTEIRO ONDE O ID FOI ENCONTRADO
        for(i=0;i<lista->tamanho;i++)
        {
            if(aux->ID==ID)
                break;
            else
                aux=aux->prox;
        }
            //CASO A ID ENCONTRADA SEJA A PRIMEIRA
        if(lista->primeiro->ID==ID)
        {
            lista->primeiro=aux->prox;
            free(aux);
            lista->tamanho--;
        }
            //CASO A ID ENCONTRADA SEJA A ULTIMA
        else if(lista->ultimo->ID==ID)
        {
             for(i=0;i<lista->tamanho;i++)
            {
                if(aux2->prox==aux)
                    break;
                else
                    aux2=aux2->prox;
            }
            lista->ultimo=aux2;
            aux2->prox=NULL;
            free(aux);
            lista->tamanho--;
        }
            //CASO A ID NAO SEJA NEM A PRIMEIRA NEM A ULTIMA
        else if(i==lista->tamanho)
            printf("nao existe\n");
        else
        {
            for(i=0;i<lista->tamanho;i++)
            {
                if(aux2->prox==aux)
                    break;
                else
                    aux2=aux2->prox;
            }
            aux2=aux->prox;
            free(aux);
            lista->tamanho--;
        }
    }
}
//-----------------------------------------------MAIN---------------------------------------------------------------
int main()
{
    listaD lista;
    Tipoelemento aux;
    int i,vezes,opcao,qtd=0,ID=0;
    InicalizaLista(&lista);
    scanf("%d",&vezes);
    for(i=0;i<vezes;i++)
    {
        scanf("%d",&opcao);
        switch(opcao)
        {
            case 1:
            scanf("%d %d %f",&aux.ID,&aux.quantidade,&aux.lucro);
            InsereElemento(&lista,aux);
            break;
            case 2:
                scanf("%d %d",&ID,&qtd);
                AumentaQuantidade(&lista,ID,qtd);
            break;
            case 3:
                scanf("%d",&ID);
                RemoveQTD(&lista,ID);
            break;
            case 4:
                scanf("%d",&ID);
                RemoveProduto(&lista,ID);
        }

    //ImprimeLista(&lista);
        //printf("TAMANHO DA LISTA:%d\n",lista.tamanho);
    }
    ImprimeLista(&lista);
    //Esvazia(&lista);
return 0;
}
