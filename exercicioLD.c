#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"
int main()
{
    listaD lista;
    int opcao=0,valor;
    InicializaLista(&lista);
        printf("DIGITE 1 PARA INSERIR NO FINAL \nDIGITE 2 PARA INSERIR NO INICIO:\nDIGITE 3 PARA BUSCAR UM VALOR NA LISTA\n");
        printf("DIGITE 4 PARA REMOVER O PRIMEIRO ELEMENTO\nDIGITE 5 PARA REMOVER NO FINAL\nDIGITE 6 PARA REMOVER EM LOCAL BUSCADO\n");
    while(opcao!=-1)
    {
        scanf("%d",&opcao);
        if(opcao==-1)
            break;
        printf("DIGITE O VALOR A SER INSERIDO\n");
        scanf("%d",&valor);
        if(opcao==1)
            InsereElementoFinal(&lista,valor);
        else if (opcao==2)
            InsereElementoInicio(&lista,valor);
        else if(opcao==3)
            Busca(&lista,valor);
        else if(opcao==4)
            RemoveInicio(&lista);
        else if(opcao==5)
            RemoveFinal(&lista);
        else if(opcao==6)
            RemoveLD(&lista,Busca2(&lista,valor));
    ImprimeLista(&lista,lista.primeiro);

    }
    ImprimeLista(&lista,lista.primeiro);
    Esvazia(&lista);
return 0;
}
