#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"


Alumno* alumno_new()
{
    return malloc(sizeof(Alumno));
}

void alumno_delete(Alumno* this)
{
    free(this);
}

int alumno_setEdad(Alumno* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        retorno = 0;
        this->edad = edad;
    }
    return retorno;
}

int alumno_setNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int alumno_setApellido(Alumno* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(this->apellido, apellido);
        retorno = 0;
    }
    return retorno;
}

int alumno_getEdad(Alumno* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }
    return retorno;
}

int alumno_getNombre(Alumno* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}


int alumno_getApellido(Alumno* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        retorno = 0;
        strcpy(apellido,this->apellido);
    }
    return retorno;
}

