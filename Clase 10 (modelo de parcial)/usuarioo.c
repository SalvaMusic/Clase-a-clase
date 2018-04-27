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

