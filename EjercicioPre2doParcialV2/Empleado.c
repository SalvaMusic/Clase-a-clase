#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);


Empleado* empleado_new(void)
{
    Empleado* returnAux;
    returnAux = (Empleado*) malloc(sizeof(Empleado));
    return returnAux;

}

Empleado* empleado_newParametrosString(char* id,char* strNombre,char* strHorasTrabajadas)
{
    Empleado* this = empleado_new();;
    int idEmpleado;
    int horasTrabajadas;
    idEmpleado = atoi(id);
    horasTrabajadas = atoi(strHorasTrabajadas);
        empleado_setId(this,idEmpleado);
        empleado_setNombre(this,strNombre);
        empleado_setHorasTrabajadas(this,horasTrabajadas);

    return this;
}

void empleado_delete(Empleado* this)
{
    if(this != NULL)
        free(this);
}



int empleado_setId(Empleado* this, int id)
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

int empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int empleado_setNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
            retorno = 0;
            strcpy(this->nombre,nombre);
    }
    return retorno;
}

int empleado_setHorasTrabajadas(Empleado* this, int horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas))
    {
            retorno = 0;
            this->horasTrabajadas = horasTrabajadas;
    }
    return retorno;
}

int empleado_setSueldo(Empleado* this, int sueldo)
{
    int retorno=-1;
    if(this != NULL )
    {
            retorno = 0;
            this->sueldo = sueldo;
    }
    return retorno;
}

int empleado_getSueldo(Empleado* this, int* sueldo)
{
    int retorno=-1;
    if(this != NULL && sueldo != NULL)
    {
            retorno = 0;
            *sueldo = this->sueldo;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this, int* horasTrabajadas)
{
    int retorno=-1;
    if(this != NULL && horasTrabajadas != NULL)
    {
            retorno = 0;
            *horasTrabajadas = this->horasTrabajadas;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* nombre)
{
    int retorno=-1;
    if(this != NULL && nombre != NULL)
    {
            retorno = 0;
            strcpy(nombre,this->nombre);
    }
    return retorno;
}

int empleado_calcularSueldo(void* this)
{
    int retorno = -1;
    int horasTrabajadas;
    int sueldo = 0;

    if (this != NULL)
    {
        retorno = 0;
        empleado_getHorasTrabajadas(this, &horasTrabajadas);
        if (horasTrabajadas < 120)
        {
            sueldo = horasTrabajadas * 180;
        }else if (horasTrabajadas < 160)
        {
            sueldo = horasTrabajadas * 240;
        }else
        {
            sueldo = horasTrabajadas * 350;
        }
        empleado_setSueldo(this,sueldo);
    }
    return retorno;
}
static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidHorasTrabajadas(int horasTrabajadas)
{
    return 1;
}


