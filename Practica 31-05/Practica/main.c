#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "utn.h"
#include "controller.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Guardar datos en data.csv (modo texto)
        9. Guardar datos en data.bin (modo binario)
*****************************************************/

int main()
{
    FILE* pFile;
    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();

    char seguir = 's';
    int opcion = 0;

    while(seguir == 's')
    {
        getValidInt("\n1. Cargar datos desde data.csv\n2. Listar Clientes\n3. Ordenar por nombre y apellido\
                    \n4. Ordenar por mail\n5. Agregar un Cliente\n6. Elimina un Cliente\n7. Modificar Cliente (Nombre, Apellido y Mail)\
                    \n8.Guardar datos en data.csv (modo texto)\n9. Guardar datos en data.bin (modo binario)\n11- Salir\
                    \n","Ingrese un numero correcto!\n",&opcion,1,11,2);

        switch(opcion)
        {
            case 1:
                controller_leerArchivo("data.csv",pArrayClientes);
                break;
            case 2:
                controller_listarArchivo(pArrayClientes);
                break;
            case 3:
                controller_ordenarArchivoNombreApellido(pArrayClientes);
               break;
            case 4:
                controller_ordenarEmail(pArrayClientes);
               break;
            case 5:

               break;
            case 6:

                break;
            case 7:
                controller_modificar(pArrayClientes);
                break;
            case 8:

               break;
            case 9:
                controller_guardarClientesArchivo(pArrayClientes,"data2.csv");
               break;
            case 10:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
