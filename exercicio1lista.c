#include <stdio.h>
#include <stdlib.h>
#define N 5

//STRUCT
typedef struct
{
    int ultimo;
    int tamanho;
    int lista[N];
}TipoListaES;
    // Inicializa a lista com 0 em todas as posições e tamanho N
void Inicializa(TipoListaES *lista)
{
    int i;
    lista->tamanho = 0;
    for(i=0;i<N;i++)
        lista->lista[i] = 0;
    lista->ultimo=0;
}
    //Insere um valor na lista (na ultima posição)
void InsereListaES(TipoListaES *lista)
{
    lista->tamanho++;
    scanf("%d",&lista->lista[lista->tamanho-1]);
    lista->ultimo = lista->tamanho-1;
}
    //Remove um valor na posição indicada e retorna o mesmo
int RemoveValor(TipoListaES *lista,int posicao)
{
    int retorno,i;
    retorno = lista->lista[posicao];
    for(i=posicao;i<lista->tamanho;i++)
    {
        lista->lista[i]= lista->lista[i+1];
    }
    lista->lista[lista->ultimo]=0;
    lista->tamanho--;
    lista->ultimo--;
    return retorno;
}
    //Imprime todos os valores da lista e mostra o seu tamanho
void ImprimeListaES(TipoListaES *lista)
{
    int i;
    for(i=0;i<lista->tamanho;i++)
    {
        printf(" POSICAO: %d",i);
        printf(" %d \n",lista->lista[i]);
    }
    printf("TAMANHO:%d\nULTIMO VALOR:%d \n",lista->tamanho,lista->lista[lista->ultimo]);
}
int main()
{
    TipoListaES lista;
    int cont=0,remocao;
    Inicializa(&lista);
    do
    {
        InsereListaES(&lista);
        cont++;
    }while(cont<N);
    remocao = RemoveValor(&lista,0);
    printf("VALOR REMOVIDO:%d \n",remocao);
    ImprimeListaES(&lista);
return 0;
}
