#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    int rg;
    int cpf;
}aluno;

int main()
{
    int i=0;
    aluno *lista, aux;
    lista = (aluno*)malloc(sizeof(aluno)*2);
    FILE *arquivo=NULL;
    arquivo = fopen("arquivo.bin","wb");
    for(i=0;i<2;i++)
    {
        scanf("%s %d %d",lista[i].nome,&lista[i].cpf,&lista[i].rg);
        fwrite(&lista[i],sizeof(aluno),1,arquivo);

    }
    fclose(arquivo);

    arquivo= fopen("arquivo.bin", "rb");
    for(i=0;i<2;i++)
    {
        fread(&aux,sizeof(aluno),1,arquivo);
        printf("NOME:%s RG:%d CPF:%d \n",aux.nome,aux.rg,aux.cpf);
    }
    free(lista);
return 0;
}
