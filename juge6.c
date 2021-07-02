#include <stdio.h>
#include <stdlib.h>


//----------------------------------------------------STRUCTS----------------------------------------------------
struct elemento
{
    int valor;
    struct elemento *ant;
};

typedef struct elemento tipoelementoPilha;

typedef struct
{
    int tamanhoPilha;
    tipoelementoPilha *topo;
}pilhaD;

//----------------------------------------------------FUNCOES----------------------------------------------------

void InicializaPilhaD(pilhaD *pilha)
{
    pilha->tamanhoPilha=0;
    pilha->topo=NULL;
}

void Empilhar(pilhaD *pilha,int valor)
{
    tipoelementoPilha *novo;
    novo=(tipoelementoPilha*)malloc(sizeof(tipoelementoPilha));
    novo->valor=valor;
    novo->ant=NULL;
    if(pilha->tamanhoPilha==0)
    {
        pilha->topo=novo;
        pilha->tamanhoPilha++;
    }
    else
    {
        novo->ant=pilha->topo;
        pilha->topo=novo;
        pilha->tamanhoPilha++;
    }
}

int Desempilha(pilhaD *pilha)
{
    int retorno;
    tipoelementoPilha *aux;
    if(pilha->tamanhoPilha>0)
    {
        aux=pilha->topo;
        retorno=aux->valor;
        pilha->topo=pilha->topo->ant;
        free(aux);
        pilha->tamanhoPilha--;
        return retorno;
    }
}

int Operacao(pilhaD *pilha,char texto)
{
    int valor1,valor2;
    if(pilha->tamanhoPilha>1)
    {
        valor1=Desempilha(pilha);
        valor2=Desempilha(pilha);
        switch(texto)
        {
            case '+':
                valor1=valor1+valor2;
                break;
            case '-':
                valor1=valor2-valor1;
                break;
            case '*':
                valor1=valor1*valor2;
                break;
            case '/':
                valor1=valor2/valor1;
                break;
            case '^':
                valor1=valor2^valor1;
                break;
        }
        return valor1;
    }
}

void ImprimirPilha(pilhaD *pilha)
{
    tipoelementoPilha *aux;
    aux=pilha->topo;
    while(aux!=NULL)
    {
        printf("%d ",aux->valor);
        aux=aux->ant;
    }
}

void EsvaziaPilha(pilhaD *pilha)
{
    int i;
    tipoelementoPilha *aux;
    aux=pilha->topo;
    while(aux!=NULL)
    {
        i=Desempilha(pilha);
        if(pilha->tamanhoPilha>0)
            aux=pilha->topo;
    }
}

int main()
{
    pilhaD pilha;
    int vezes,i,valorInt,valorEmpilhar;
    char valor;
    InicializaPilhaD(&pilha);
    scanf("%d",&vezes);
    for(i=0;i<vezes;i++)
    {
        scanf(" %c",&valor);
        valorInt=valor-48;
        if(valor=='E')
            Empilhar(&pilha,0);
        else if(valor=='C')
        {
            if(pilha.tamanhoPilha!=0)
            {
                valorInt=Desempilha(&pilha);
                printf("%d\n",valorInt);
                EsvaziaPilha(&pilha);
            }
                break;


        }
        else if((valorInt>=0)&&(valorInt<=9))
        {
            valorInt=valor-48;
            valorEmpilhar=Desempilha(&pilha);
            valorEmpilhar=valorEmpilhar*10+valorInt;
            Empilhar(&pilha,valorEmpilhar);
        }
        else
        {
            valorEmpilhar=Operacao(&pilha,valor);
            Empilhar(&pilha,valorEmpilhar);
        }

    }


return 0;
}
