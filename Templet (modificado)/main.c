#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "abonado.h"
#include "llamada.h"
#include "utn.h"
#define QTY 10
#define QTY_Llamada 1000

int main()
{
    Abonado array[QTY];
    Llamada arrayLlamada [QTY_Llamada];
    int menu;
    int auxiliarId;

    abonado_init(array,QTY);
    do
    {
        getValidInt("\n1.Alta Abonado\n2.Baja Abonado\n3.Modificar Abonado\n4.Mostrar Abonado\n5.Ordenar Abonado\n6.Mostrar Debug\n7.Nueva Lamada\n8.Informe Llamada\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                abonado_alta(array,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                abonado_baja(array,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                abonado_modificacion(array,QTY,auxiliarId);
                break;
            case 4:
                abonado_mostrar(array,QTY);
                break;
            case 5:
                abonado_ordenar(array,QTY,0);
                break;
            case 6:
                abonado_mostrarDebug(array,QTY);
                break;
            case 7:


                break;
        }

    }while(menu != 9);

    return 0;
}
