#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int RG;
    int CPF;
    char nome[50];
}cadastro;
void InsereCadastro(cadastro *lista,int posicao)
{

}
int main()
{
    int tamanho=2,i=0;
    FILE *arquivo;
    cadastro *lista;
    lista=(cadastro*) malloc(sizeof(cadastro)*2);
    arquivo = fopen("arquivo2.txt","w");
    for(i=0;i<tamanho;i++)
    {
        scanf("%d %d %s",&lista[i].RG,&lista[i].CPF,&lista[i].nome);
        fprintf(arquivo,"Nome:%s RG:%d CPF:%d \n",lista[i].nome,lista[i].RG,lista[i].CPF);
    }

return 0;
}
