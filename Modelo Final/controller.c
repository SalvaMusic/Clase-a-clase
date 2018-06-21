#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ArrayList.h"
#include "controller.h"

int controller_leerArchivoCliente(char* path,ArrayList* pArrayClientes)
{
    FILE* pFile;
    Cliente* pAuxiliarCliente;
    int retorno = -1;

    char bNombre[4096];
    char bApellido[4096];
    char bDni[4096];
    char bId[4096];
    int id;

    pFile = fopen(path,"r");
    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bDni);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bDni);
            id = atoi(bId);
            pAuxiliarCliente = cliente_newParametrosString(id,bNombre,bApellido,bDni);
            al_add(pArrayClientes,pAuxiliarCliente);
        }
    }
    fclose(pFile);

    return retorno;
}

int controller_altaCliente(ArrayList* pArrayClientes)
{
    Cliente* pAuxiliarCliente;
    int retorno = -1;

    char nombre[64];
    char apellido[64];
    char dni[14];

    if(pArrayClientes != NULL)
    {
        retorno = 0;
        cliente_setParametros(nombre,apellido,dni);
        pAuxiliarCliente = cliente_newParametrosString(-1,nombre,apellido,dni);
        al_add(pArrayClientes,pAuxiliarCliente);

    }
    return retorno;
}

int controller_listarCliente(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int i;
    char nombre[64];
    char apellido[64];
    char dni[14];
    int id;

    printf("\nID - Nombre - Apellido - DNI");
    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getId(auxiliarCliente,&id);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        cliente_getDni(auxiliarCliente,dni);
        printf("\n%d - %s - %s- %s",id,nombre,apellido,dni);
    }
    printf("\n");

    return retorno;
}

int controller_listarClienteApellidoNombre(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int i;
    char nombre[64];
    char apellido[64];
    char dni[14];
    int id;

    printf("\nID - Nombre - Apellido - DNI");

    controller_ordenarClienteApellidoNombre(pArrayClientes);
    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getId(auxiliarCliente,&id);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        cliente_getDni(auxiliarCliente,dni);
        printf("\n%d - %s - %s- %s",id,nombre,apellido,dni);
    }
    printf("\n");

    return retorno;
}


int controller_modificarCliente(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int id;
    int idCliente;
    char nombre[64];
    char apellido[64];
    char dni[14];
    int exito;
    int i;

    if (pArrayClientes != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);
        if (!exito)
        {
            for(i=0;i<al_len(pArrayClientes);i++)
            {
                auxiliarCliente = al_get(pArrayClientes,i);
                cliente_getId(auxiliarCliente,&idCliente);
                if(id == idCliente)
                {
                    cliente_setParametros(nombre,apellido,dni);
                    auxiliarCliente = cliente_newParametrosString(idCliente,nombre,apellido,dni);
                    al_set(pArrayClientes,i,auxiliarCliente);
                    retorno = 0;
                    break;
                }
            }
        }
    }

    return retorno;
}

int controller_bajaCliente(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int id;
    int idCliente;
    int exito;
    int i;

    if (pArrayClientes != NULL)
    {
        exito = getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);
        if (!exito)
        {
            for(i=0;i<al_len(pArrayClientes);i++)
            {
                auxiliarCliente = al_get(pArrayClientes,i);
                cliente_getId(auxiliarCliente,&idCliente);
                if(id == idCliente)
                {
                    retorno = 0;
                    al_remove(pArrayClientes,i);
                    break;
                }
            }
        }
    }

    return retorno;
}

int controller_guardarClienteArchivo(ArrayList* pArrayClientes,char* path)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int i;
    char nombre[64];
    char apellido[64];
    char dni[14];
    int id;

    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,apellido,dni\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            auxiliarCliente = al_get(pArrayClientes,i);
            cliente_getId(auxiliarCliente,&id);
            cliente_getNombre(auxiliarCliente,nombre);
            cliente_getApellido(auxiliarCliente,apellido);
            cliente_getDni(auxiliarCliente,dni);
            fprintf(pFile,"\n%d, %s, %s, %s",id,nombre,apellido,dni);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_ordenarClienteApellidoNombre(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarApellidoNombre,1);
    }
    return retorno;
}
