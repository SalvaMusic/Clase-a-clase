#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "informe.h"
#include "utn.h"
#include "gasper.h"
#include "fantasma.h"

int informe_listarProdMayorCantidad(Gasper* arrayGasper, int lenGasper)
{
    int i;
    int retorno = -1;
    int flag=0;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        printf("\n\n\tGaspers con Stock mayor a 10:");
        retorno = -2;
        for(i=0;i<lenGasper;i++)
        {
            if (!arrayGasper[i].isEmpty && arrayGasper[i].cantidad>10)
            {
                retorno=0;
                printf("\nDescripcion: %s - ID:%d - Precio: %.2f - Cantidad: %d",arrayGasper[i].nombre,arrayGasper[i].idGasper,arrayGasper[i].precio,arrayGasper[i].cantidad);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
    }
    return retorno;
}

int informe_listarProdMenorCantidad(Gasper* arrayGasper, int lenGasper)
{
    int i;
    int retorno = -1;
    int flag=0;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        printf("\n\n\tGaspers con Stock no mayor a 10:");
        retorno = -2;
        for(i=0;i<lenGasper;i++)
        {
            if (!arrayGasper[i].isEmpty && arrayGasper[i].cantidad<=10)
            {
                retorno=0;
                printf("\nDescripcion: %s - ID:%d - Precio: %.2f - Cantidad: %d\n",arrayGasper[i].nombre,arrayGasper[i].idGasper,arrayGasper[i].precio,arrayGasper[i].cantidad);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!\n");
        }
    }
    return retorno;
}

int informe_listarGaspersOrden(Gasper* arrayGasper,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(limite > 0 && arrayGasper != NULL)
    {
        retorno = 0;
        gasper_ordenarNombre(arrayGasper,limite,0);
        gasper_ordenarImporte(arrayGasper,limite,1);
        printf("\n\n\tGaspers ordenados:");

        for(i=0;i<limite;i++)
        {
            if(!arrayGasper[i].isEmpty)
            {
               printf("\nDescripcion: %s - ID:%d - Precio: %.2f - Cantidad: %d",arrayGasper[i].nombre,arrayGasper[i].idGasper,arrayGasper[i].precio,arrayGasper[i].cantidad);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
    }
    return retorno;
}

int informe_cantidadProdMenorCantidad(Gasper* arrayGasper, int lenGasper)
{
    int i;
    int retorno = -1;
    int contMenor = 0;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        retorno = -2;
        for(i=0;i<lenGasper;i++)
        {
            if (!arrayGasper[i].isEmpty && arrayGasper[i].cantidad<=10)
            {
                retorno=0;
                contMenor++;
            }
        }
        printf("\nGaspers que no superan 10 Stock: %d\n", contMenor);

    }
    return retorno;
}

int informe_cantidadProdMayorCantidad(Gasper* arrayGasper, int lenGasper)
{
    int i;
    int retorno = -1;
    int contMayor = 0;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        retorno = -2;
        for(i=0;i<lenGasper;i++)
        {
            if (!arrayGasper[i].isEmpty && arrayGasper[i].cantidad>10)
            {
                retorno=0;
                contMayor++;
            }
        }
        printf("\nGaspers que superan 10 Stock: %d\n", contMayor);

    }
    return retorno;
}


int informe_totalPromedioImporteInfPromedio(Gasper* arrayGasper, int lenGasper)
{
    int retorno = -1;
    int i;
    int contMinimoPromedio=0;
    float importeTotal;
    float promedioTotal;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        retorno = -2;
        gasper_importePromedioTotal(arrayGasper,lenGasper,&importeTotal,&promedioTotal);
        for(i=0;i<lenGasper;i++)
        {
            retorno=0;
            if (!arrayGasper[i].isEmpty && arrayGasper[i].precio<=promedioTotal)
            {
                contMinimoPromedio++;
            }
        }
        printf("\nImporte Total: %.2f",importeTotal);
        printf("\nPromedio Total: %.2f",promedioTotal);
        printf("\nCantidad Gaspers Inferior a Promedio Total: %d\n",contMinimoPromedio);
    }
    return retorno;
}

int informe_totalPromedioImporteSuprPromedio(Gasper* arrayGasper, int lenGasper)
{
    int retorno = -1;
    int i;
    int contMaximoPromedio=0;
    float importeTotal;
    float promedioTotal;

    if(arrayGasper!= NULL && lenGasper > 0)
    {
        retorno = -2;
        gasper_importePromedioTotal(arrayGasper,lenGasper,&importeTotal,&promedioTotal);
        for(i=0;i<lenGasper;i++)
        {
            retorno=0;
            if (!arrayGasper[i].isEmpty && arrayGasper[i].precio>promedioTotal)
            {
                contMaximoPromedio++;
            }
        }
        printf("\nImporte Total: %.2f",importeTotal);
        printf("\nPromedio Total: %.2f",promedioTotal);
        printf("\nCantidad Gaspers Superior a Promedio Total: %d\n",contMaximoPromedio);
    }
    return retorno;
}
