#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"

static int isValidNombre(char* nombre);
static int isValidApellido(char* apellido);
static int isValidGenero(char* genero);
static int isValidNacionalidad(char* nacionalidad);
static int isValidProfesion(char* profesion);
static int isValidEmail(char* email);
static int isValidUsuario(char* usuario);

Cliente* cliente_new(void)
{
    Cliente* returnAux = NULL;
    returnAux = (Cliente*) malloc(sizeof(Cliente));
    return returnAux;

}

Cliente* cliente_newParametrosString(char* strId,char* strNombre,char* strApellido,char* strEmail,char* strGenero,char* strProfesion,char* strUsuario,char* strNacionalidad)
{
    Cliente* this = cliente_new();;
    int id;

    id = atoi(strId);
    cliente_setId(this,id);
    cliente_setNombre(this,strNombre);
    cliente_setApellido(this,strApellido);
    cliente_setEmail(this,strEmail);
    cliente_setGenero(this,strGenero);
    cliente_setProfesion(this,strProfesion);
    cliente_setUsuario(this,strUsuario);
    cliente_setNacionalidad(this,strNacionalidad);

    return this;
}

void cliente_delete(Cliente* this)
{
    if(this != NULL)
        free(this);
}


int cliente_setId(Cliente* this, int id)
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

int cliente_setEmail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
            retorno = 0;
            strcpy(this->email,email);
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char* genero)
{
    int retorno=-1;
    if(this != NULL && genero != NULL && isValidGenero(genero))
    {
            retorno = 0;
            strcpy(this->genero,genero);
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this != NULL && profesion != NULL && isValidProfesion(profesion))
    {
            retorno = 0;
            strcpy(this->profesion,profesion);
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this != NULL && nacionalidad != NULL && isValidNacionalidad(nacionalidad))
    {
            retorno = 0;
            strcpy(this->nacionalidad,nacionalidad);
    }
    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this != NULL && usuario != NULL && isValidUsuario(usuario))
    {
            retorno = 0;
            strcpy(this->usuario,usuario);
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

int cliente_getEmail(Cliente* this, char* email)
{
    int retorno=-1;
    if(this != NULL && email != NULL)
    {
            retorno = 0;
            strcpy(email,this->email);
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char* genero)
{
    int retorno=-1;
    if(this != NULL && genero != NULL)
    {
            retorno = 0;
            strcpy(genero,this->genero);
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno=-1;
    if(this != NULL && profesion != NULL)
    {
            retorno = 0;
            strcpy(profesion,this->profesion);
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno=-1;
    if(this != NULL && nacionalidad != NULL)
    {
            retorno = 0;
            strcpy(nacionalidad,this->nacionalidad);
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno=-1;
    if(this != NULL && usuario != NULL)
    {
            retorno = 0;
            strcpy(usuario,this->usuario);
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

static int isValidUsuario(char* usuario)
{
    return 1;
}

static int isValidGenero(char* genero)
{
    return 1;
}

static int isValidEmail(char* email)
{
    return 1;
}

static int isValidNacionalidad(char* nacionalidad)
{
    return 1;
}

static int isValidProfesion(char* profesion)
{
    return 1;
}

int cliente_ordenarNombreApellido(void* clienteA,void* clienteB)
{
    char nombreA[64];
    char nombreB[64];
    int retorno;
    cliente_getNombre(clienteA,nombreA);
    cliente_getNombre(clienteB,nombreB);
    retorno = strcmp(nombreA,nombreB);
    if(!retorno)
    {
        char apellidoA[64];
        char apellidoB[64];
        cliente_getApellido(clienteA,apellidoA);
        cliente_getApellido(clienteB,apellidoB);
        retorno = strcmp(apellidoA,apellidoB);
    }
    return retorno;
}

int cliente_ordenarEmail(void* clienteA,void* clienteB)
{
    char emailA[64];
    char emailB[64];

    cliente_getEmail(clienteA,emailA);
    cliente_getEmail(clienteB,emailB);

    return strcmp(emailA,emailB);
}
