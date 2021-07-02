#include <stdio.h>
#include <stdlib.h>

void InsereValor(int **matriz,int valor,int i, int j)
{
    matriz[i][j]=valor;
}
void Aloca(int **vetor,int tamanho)
{
    vetor[tamanho]=(int*)malloc(sizeof(int*));
}
int main()
{
    int **vetor,teste,i,tamanho=0;
    vetor = (int**)malloc(sizeof(int*));
    do
    {
        scanf("%d",&teste);
        if(teste>0)
        {
            tamanho++;
            vetor=realloc(vetor,sizeof(int));
            Aloca(vetor,tamanho);
        }
    }while(teste!=0);
    free(vetor);
return 0;
}
