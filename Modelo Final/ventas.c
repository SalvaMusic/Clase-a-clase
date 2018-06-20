#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ventas.h"
#include "utn.h"

/*

Ventas* ventas_new(void)
{
    Ventas* returnAux = NULL;
    returnAux = (Ventas*) malloc(sizeof(Ventas));
    return returnAux;

}*/
/*
Ventas* ventas_newParametrosString(char* strId,char* strNombre,char* strApellido,char* strEmail,char* strGenero,char* strProfesion,char* strUsuario,char* strNacionalidad)
{
    Ventas* this = ventas_new();;
    int id;

    id = atoi(strId);
    ventas_setId(this,id);


    return this;
}
*//*
void ventas_delete(Ventas* this)
{
    if(this != NULL)
        free(this);
}


int ventas_setId(Ventas* this, int id)
{
    static int ultimoId = -1;
    int retorno=-1;
    if(this != NULL)
    {
        retorno = 0;
        if(id > 0)
        {
            this->id = id;
            if(id > ultimoId)
                ultimoId = id;
        }
        else
        {
            ultimoId++;
            this->id =  ultimoId;
        }
    }
    return retorno;
}

int ventas_getId(Ventas* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}



int ventas_ordenarNombreApellido(void* ventasA,void* ventasB)
{
    char nombreA[64];
    char nombreB[64];
    int retorno;
    ventas_getNombre(ventasA,nombreA);
    ventas_getNombre(ventasB,nombreB);
    retorno = strcmp(nombreA,nombreB);
    if(!retorno)
    {
        char apellidoA[64];
        char apellidoB[64];
        ventas_getApellido(ventasA,apellidoA);
        ventas_getApellido(ventasB,apellidoB);
        retorno = strcmp(apellidoA,apellidoB);
    }
    return retorno;
}

*/
