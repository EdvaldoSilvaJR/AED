#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Alunos
{
    char nome[50];
    int matricula;
    long int cpf;
};
struct Alunos **Alocalista(int i,int j)
{
    int linhas,colunas;
    struct Alunos **lista = (struct Alunos**) malloc(i * sizeof(struct Alunos*));
    for(linhas=0;linhas<i;linhas++)
    {
        lista[linhas]=(struct Alunos*)malloc(j * sizeof(struct Alunos));
    }
    return lista;
}
void InsereAluno(struct Alunos **lista,int i,int j,struct Alunos aux)
{
    lista[i][j].cpf = aux.cpf;
    lista[i][j].matricula = aux.matricula;
    strcpy(lista[i][j].nome,aux.nome);
}
void Imprime(struct Alunos **lista,int tamanho)
{
    int i,j;
    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            printf("Aluno:%s matricula:%d CPF:%d ",lista[i][j].nome,lista[i][j].matricula,lista[i][j].cpf);
        }
        printf("\n");
    }
}
int main()
{
    int tamanho,i,j;
    struct Alunos **listaAlunos,auxiliar;
    scanf("%d",&tamanho);
    listaAlunos = Alocalista(tamanho,tamanho);
    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            gets(auxiliar.nome);
            scanf("%d %d",&auxiliar.nome,&auxiliar.matricula,&auxiliar.cpf);
            InsereAluno(listaAlunos,i,j,auxiliar);
        }
    }
    Imprime(listaAlunos,tamanho);
free(listaAlunos);
return 0;
}
