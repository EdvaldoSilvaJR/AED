#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
//-----------------------------------------------------------------STRUCTS-----------------------------------------------------------------
typedef struct
{
    int elementos[N];
    int topo;
}tipopilha;

//-----------------------------------------------------------------FUNCOES-----------------------------------------------------------------

void InicializaPilha(tipopilha *pilha)
{
    int i;
    pilha->topo=-1;
    for(i=0;i<N;i++)
        pilha->elementos[i]=0;
}

void Empilhar(tipopilha *pilha,int valor)
{
    if(PilhaCheia(pilha)==1)
        printf("PILHA CHEIA\n");
    else
    {
        pilha->topo++;
        pilha->elementos[pilha->topo]=valor;
    }
}

int Desempilha(tipopilha *pilha)
{
    int retorno=-1;
    if(PilhaVazia(pilha)==0)
        {
            retorno = pilha->elementos[pilha->topo];
            pilha->elementos[pilha->topo]=0;
            pilha->topo--;
        }
    else
        printf("PILHA VAZIA\n");
    return retorno;
}

void ImprimirPilha(tipopilha *pilha)
{
    int i=pilha->topo;
    while(i>=0)
    {
        printf("%d\n",pilha->elementos[i]);
        i--;
    }
}
void ImprimirTudo(tipopilha *pilha)
{
    int i;
    for(i=0;i<N;i++)
        printf("%d\n",pilha->elementos[i]);
}
int ConsultarTopo(tipopilha *pilha)
{
    int retorno=-1;
    if(PilhaVazia(pilha)==0)
        retorno = pilha->elementos[pilha->topo];
    else
        printf("PILHA VAZIA\n");
    return retorno;
}
int PilhaCheia(tipopilha *pilha)
{
    if(pilha->topo==N-1)
        return 1;
    else
        return 0;
}

int PilhaVazia(tipopilha *pilha)
{
    if(pilha->topo==-1)
        return 1;
    else
        return 0;
}
void Posfixa(tipopilha *pilha,char texto[10])
{
    int valor,aux,aux2;
        if(*texto=='-')
        {
            aux=Desempilha(pilha);
            aux2=Desempilha(pilha);
            aux=aux2-aux;
            Empilhar(pilha,aux);
        }
        else if(*texto=='+')
        {
            aux=Desempilha(pilha);
            aux2=Desempilha(pilha);
            aux=aux+aux2;
            Empilhar(pilha,aux);
        }
        else if(*texto=='/')
        {
            aux=Desempilha(pilha);
            aux2=Desempilha(pilha);
            aux=aux2/aux;
            Empilhar(pilha,aux);
        }
        else if(*texto=='*')
        {
            aux=Desempilha(pilha);
            aux2=Desempilha(pilha);
            aux=aux*aux2;
            Empilhar(pilha,aux);
        }
        else if(*texto!='s')
        {
            printf("ENTROU NO EMPILHAR\n");
            valor=atoi(texto);
            Empilhar(pilha,valor);
        }
}
int main()
{
    tipopilha pilha;
    char valor[10];
    int convertido;
    InicializaPilha(&pilha);
    do{
        gets(valor);
        convertido=atoi(valor);
        Posfixa(&pilha,valor);
        ImprimirPilha(&pilha);
    }while(*valor!='s');


return 0;
}
