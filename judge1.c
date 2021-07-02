#include <stdio.h>
#include <stdlib.h>
#define N 10
//----------------------STRUCTS----------------------------------------------------
typedef struct
{
    int numLivro;
    int reservado;
}reserva;
typedef struct
{
    int tamanho;
    int ultimo;
    reserva listaR[N];
}listaReservas;

//-------------------FUNCOES------------------------------------------------------
void Inicialista(listaReservas *lista)
{
    int i;
    lista->tamanho=0;
    lista->ultimo=0;
    for(i=0;i<N;i++)
    {
        lista->listaR[i].numLivro=0;
        lista->listaR[i].reservado=0;
    }
}
void InsereEmprestimo(listaReservas *lista,int livro)
{
    lista->listaR[lista->tamanho].numLivro = livro;
    lista->listaR[lista->tamanho].reservado =1;
    lista->tamanho++;
    lista->ultimo++;
}
void ImprimeLista(listaReservas *lista)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("POSICAO:%d NUMERO LIVRO:%d EMPRESTADO:%d \n",i,lista->listaR[i].numLivro,lista->listaR[i].reservado);
    }
}
int main()
{
    listaReservas lista;
    int totalL,i,opcao,livro;
    Inicialista(&lista);
    scanf("%d",&totalL);
    for(i=0;i<totalL;i++)
    {
        scanf("%d %d",&opcao,&livro);
        if(opcao==1)
        InsereEmprestimo(&lista,livro);
        else if(opcao==2)


    }
    ImprimeLista(&lista);

return 0;
}
