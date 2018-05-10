#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fantasma.h"
#include "utn.h"
#define QTY 10
#define OCUPADO 0
#define LIBRE 1

static int buscarLugarLibre(Fantasma* array,int limite);
static int proximoId();

int fantasma_altaForzada(Fantasma* array,int limite,char* nombre/*,char* direccion, float precio, int tipo*/)
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
            /*strcpy(array[i].direccion,direccion);
            array[i].precio = precio;
            array[i].tipo = tipo;
            //------------------------------
            //------------------------------*/
            array[i].idFantasma = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}
int fantasma_init(Fantasma* array,int limite)
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

int fantasma_buscarPorId(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty == OCUPADO && array[i].idFantasma == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int fantasma_baja(Fantasma* array,int limite, int id)
{

    int retorno = -1;
    int indice;
    indice = fantasma_buscarPorId(array,limite,id);
    if(indice >= 0)
    {
        retorno = 0;
        array[indice].isEmpty = LIBRE;
    }
    return retorno;
}


int fantasma_mostrar(Fantasma* array,int limite)
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
               printf("\nNombre: %s - ID:%d - Estado: %d",array[i].nombre,array[i].idFantasma,array[i].isEmpty);
               flag=1;
            }
        }
        if(!flag){
            printf("\nNo hay datos ingresados!");
        }
    }
    return retorno;
}

int fantasma_mostrarDebug(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("\n[DEBUG] %s - %d - %d",array[i].nombre,array[i].idFantasma,array[i].isEmpty);
        }
    }
    return retorno;
}


int fantasma_alta(Fantasma* array,int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

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
                retorno = 0;
                strcpy(array[indice].nombre,nombre);
                array[indice].idFantasma = id;
                array[indice].isEmpty = OCUPADO;
            }
        }
    }
    return retorno;
}



int fantasma_modificacion(Fantasma* array,int limite, int id)
{
    int retorno = -1;
    int indice;
    char nombre[50];

    if(limite > 0 && array != NULL)
    {
        indice = fantasma_buscarPorId(array,limite,id);
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


static int buscarLugarLibre(Fantasma* array,int limite)
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

int fantasma_modificacionCase(Fantasma* array,int sizeArray,int id)
{
    int indice;
    char continuar;
    int modificar;
    int retorno=-1;
    char auxChar;

    if(sizeArray > 0 && array != NULL)
    {
        indice = fantasma_buscarPorId(array,sizeArray,id);
        if(indice >= 0)
        {
            retorno = -2;
            printf("\nDesea modificar al usuario '%s'?  (s/n) ",array[indice].nombre);
            fflush(stdin);
            scanf("%c", &continuar);
            if(continuar=='s'){
                retorno=0;
                getValidInt("\nIngrese la opcion que desea modificar: \n1. Modificar nombre de usuario. \n2. Modificar password. \n", "\nIngrese una opcion correcta!",&modificar,1,2,2);
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
                        getString("\nIngrese su nuevo password: ", &auxChar);
                        if(getChar("\nDesea guardar esta modificacion? (s/n): ")=='s'){
                            //  strcpy(array[indice].password,auxChar);
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

int fantasma_ordenar(Fantasma* array,int limite, int orden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    Fantasma auxiliar;

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
                    //if((array[i].idFantasma>array[i+1].idFantasma && !orden) || (array[i].idFantasma<array[i+1].idFantasma && orden)) //<------------
                }
            }
        }while(flagSwap);
    }
    return retorno;
}









































