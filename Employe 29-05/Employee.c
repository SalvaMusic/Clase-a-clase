#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

static int isValidName(char* name);
static int isValidLastName(char* lastName);
static int isValidIsEmpty(int isEmpty);


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    char nameA[51];
    char nameB[51];
    int retorno;
    employee_getName(pEmployeeA,nameA);
    employee_getName(pEmployeeB,nameB);
    retorno = strcmp(nameA,nameB);
    if(!retorno)
    {
        char lastNameA[51];
        char lastNameB[51];
        employee_getLastName(pEmployeeA,lastNameA);
        employee_getLastName(pEmployeeB,lastNameB);
        retorno = strcmp(lastNameA,lastNameB);
    }
    return retorno;
}


void employee_print(Employee* this)
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;
    employee_getName(this,name);
    employee_getLastName(this,lastName);
    employee_getId(this,&id);
    employee_getIsEmpty(this,&isEmpty);
    printf("\nNombre: %s -Apellido %s - Id: %d - IsEmpty: %d",name,lastName,id,isEmpty);
}


Employee* employee_new(void)
{
    Employee* returnAux = NULL;
    returnAux = (Employee*) malloc(sizeof(Employee));
    return returnAux;

}

Employee* employee_newParametrosString(char* strId,char* strName, char* strLastName, char* strIsEmpty)
{
    Employee* this;
    int id; // FALTA VALIDAR
    int isEmpty = 0;

    id = atoi(strId); // FALTA VALIDAR
    if(!strcmp(strIsEmpty,"true"))
        isEmpty = 1;

    this = employee_new();
    employee_setId(this,id);
    employee_setIsEmpty(this,isEmpty);
    employee_setName(this,strName);
    employee_setLastName(this,strLastName);
    return this;
}



void employee_delete(Employee* this)
{
    if(this != NULL)
        free(this);
}


int employee_setId(Employee* this, int id)
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

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int employee_setName(Employee* this, char* name)
{
    int retorno=-1;
    if(this != NULL && name != NULL && isValidName(name))
    {
            retorno = 0;
            strcpy(this->name,name);
    }
    return retorno;
}

int employee_getName(Employee* this, char* name)
{
    int retorno=-1;
    if(this != NULL && name != NULL)
    {
            retorno = 0;
            strcpy(name,this->name);
    }
    return retorno;
}

int employee_setLastName(Employee* this, char* lastName)
{
    int retorno=-1;
    if(this != NULL && lastName != NULL && isValidLastName(lastName))
    {
            retorno = 0;
            strcpy(this->lastName,lastName);
    }
    return retorno;
}

int employee_getLastName(Employee* this, char* lastName)
{
    int retorno=-1;
    if(this != NULL && lastName != NULL)
    {
            retorno = 0;
            strcpy(lastName,this->lastName);
    }
    return retorno;
}

int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int retorno=-1;
    if(this != NULL && isValidIsEmpty(isEmpty))
    {
        retorno = 0;
        this->isEmpty = isEmpty;
    }
    return retorno;
}

int employee_getIsEmpty(Employee* this,int* isEmpty)
{
    int retorno=-1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

static int isValidName(char* name)
{
    return 1;
}

static int isValidLastName(char* lastName)
{
    return 1;
}

static int isValidIsEmpty(int isEmpty)
{
    return 1;
}

