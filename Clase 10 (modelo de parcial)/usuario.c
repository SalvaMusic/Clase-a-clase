#include <stdio.h>
#include <string.h>
#include "usuario.h"
#include "funciones.h"

int usu_mostrar(Usuario* arrayUsuario, int sizeArray)
{
    int i;
    int flag=0;

    for(i=0;i<sizeArray;i++)
    {
        if(!arrayUsuario [i].isEmpty)
        {
            printf("\n%s,\t ID:%d",arrayUsuario[i].nombreUsuario, arrayUsuario[i].idUsuario);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nNo hay usuarios ingresados\n");
    }
    return 0;
}
/*
int usu_modificar(Usuario* arrayUsuario, int sizeArray)
{
    int i;
    int idUsuario;
    char continuar;
    int modificar;
    char auxChar;
    int flag=0;

    getInt("Ingrese el ID del usuario: ", "Fuera de rango", 2, 1, sizeArray, &idUsuario);

    for(i=0;i<sizeArray;i++)
    {
        if(idUsuario==arrayUsuario[i].idUsuario)
        {
            printf("\nVa a modificar al usuario '%s'. Desea continuar? (s/n): ", arrayUsuario[i].nombreUsuario);
            fflush(stdin);
            scanf("%c", &continuar);
            if (continuar=='s')
            {
                getInt("\nIngrese la opcion que desea modificar: \n1. Modificar nombre de usuario. \n 2. Modificar password", "Opcion incorrecta",2,1,2, &modificar);
                switch (modificar)
                {
                    case '1':
                        getStringLetras("\nIngrese el nuevo nombre de usuario: ", auxChar);
                        printf("Desea confirmar la modificacion? (s/n)");
                        if(continuar == 's')
                        {
                            strcpy(arrayUsuario[i].nombreUsuario, auxChar);
                            printf("\nSu nueno nombre de usuario es: %s", arrayUsuario[i].nombreUsuario);
                        }
                        else
                        {
                            printf("\nOperacion cancelada");
                        }
                        break;
                    case '2':
                        getString("\nIngrese el nuevo password: ", &auxChar);
                        printf("Desea confirmar la modificacion? (s/n)");
                        if(continuar == 's')
                        {
                            strcpy(arrayUsuario[i].password, auxChar);
                            printf("\nHa modificado su password con exito");
                        }
                        else
                        {
                            printf("\nOperacion cancelada");
                        }
                        break;
                }
            flag=1;
        }

    }
    if(!flag)
    {
        printf("\nNo se encontro el ID");
    }
    return 0;
}
*/

int usu_modificar(Usuario* arrayUsuario,int sizeArray)
{
    int n=0;
    int i;
    char continuar;
    int idUsuario;
    int modificar;
    int flag=1;
    char auxChar;

    do
    {
        getInt("\nIngrese el ID del usuario que desea modificar: ", "\nFuera de rango! Ingrese un ID valido",2,1,sizeArray, &idUsuario);
        n++;
        for(i=0;i<sizeArray;i++)
        {
            if(idUsuario == arrayUsuario[i].idUsuario)
            {
                printf("\nDesea modificar al usuario '%s'?  (s/n) ",arrayUsuario[i].nombreUsuario);
                fflush(stdin);
                scanf("%c", &continuar);
                if(continuar=='s')
                {
                    getInt("\nIngrese la opcion que desea modificar: \n1. Modificar nombre de usuario. \n2. Modificar password. \n", "\nIngrese una opcion correcta!",2,1,2, &modificar);
                    switch(modificar)
                    {
                        case 1:
                            getString("\nIngrese su nuevo nombre de usuario: "  ,&auxChar);

                            getStringLetras("\nDesea guardar esta modificacion? (s/n): ", &continuar);
                            if (continuar=='s')
                            {
                                strcpy(arrayUsuario[i].nombreUsuario, auxChar);
                                printf("\nSu nuevo nombre de usuario es: %s", arrayUsuario[i].nombreUsuario);
                            }
                            else
                            {
                                printf("\nOperacion cancelada!");
                            }

                            break;
                        case 2:
                            getString("\nIngrese su nuevo password: ", &auxChar);

                            getStringLetras("\nDesea guardar esta modificacion? (s/n): ", &continuar);
                            if (continuar=='s')
                            {
                                strcpy(arrayUsuario[i].password,auxChar);
                                printf("\nHa modificado su password con exito");
                            }
                            else
                            {
                                printf("\nOperacion cancelada!");
                            }
                            break;
                    }
                }
                else
                {
                    printf("\nOperacion cancelada");
                }
             flag=0;
            }
        }
        if(flag)
        {
            printf("\nID no encontrado\n");
        }
        if(n>2)
        {
            getStringLetras("\nIntentar nuevamente? (s/n): ", &continuar);
            if(continuar!='s')
                flag=0;
        }


    }while(flag);
    return 0;
}

int usu_baja(Usuario* arrayUsuario,int sizeArray)
{
    int i;
    char continuar;
    int idUsuario;
    int flag=1;
    int n=0;

    do
    {
        getInt("\nIngrese el ID del usuario que desea bajar: ", "\nFuera de rango! Ingrese un ID valido",2,1,sizeArray, &idUsuario);
        n++;
        for(i=0;i<sizeArray;i++)
        {
            if(idUsuario == arrayUsuario[i].idUsuario)
            {
                printf("\nDesea dar de baja al usuario '%s'?  (s/n) ",arrayUsuario[i].nombreUsuario);
                fflush(stdin);
                scanf("%c", &continuar);
                if(continuar=='s')
                {
                    printf("\nHa dado de baja al usuario '%s' correctamente",arrayUsuario[i].nombreUsuario);
                    arrayUsuario[i].isEmpty=1;
                }
                else
                {
                    printf("\nOperacion cancelada");
                }
             flag=0;
            }
        }
        if(flag)
        {
            printf("\nID no encontrado\n");
        }
        if(n>2)
        {
            getStringLetras("\nIntentar nuevamente? (s/n): ", &continuar);
            if(continuar!='s')
                flag=0;
        }


    }while(flag);
    return 0;
}

int usu_alta (Usuario* arrayUsuario, int sizeArray)
{
    int i;

    for(i=0;i<sizeArray;i++)
    {
        if(arrayUsuario [i].isEmpty)
        {
            getString("\nIngrese nombre de Usuario: ", arrayUsuario[i].nombreUsuario);
            getString("\nIngrese Password: ", arrayUsuario[i].password);
            arrayUsuario[i].idUsuario=i+1;
            arrayUsuario[i].isEmpty=0;
            printf("\nHa ingresado al usuario %s, ID: %d", arrayUsuario[i].nombreUsuario, arrayUsuario[i].idUsuario);
            break;
        }
    }
    return 0;
}

int usu_init (Usuario* arrayUsuario, int sizeArray)
{
    int i;

    for(i=0;i<sizeArray;i++)
    {
        arrayUsuario [i].isEmpty=1;
    }
    return 0;
}

int usu_len (Usuario* arrayUsuario,int sizeArray)
{
    int i;
    for(i=0;i<sizeArray;i++)
    {
        if(arrayUsuario[i].isEmpty)
            break;
    }
    return i;
}






