#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funciones.h"

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
   // fpurge(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 1)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}


int esEntero(char *str)
{
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        if(str[i] > '9' || str[i] < '0')
            return 0;
    }
    return 1;
}

/*
int emp_mostrar(Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(!arrayEmpleados[i].isEmpty)
            printf("\nNombre: %s - Id: %d - Index:%d",arrayEmpleados[i].nombre,arrayEmpleados[i].idEmpleado,i);
    }
    return 0;
}

int emp_len (Empleado* arrayEmpleados,int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(arrayEmpleados[i].isEmpty)
            break;
    }
    return i;
}

int emp_compactarArrayInsertion(Empleado * arrayEmpleado,int cantidad)
{
	Empleado auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = arrayEmpleado[i];
		j = i;
		while(j > 0 && auxiliar.isEmpty < arrayEmpleado[j - 1].isEmpty)
        {
			arrayEmpleado[j] = arrayEmpleado[j - 1];
			j--;
		}
		arrayEmpleado[j] = auxiliar;
	}
    return 0;
}

int emp_ordenarEmpleadoNombre(Empleado * arrayEmpleado,int cantidad)
{
	Empleado auxiliar;
    int j, i;

    emp_compactarArrayInsertion(arrayEmpleado,cantidad);
    cantidad = emp_len(arrayEmpleado,cantidad);

	for(i = 1; i < cantidad; i++) {
		auxiliar = arrayEmpleado[i];
		j = i;
		while(j > 0 && strcmp(auxiliar.nombre , arrayEmpleado[j - 1].nombre) > 0)
        {
			arrayEmpleado[j] = arrayEmpleado[j - 1];
			j--;
		}
		arrayEmpleado[j] = auxiliar;
	}
    return 0;
}



int ordenarArrayInt(int * array,int cantidad,int orden)
{
    int i;
    int flagSwap;
    int auxiliar;

    do
    {
        flagSwap = 0;
        for(i=0;i< cantidad-1;i++)
        {
            if((array[i]>array[i+1] && orden == 0) || (array[i]<array[i+1] && orden == 1))
            {
                auxiliar = array[i];
                array[i] = array[i+1];
                array[i+1] = auxiliar;
                flagSwap = 1;
            }

        }
    }while(flagSwap);

    return 0;
}

int mostrarArrayInt(int * array,int cantidad)
{
    int i;
    printf(" ------ ");
    for(i=0;i<cantidad;i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}

int ordenarArrayIntInsertion(int * array,int cantidad,int orden)
{
	int auxiliar;
    int j, i;

	for(i = 1; i < cantidad; i++) {
		auxiliar = array[i];
		j = i;
		while(j > 0 && auxiliar < array[j - 1])
        {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = auxiliar;
	}
    return 0;
}
*/



















