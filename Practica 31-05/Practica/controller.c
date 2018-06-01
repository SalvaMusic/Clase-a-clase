#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "ArrayList.h"

int controller_leerArchivo(char* path,ArrayList* pArrayClientes)
{
    FILE* pFile;
    Cliente* pAuxiliarCliente;
    int retorno = -1;

    char bNombre[4096];
    char bApellido[4096];
    char bEmail[4096];
    char bGenero[4096];
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bId[4096];
    char bUsuario[4096];

    pFile = fopen(path,"r");
    if(pFile != NULL)
    {

        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);
            pAuxiliarCliente = cliente_newParametrosString(bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);
            al_add(pArrayClientes,pAuxiliarCliente);
        }
    }

    return retorno;
}
int controller_listarArchivo(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int i;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[10];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;

    for(i=0;i<al_len(pArrayClientes);i++)
    {
        auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getId(auxiliarCliente,&id);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        cliente_getEmail(auxiliarCliente,email);
        cliente_getGenero(auxiliarCliente,genero);
        cliente_getProfesion(auxiliarCliente,profesion);
        cliente_getNacionalidad(auxiliarCliente,nacionalidad);
        cliente_getUsuario(auxiliarCliente,usuario);
        printf("\n%d - %s - %s- %s- %s- %s- %s- %s\n",id,nombre,apellido,email,genero,profesion,nacionalidad,usuario);
    }


    return retorno;
}

int controller_guardarClientesArchivo(ArrayList* pArrayClientes,char* path)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int i;
    char nombre[64];
    char apellido[64];
    char email[256];
    char genero[10];
    char profesion[256];
    char nacionalidad[256];
    char usuario[64];
    int id;

    FILE* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,apellido,email,genero,profesion,nacionalidad,usuario\n");
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            auxiliarCliente = al_get(pArrayClientes,i);
            cliente_getId(auxiliarCliente,&id);
            cliente_getNombre(auxiliarCliente,nombre);
            cliente_getApellido(auxiliarCliente,apellido);
            cliente_getEmail(auxiliarCliente,email);
            cliente_getGenero(auxiliarCliente,genero);
            cliente_getProfesion(auxiliarCliente,profesion);
            cliente_getNacionalidad(auxiliarCliente,nacionalidad);
            cliente_getUsuario(auxiliarCliente,usuario);
            fprintf(pFile,"\n%d - %s - %s- %s- %s- %s- %s- %s",id,nombre,apellido,email,genero,profesion,nacionalidad,usuario);
        }
    }
    fclose(pFile);
    return retorno;
}

int controller_ordenarArchivoNombreApellido(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarNombreApellido,1);
    }
    return retorno;
}

int controller_ordenarEmail(ArrayList* pArrayClientes)
{
    int retorno = -1;
    if(pArrayClientes != NULL)
    {
        retorno = 0;
        al_sort(pArrayClientes,cliente_ordenarEmail,1);
    }
    return retorno;
}

int controller_modificar(ArrayList* pArrayClientes)
{
    Cliente* auxiliarCliente;
    int retorno = -1;
    int id;
    char nombre[64];
    char apellido[64];
    char email[256];

    getValidInt("\nIngrese el ID: ","\nIngrese un caracter valido!",&id,0,1000,2);


       /* auxiliarCliente = al_get(pArrayClientes,i);
        cliente_getNombre(auxiliarCliente,nombre);
        cliente_getApellido(auxiliarCliente,apellido);
        cliente_getEmail(auxiliarCliente,email);*/
    return retorno;

}

