#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1
#define EN_CURSO 0

static int buscarLugarLibre(Llamada* arrayLlamadas,int limite);
static int proximoId();

int llamada_init(Llamada* arrayLlamadas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            arrayLlamadas[i].isEmpty = 1;
        }
    }
    return retorno;
}

int llamada_buscarPorId(Llamada* arrayLlamadas,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayLlamadas[i].isEmpty == OCUPADO && arrayLlamadas[i].idLlamada == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int llamada_baja(Llamada* arrayLlamadas,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = llamada_buscarPorId(arrayLlamadas,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        arrayLlamadas[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int llamada_mostrar(Llamada* arrayLlamadas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!arrayLlamadas[i].isEmpty)
            {
               printf("\n[RELEASE] %d - %d - %d -%d ",arrayLlamadas[i].idAbonado,arrayLlamadas[i].idEstado,arrayLlamadas[i].idLlamada,arrayLlamadas[i].isEmpty);
            }
        }
    }
    return retorno;
}

int llamada_mostrarDebug(Llamada* arrayLlamadas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
             printf("\n[RELEASE] %d - %d - %d -%d ",arrayLlamadas[i].idAbonado,arrayLlamadas[i].idEstado,arrayLlamadas[i].idLlamada,arrayLlamadas[i].isEmpty);
        }
    }
    return retorno;
}


int llamada_alta(Llamada* arrayLlamadas,int limite)
{
    int retorno = -1;
    int idAbonado;
    int idMotivo;
    int id;
    int indice;

    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(arrayLlamadas,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidInt("\nID usuario:","Error", &idAbonado,0,limite,2))
            {
                if(!getValidInt("\nMotivo: ","Error", &idMotivo,1,3,2))
                {
                    retorno = 0;
                    arrayLlamadas[indice].idLlamada = id;
                    arrayLlamadas[indice].isEmpty = OCUPADO;
                    arrayLlamadas[indice].idEstado = EN_CURSO;
                }
            }
        }
    }
    return retorno;
}


/*
int llamada_modificacion(Llamada* arrayLlamadas,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];
    indice = llamada_buscarPorId(arrayLlamadas,limite,id);
    if(indice >= 0)
    {
        retorno = -2;
        if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
        {
            retorno = 0;
            strcpy(arrayLlamadas[indice].nombre,nombre);
        }


    }
    return retorno;
}
*/

static int buscarLugarLibre(Llamada* arrayLlamadas,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(arrayLlamadas[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}


/*
int llamada_ordenar(Llamada* arrayLlamadas,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Llamada auxiliar;

    if(limite > 0 && arrayLlamadas != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                    if(arrayLlamadas[i].isEmpty == OCUPADO && arrayLlamadas[i+1].isEmpty == OCUPADO )
                    {
                        if((strcmp(arrayLlamadas[i].nombre,arrayLlamadas[i+1].nombre) > 0 && !orden) || (strcmp(arrayLlamadas[i].nombre,arrayLlamadas[i+1].nombre) < 0 && orden)) //<------------
                        {
                            auxiliar = arrayLlamadas[i];
                            arrayLlamadas[i] = arrayLlamadas[i+1];
                            arrayLlamadas[i+1] = auxiliar;
                            flagSwap = 1;
                        }
                    }
            }
        }while(flagSwap);
    }

    return retorno;
}


*/






































