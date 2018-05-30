#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    //employee_newParametrosString
    int retorno = -1;
    Employee* auxiliarEmpleado;
    char id[4096];
    char name[4096];
    char lastName[4096];
    char isEmpty[4096];

    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);
            auxiliarEmpleado = employee_newParametrosString(id,name,lastName,isEmpty);
            al_add(pArrayListEmployee,auxiliarEmpleado);
        }
    }

    return retorno;
}
