#include <stdio.h>
#include <stdlib.h>

void Imprimevetor(float *aluno,int tamanho)
{
    int cont;
    for(cont=0;cont<tamanho;cont++)
    {
        printf("%f \n",aluno[cont]);
    }
}
float media(float *aluno,int tamanho)
{
    float total;
    int cont;
    for(cont=0;cont<tamanho;cont++)
    {
        printf("nota selecionada: %f \n",aluno[cont]);
        total=total+aluno[cont];
    }
    total=total/tamanho;
    return total;
}
int main()
{
    float nota, *aluno;
    int i=0;
    aluno =(float*) malloc(sizeof(float));
    do
    {
        scanf("%f",&nota);
        if(nota>0)
        {
            aluno[i]=nota;
            i++;
            aluno = realloc(aluno,sizeof(float));
        }

    }while(nota>0);
    nota = media(aluno,i);
    //Imprimevetor(aluno,i);
    printf("MEDIA DO ALUNO: %.2f ",nota);
    free(aluno);
return 0;
}
