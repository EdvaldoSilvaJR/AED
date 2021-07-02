#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *arquivo;
    char texto[100];
    /*scanf("%s",&texto);
    arquivo=fopen("teste.txt","w");
    fputs(texto,arquivo);
    fclose(arquivo);
    */
    arquivo=fopen("teste.txt","r");
    fgets(texto,100,arquivo);
    printf("%s",texto);
    fclose(arquivo);
return 0;
}
