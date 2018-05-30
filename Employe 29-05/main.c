#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    FILE* pFile;
    ArrayList* pArrayEmpleados;
    Employee* auxiliarEmpleado;
    int i;
    pArrayEmpleados = al_newArrayList();
    pFile = fopen("data.csv","r");
    parserEmployee(pFile,pArrayEmpleados);


    al_sort(pArrayEmpleados,employee_compare,0);
    for(i = 0; i < al_len(pArrayEmpleados);i++)
    {
        auxiliarEmpleado = (Employee*) al_get(pArrayEmpleados,i);
        employee_print(auxiliarEmpleado);
    }




    return 0;
}
