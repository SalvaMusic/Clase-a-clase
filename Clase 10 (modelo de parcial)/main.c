#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "usuario.h"
#define CANTIDAD 5

int main()
{
    Usuario arrayUsuario [CANTIDAD];
    usu_init(arrayUsuario, CANTIDAD);


    printf("\nCOMPRA VENTA\n");
    printf("\n1.");


    usu_mostrar(arrayUsuario, CANTIDAD);

    usu_alta(arrayUsuario, CANTIDAD);


    usu_mostrar(arrayUsuario, CANTIDAD);

    usu_modificar(arrayUsuario,CANTIDAD);
    usu_mostrar(arrayUsuario,CANTIDAD);



    return 0;
}
