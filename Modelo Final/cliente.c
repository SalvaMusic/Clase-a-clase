#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidDni(char* dni);

Cliente* cliente_new(void)
{
    Cliente* returnAux = NULL;
    returnAux = (Cliente*) malloc(sizeof(Cliente));
    return returnAux;

}

Cliente* cliente_newParametrosString(int id,char* strNombre,char* strApellido,char* strDni)
{
    Cliente* this = cliente_new();;

    cliente_setId(this,id);
    cliente_setNombre(this,strNombre);
    cliente_setApellido(this,strApellido);
    cliente_setDni(this,strDni);
    return this;
}
int cliente_setParametros(char* nombre,char* apellido,char* dni)
{
    int retorno = -1;
    int exito;
    exito = getValidString("Nombre: ","\nCaracteres Invalidos!\n","\nDemasiados Caracteres\n", nombre,64,2);
    if(!exito)
    {
        exito = getValidString("Apellido: ","\nCaracteres Invalidos!\n","\nDemasiados Caracteres\n", apellido,64,2);
        if(!exito)
        {
            exito =  getStringNumeros("DNI: ", dni);
            if(!exito)
            {
                retorno = 0;
            }
        }
    }
    return retorno;
}
void cliente_delete(Cliente* this)
{
    if(this != NULL)
        free(this);
}



int cliente_setId(Cliente* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
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

int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
            retorno = 0;
            strcpy(this->nombre,nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this != NULL && apellido != NULL && isValidApellido(apellido))
    {
            retorno = 0;
            strcpy(this->apellido,apellido);
    }
    return retorno;
}

int cliente_setDni(Cliente* this, char* dni)
{
    int retorno=-1;
    if(this != NULL && dni != NULL && isValidDni(dni))
    {
            retorno = 0;
            strcpy(this->dni,dni);
    }
    return retorno;
}



int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
            retorno = 0;
            strcpy(nombre,this->nombre);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno=-1;
    if(this != NULL && apellido != NULL)
    {
            retorno = 0;
            strcpy(apellido,this->apellido);
    }
    return retorno;
}

int cliente_getDni(Cliente* this, char* dni)
{
    int retorno=-1;
    if(this != NULL && dni != NULL)
    {
            retorno = 0;
            strcpy(dni,this->dni);
    }
    return retorno;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidApellido(char* apellido)
{
    return 1;
}

static int isValidDni(char* dni)
{
    return 1;
}


int cliente_ordenarApellidoNombre(void* clienteA,void* clienteB)
{
    int retorno;
    char apellidoA[64];
    char apellidoB[64];

    cliente_getApellido(clienteA,apellidoA);
    cliente_getApellido(clienteB,apellidoB);
    retorno = strcmp(apellidoA,apellidoB);

    if(!retorno)
    {
        char nombreA[64];
        char nombreB[64];
        cliente_getNombre(clienteA,nombreA);
        cliente_getNombre(clienteB,nombreB);
        retorno = strcmp(nombreA,nombreB);
    }
    return retorno;
}
