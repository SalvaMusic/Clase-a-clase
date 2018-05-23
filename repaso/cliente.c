#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

static int cliente_setId(Cliente* this);

Cliente* cliente_new()
{
    return (Cliente*) malloc(sizeof(Cliente));
}

Cliente* cliente_new2(char* nombre, char* apellido, char* cuit, int edad)
{
    Cliente* retorno = cliente_new();

    cliente_setNombre(retorno, nombre);
    cliente_setApellido(retorno, apellido);
    cliente_setCuit(retorno, cuit);
    cliente_setEdad(retorno, edad);
    cliente_setId(retorno);

    return retorno;
}

int cliente_alta(int *cantidad,Cliente *listado[])
{
    listado [*cantidad] = cliente_new2("Salvador", "Pedrozo", "1245158448",25);
    *cantidad = (*cantidad)+1;
}

int cliente_listar(int cantidad,Cliente *listado[])
{
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int edad;

    printf("Nombre - \tApellido - \t Cuit - \tEdad");
    for(i=0;i<cantidad;i++)
    {
        cliente_getNombre((*(listado+i)),nombre);
        cliente_getApellido((*(listado+i)), apellido);
        cliente_getCuit((*(listado+i)),cuit);
        cliente_getEdad((*(listado+i)), &edad);

        printf("\n%s \t", nombre);
        printf("%s -\t", apellido);
        printf(" %s -\t", cuit);
        printf(" %d -", edad);

    }

    return 0;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_setCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strcpy(this->cuit, cuit);
        retorno = 0;
    }
    return retorno;
}

int cliente_setEdad(Cliente* this,int edad)
{
    int retorno = -1;
    if(this != NULL && !validarEdad(edad))
    {
        this->edad = edad;
        retorno = 0;

    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido,this->apellido);
    }
    return retorno;
}

int cliente_getCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        retorno = 0;
        strcpy(cuit,this->cuit);
    }
    return retorno;
}

int cliente_getEdad(Cliente* this,int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

int validarEdad(int edad)
{
    int retorno = -1;
    if (edad>=0 && edad<=200);
        retorno=0;

    return retorno;
}

static int cliente_setId(Cliente* this)
{
    int retorno = -1;
    static int ultimoId = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->idCliente = ultimoId;
        retorno = 0;
    }
    return retorno;
}
