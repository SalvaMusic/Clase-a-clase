#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define QTY 10

int main()
{
    Fantasma array[QTY];
    int menu;
    int auxiliarId;

    fantasma_init(array,QTY);

    /*fantasma_altaForzada(array,QTY,"Esteban");
    fantasma_altaForzada(array,QTY,"Juan");
    fantasma_altaForzada(array,QTY,"Gustavo");
    fantasma_altaForzada(array,QTY,"Elias");*/
    do
    {
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                printf("\nALTA:");
                fantasma_alta(array,QTY);
                break;
            case 2:
                printf("\nBAJAR:");
                getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                fantasma_baja(array,QTY,auxiliarId);
                break;
            case 3:
                printf("\nMODIFICAR:");
                fantasma_mostrar(array,QTY);
                getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                fantasma_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                printf("\nMOSTRAR:");
                fantasma_mostrar(array,QTY);
                break;
            case 5:
                printf("\nORDENAR:");
                fantasma_ordenar(array,QTY,0);
                break;
            case 6:
                printf("\nMOSTRAR DEBUG:");
                fantasma_mostrarDebug(array,QTY);
                break;
        }

    }while(menu != 9);

    return 0;
}
