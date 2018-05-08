#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "utn.h"
#include "Pantalla.h"


int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas, char* cuit)
{
    int retorno = -1;
    int i;
    int indexPantalla;

    if (arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        retorno = -1;
        for(i=0;i<limite;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(cuit,arrayC[i].cuit))
            {
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("ID: %d - Dias %d - Precio: %.2f\n", arrayC[i].id, arrayC[i].dias, arrayC[i].dias * pantallas[indexPantalla].precio);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int informar_ListarContrataciones(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    int indexPantalla;

    if (arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        for(i=0;i<limite;i++)
        {
            if (!arrayC[i].isEmpty)
            {
                retorno = 0;
                indexPantalla = pantalla_buscarPorId(pantallas,lenPantallas,arrayC[i].idPantalla);
                printf("Nombre: %s - Video: %s - Dias: %d - Cuit: %s \n", pantallas[indexPantalla].nombre, arrayC[i].archivo, arrayC[i].dias, arrayC[i].cuit);
            }
        }
    }
    return retorno;
}


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    char ultimoCuit [50]= "-";
    int cantContrataciones=0;
    float importeGastado=0.00;
    float importeTotal=0.00;
    int indexPantalla;
    int flag=0;

    if (arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        retorno = -3;
        cont_ordenarCuit(arrayC,limite,1);
        for(i=0;i<limite;i++)
        {
            if (!arrayC[i].isEmpty && strcmp(arrayC[i].cuit,ultimoCuit) && flag)
            {
                strcpy(ultimoCuit,arrayC[i].cuit);
                printf("\nINFO DEL CUIT: %s \n", ultimoCuit);
                printf("\n Importe Gastado: %.2f \tContrataciones: %d \n", importeTotal, cantContrataciones);
                cantContrataciones=0;
                importeGastado = 0.00;
                importeTotal = 0.00;
            }
                flag=1;
                cantContrataciones++;
                importeGastado = arrayC[i].dias*pantallas[indexPantalla].precio;
                importeTotal=importeTotal+importeGastado;


        }
    }
    return retorno;
}
/*
int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,Pantalla* pantallas, int lenPantallas)
{
    int retorno = -1;
    int i;
    char ultimoCuit [50]= "-";

    if (arrayC != NULL && pantallas != NULL && limite > 0 && lenPantallas > 0)
    {
        retorno = -3;
        cont_ordenarCuit(arrayC,limite,0);
        for(i=0;i<limite;i++)
        {
            if (!arrayC[i].isEmpty && strcmp(arrayC[i].cuit,ultimoCuit))
            {
                strcpy(ultimoCuit,arrayC[i].cuit);
                printf("\nINFO DEL CUIT: %s ", ultimoCuit);




            }
        }
    }
    return retorno;
}

*/
