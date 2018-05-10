#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "gasper.h"
#include "fantasma.h"
#include "utn.h"
#include "informe.h"
#define QTY 10

int main()
{
    Fantasma arrayFantasma[QTY];
    Gasper arrayGasper[QTY];
    int menu;
    int auxiliarId;

    gasper_init(arrayGasper,QTY);
    fantasma_init(arrayFantasma,QTY);
/*
    fantasma_altaForzada(arrayFantasma,QTY,"Salvador");
    fantasma_altaForzada(arrayFantasma,QTY,"Gustavo");
    fantasma_altaForzada(arrayFantasma,QTY,"Yesica");

    gasper_altaForzada(arrayGasper,QTY,"Galletitas",15.50,15,0);
    gasper_altaForzada(arrayGasper,QTY,"Harina",20,25,1);
    gasper_altaForzada(arrayGasper,QTY,"Jugo",16,30,0);
    gasper_altaForzada(arrayGasper,QTY,"Fideos",15.5,65,2);
*/

    do
    {
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                printf("\nALTA:");
                break;
            case 2:
                printf("\nBAJAR:");
                //getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                break;
            case 3:
                printf("\nMODIFICAR:");
                gasper_mostrar(arrayGasper,QTY);
                getValidInt("\nIngrese ID: ","\nNumero invalido\n",&auxiliarId,0,200,2);
                gasper_modificacionCase(arrayGasper,QTY,auxiliarId);
                break;
            case 4:
                printf("\nINFORMAR:");
                informe_totalPromedioImporteSuprPromedio(arrayGasper,QTY);
                informe_totalPromedioImporteInfPromedio(arrayGasper,QTY);
                informe_cantidadProdMenorCantidad(arrayGasper,QTY);
                informe_cantidadProdMayorCantidad(arrayGasper,QTY);

                break;
            case 5:
                printf("\nLISTAR:");
                informe_listarGaspersOrden(arrayGasper,QTY);
                informe_listarProdMayorCantidad(arrayGasper,QTY);
                informe_listarProdMenorCantidad(arrayGasper,QTY);

                break;
            case 6:
                printf("\nMOSTRAR DEBUG:");
                break;
        }

    }while(menu != 9);

    return 0;
}
