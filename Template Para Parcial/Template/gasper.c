#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gasper.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Gasper* array,int limite);
static int proximoId();

int gasper_importePromedioTotal(Gasper* array,int limite,float *precioTotal,float *promedio)
{
    int retorno = -1;
    int i;
    int cantidad=0;
    float precio=0;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                retorno = 0;
                cantidad = cantidad+array[i].cantidad;
                precio = precio+(array[i].cantidad*array[i].precio);
            }
        }
        *promedio = precio/cantidad;
        *precioTotal = precio;
    }
    return retorno;
}

int gasper_promedioGasper(Gasper* array,int limite, int id,float *promedio)
{
    int retorno = -1;
    int indice;

    if(limite > 0 && array != NULL)
    {
        indice = gasper_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = 0;
            *promedio=array[indice].precio*array[indice].cantidad;
        }
    }
    return retorno;
}

int gasper_altaForzada(Gasper* array,int limite,char* nombre, float precio, int cantidad,int idFantasma)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            array[i].precio = precio;
            array[i].cantidad = cantidad;
            array[i].idFantasma =  idFantasma;
            //------------------------------
            //------------------------------*/
            array[i].idGasper = proximoId();
            array[i].isEmpty = OCUPADO;
        }
        retorno = 0;
    }
    return retorno;
}

int gasper_init(Gasper* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int gasper_buscarPorId(Gasper* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idGasper == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int gasper_baja(Gasper* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = gasper_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }else{
        printf("\nID no encontrado!");
    }
    return retorno;
}

int gasper_mostrar(Gasper* array,int limite)
{
    int retorno = -1;
    int i;
    int flag=0;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
               printf("\nNombre: %s - ID:%d - Precio: %.2f - Cantidad: %d",array[i].nombre,array[i].idGasper,array[i].precio,array[i].cantidad);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
    }
    return retorno;
}

int gasper_mostrarDebug(Gasper* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idGasper,array[i].isEmpty);
        }
    }
    return retorno;
}

int gasper_alta(Gasper* array,int limite,int idFantasma)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;
    float precio;
    int cantidad;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;

            id = proximoId();
            if(!getValidString("\nIngrese Descripcion: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2))
            {
                if(!getValidFloat("\nIngrese Precio: ", "\nError! Caracteres no validos", &precio,0,9999999999,2))
                {
                    if(!getValidInt("\nIngrese Cantidad: ", "\nError! Caracteres no validos", &cantidad,0,999999,2))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        array[indice].precio = precio;
                        array[indice].cantidad = cantidad;
                        array[indice].idGasper = id;
                        array[indice].isEmpty = OCUPADO;
                        array[indice].idFantasma = idFantasma;
                    }
                }

            }
        }
    }
    return retorno;
}
/*int gasper_alta(Gasper* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;
    float precio;
    int cantidad;

    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        indice = buscarLugarLibre(array,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = proximoId();
            if(!getValidString("\nIngrese Nombre: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2))
            {
                if(!getValidFloat("\nIngrese Precio: ", "\nError! Caracteres no validos", &precio,0,9999999999,2))
                {
                    if(!getValidInt("\nIngrese Cantidad: ", "\nError! Caracteres no validos", &cantidad,0,999999,2))
                    {
                        retorno = 0;
                        strcpy(array[indice].nombre,nombre);
                        array[indice].precio = precio;
                        array[indice].cantidad = cantidad;
                        array[indice].idGasper = id;
                        array[indice].isEmpty = OCUPADO;
                    }
                }

            }
        }
    }
    return retorno;
}*/

int gasper_modificacion(Gasper* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];

    if(limite > 0 && array != NULL)
    {
        indice = gasper_buscarPorId(array,limite,id);
        if(indice >= 0)
        {
            retorno = -2;
            if(!getValidString("\nIngrese nuevo Nombre: ","\nError! Caracteres no validos","\nSe excedio de caracteres", nombre,50,2))
            {
                retorno = 0;
                if (getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                    strcpy(array[indice].nombre,nombre);
                }else{
                    printf("\nOperacion Cancelada!");
                }
            }

        }else{
            printf("\nID no encontrado");
        }

    }
    return retorno;
}

static int buscarLugarLibre(Gasper* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId()
{
    static int ultimoId = -1;
    ultimoId++;
    return ultimoId;
}

int gasper_modificacionCase(Gasper* array,int sizeArray,int id)
{
    int indice;
    char continuar;
    int modificar;
    int retorno=-1;
    char auxChar;
    float auxFloat;
    int auxInt;

    if(sizeArray > 0 && array != NULL)
    {
        indice = gasper_buscarPorId(array,sizeArray,id);
        if(indice >= 0)
        {
            retorno = -2;
            printf("\nDesea modificar al usuario '%s'?  (s/n) ",array[indice].nombre);
            fflush(stdin);
            scanf("%c", &continuar);
            if(continuar=='s'){
                retorno=0;
                getValidInt("\nIngrese la opcion que desea modificar: \n1. Modificar Descripcion. \n2. Modificar Importe. \n3.Modificar Cantidad:\n", "\nIngrese una opcion correcta!",&modificar,1,3,2);
                switch(modificar)
                {
                    case 1:
                        getString("\nIngrese su nuevo nombre de usuario: "  ,  &auxChar);
                        if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                            strcpy(array[indice].nombre,&auxChar);
                            printf("\nOperacion Exitosa");
                        }
                        else{
                            printf("\nOperacion cancelada!");
                        }
                        break;
                    case 2:
                        getValidFloat("\nIngrese su nuevo importe: ","Error! Ingrese caracteres validos", &auxFloat,0,99999999,3);
                        if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                            array[indice].precio = auxFloat;
                            printf("\nOperacion Exitosa");
                        }else{
                            printf("\nOperacion cancelada!");
                        }
                        break;
                    case 3:
                        getValidInt("\nIngrese Cantidad: ","Error! Ingrese caracteres validos", &auxInt,0,99999999,3);
                        if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                            array[indice].cantidad = auxInt;
                            printf("\nOperacion Exitosa");
                        }else{
                            printf("\nOperacion cancelada!");
                        }
                        break;
                }//switch(modificar)
            }else{
                printf("\nOperacion cancelada");
            }//if(continuar=='s')
        }else{
            printf("\nID no encontrado\n");
        }// if(indice >= 0)
    }//if(sizeArray > 0 && array != NULL)
    return retorno;
}

int gasper_ordenarNombre(Gasper* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Gasper auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && !orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                    //if((array[i].idGasper>array[i+1].idGasper && !orden) || (array[i].idGasper<array[i+1].idGasper && orden)) //<------------
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int gasper_ordenarId(Gasper* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Gasper auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                {
                    if((array[i].idGasper>array[i+1].idGasper && !orden) || (array[i].idGasper<array[i+1].idGasper && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int gasper_ordenarImporte(Gasper* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Gasper auxiliar;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(array[i].isEmpty == OCUPADO && array[i+1].isEmpty == OCUPADO )
                {
                    if((array[i].precio>array[i+1].precio && !orden) || (array[i].precio<array[i+1].precio && orden)) //<------------
                    {
                        auxiliar = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliar;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}







































