#include <stdio.h>
#include <stdlib.h>
#define N 10
//-----------------------------------------------------------------STRUCTS-----------------------------------------------------------------
typedef struct
{
    int elementos[N];
    int topo;
}tipopilha;

//-----------------------------------------------------------------FUNCOES-----------------------------------------------------------------

void ImprimirTudo(tipopilha *pilha)
{
    int i;
    for(i=N-1;i>=0;i--)
        printf("%d\n",pilha->elementos[i]);
}
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

int main()
{
    int vezes,opcao=1,valor,i;
    tipopilha pilha;
    printf("DIGITE O NUMERO DE VEZES \n");
    scanf("%d",&vezes);
    InicializaPilha(&pilha);
    for(i=0;i<vezes;i++)
    {
        printf("DIGITE A OPCAO\n");
        scanf("%d",&opcao);
        if(opcao==1)
        {
            printf("DIGITE O VALOR\n");
            scanf("%d",&valor);
            Empilhar(&pilha,valor);
        }
        else if(opcao==2)
        {
            valor = Desempilha(&pilha);
            printf("VALOR REMOVIDO %d\n",valor);
        }
        else if(opcao==3)
        {
            valor = ConsultarTopo(&pilha);
            printf("VALOR NO TOPO:%d\n",valor);
        }

        printf("TUDO\n");
        ImprimirTudo(&pilha);
        printf("NORMAL\n");
        ImprimirPilha(&pilha);
    }
        printf("TUDO\n");
        ImprimirTudo(&pilha);
        printf("NORMAL\n");
        ImprimirPilha(&pilha);

return 0;
}
