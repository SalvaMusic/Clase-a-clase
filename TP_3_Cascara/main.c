#include <stdio.h>
#include <stdlib.h>
#include "emovie.h"
#include "utn.h"


int main()
{
    EMovie* arrayPunterosEMovie [10];
    int qtyActualArrayPunterosEMovie [0];
    int qtyTotalArrayPunterosEMovie [10];
    char seguir = 's';
    int opcion = 0;

    while(seguir == 's')
    {
        getValidInt("\n1- Agregar pelicula\n2- Borrar pelicula\n3- Generar pagina web\n4- Salir\n","Ingrese un numero correcto!\n",&opcion,1,4,3);

        switch(opcion)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

               break;
            case 4:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
