#include <stdio.h>
#include <stdlib.h>

#define N 4
//------------------------FUNCOES---------------------------------
void InsereValores(int matriz[N][N],int i,int j)
{
    if(j<N)
    {
        matriz[i][j]=rand()%11;
        InsereValores(matriz,i,j+1);
    }
    else if(i<N)
    {
        i++;
        j=0;
        if(i==N)
            return ;
        else
        InsereValores(matriz,i,j);
    }
}
void ImprimeMatriz(int matriz[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}
int BuscaRepetidos(int matriz[N][N],int valor,int i,int j)
{
    int cont=0;
    if(valor==matriz[i][j])
    {
        cont++;
        BuscaRepetidos(matriz,valor,i++,j++);
    }
    printf("Quantidade de vezes que valor %d aparece %d")

   // else if()
}


int main()
{
    int matriz[N][N];
    InsereValores(matriz,0,0);
    ImprimeMatriz(matriz);
return 0;
}
