#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "ArrayList.h"
#include "controller.h"

int main()
{
    ArrayList* pArrayClientes;
    pArrayClientes = al_newArrayList();
    int menu;

    controller_leerArchivoClientes("clientes.txt",pArrayClientes);

    do
    {

        system("cls");
        printf("%d",pArrayClientes->size);
        getValidInt("\n1.Alta de Cliente\n2.Modicar datos de Cliente\n3.Baja de Cliente\n4.Listar Clientes\n5.Realizar una Venta\
                    \n6.Anular una Venta\n7.Informar Ventas\n8.Informar Ventas por Producto\n9.Generar Informe de Ventas\n10.Informar Cantidad de Ventas por Cliente\n11.Salir\n\nINGRESE UNA OPCION: ","\nNo valida\n",&menu,1,11,1);

        switch(menu)
        {
            case 1:
                printf("\n\tALTA CLIENTE:\n");
                controller_altaCliente(pArrayClientes);
                controller_guardarClientesArchivo(pArrayClientes,"clientes.txt");
                system("pause");
                break;
            case 2:
                printf("\n\tMODIFICAR DATOS CLIENTE:\n");
                controller_listarArchivoClientes(pArrayClientes);
                controller_modificarCliente(pArrayClientes);
                controller_guardarClientesArchivo(pArrayClientes,"clientes.txt");
                system("pause");
                break;
            case 3:
                printf("\n\tBAJA CLIENTE:\n");
                controller_listarArchivoClientes(pArrayClientes);
                controller_bajaCliente(pArrayClientes);
                controller_guardarClientesArchivo(pArrayClientes,"clientes.txt");
                system("pause");
                break;
            case 4:
                printf("\n\tLISTAR CLIENTES:\n");

                system("pause");
                break;
            case 5:
                printf("\n\tPAUSAR PUBLICACION:");

                system("pause");
                break;
            case 6:
                printf("\n\tREANUDAR PUBLICACION:");

                system("pause");
                break;
                case 7:
                printf("\n\tIMPRIMIR CLIENTES:\n");

                system("pause");
                break;
                case 8:
                printf("\n\tIMPRIMIR PUBLICACIONES:\n");

                system("pause");
                break;
                case 9:
                printf("\n\tINFORMAR CLIENTES:\n");

                system("pause");
                break;
                case 10:
                printf("\n\tINFORMAR PUBLICACIONES:\n");

                system("pause");
                break;
        }
    }while(menu != 11);

    return 0;
}
