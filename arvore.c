#include<stdio.h>
#include<stdlib.h>

//----------------------------------------STRUCT----------------------------------------
struct NOarvore
{
    struct NOarvore *esquerda;
    struct NOarvore *direita;
    char info;
};

typedef struct NOarvore Arvore;
//----------------------------------------FUNCOES----------------------------------------

void Inicializa(Arvore *arvoreaux,char info)
{
    arvoreaux->info=info;
    arvoreaux->esquerda=NULL;
    arvoreaux->direita=NULL;
}

Arvore *InsereNo(char info)
{
    Arvore *novo;
    novo=(Arvore*)malloc(sizeof(Arvore));
    novo->info=info;
    novo->direita=NULL;
    novo->esquerda=NULL;
    return novo;
}


int main()
{
    int vezes,i;
    char valor;
    Arvore PaiArvore,*aux;
    Inicializa(&PaiArvore);
    scanf("%d",&vezes);
    aux=&PaiArvore;
    for(i=0;i<vezes;i++)
    {
        scanf("%c",&valor);
        if(aux.direita==NULL)
            aux.direita=InsereNo(valor);
        else if(aux.esquerda==NULL)
            aux.esquerda=InsereNo(valor);
        else if((aux.direita.direita==NULL)||(aux.direita.esquerda==NULL))
            {
                aux=aux.direita;
                aux.direita
            }

    }

}
