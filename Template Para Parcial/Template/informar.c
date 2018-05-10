#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "informar.h"
#include "utn.h"
#include "Producto.h"
#include "proveedores.h"

int informar_ConsultaFacturacion(Proveedores* arrayProveedores,int lenProveedores,
              Producto* arrayProductos, int lenProductos, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexProducto;

    if(arrayProveedores != NULL && arrayProductos != NULL && lenProveedores > 0 && lenProductos > 0)
    {
        retorno = -2;
        for(i=0;i<lenProveedores;i++)
        {
            if(!arrayProveedores[i].isEmpty && !strcmp(arrayProveedores[i].cuit,cuit))
            {
                indexProducto = pantalla_buscarPorId(arrayProductos,lenProductos,arrayProveedores[i].idProducto);
                printf("\nID: %d - Valor: %.2f",

                       arrayProveedores[i].id,
                       arrayProveedores[i].dias*arrayProductos[indexProducto].precio);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int informar_ListarProveedoreses(Proveedores* arrayProveedores,int limite,
              Producto* pantallas, int lenProductos)
{
    int retorno = -1;

    return retorno;
}


int informar_ListarCantidadProveedoresesImporte(Proveedores* arrayProveedores,int lenProveedores,
              Producto* arrayProductos, int lenProductos)
{
    /*Lista de cada cliente con cantidad de contrataciones e importe
    a pagar por cada una.
    */


    int retorno = -1;
    int i;
    int indexProducto;
    char ultimoCuit[50]="-";
    if(arrayProveedores != NULL && arrayProductos != NULL && lenProveedores > 0 && lenProductos > 0)
    {
        retorno = -2;
        cont_ordenarCuit(arrayProveedores,lenProveedores,0);
        for(i=0;i<lenProveedores;i++)
        {
            if(!arrayProveedores[i].isEmpty && strcmp(arrayProveedores[i].cuit,ultimoCuit) != 0)
            {
                strcpy(ultimoCuit,arrayProveedores[i].cuit);

                printf("\n\nINFO DEL CUIT - %s -",ultimoCuit);
                informar_ConsultaFacturacionTotal(arrayProveedores,lenProveedores,arrayProductos,lenProductos,ultimoCuit);
            }
        }
    }

    return retorno;
}


int informar_ConsultaFacturacionTotal(Proveedores* arrayProveedores,int lenProveedores,
              Producto* arrayProductos, int lenProductos, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexProducto;
    int contador=0;
    float acumulador=0;

    if(arrayProveedores != NULL && arrayProductos != NULL && lenProveedores > 0 && lenProductos > 0)
    {
        retorno = -2;
        for(i=0;i<lenProveedores;i++)
        {
            if(!arrayProveedores[i].isEmpty && !strcmp(arrayProveedores[i].cuit,cuit))
            {
                indexProducto = pantalla_buscarPorId(arrayProductos,lenProductos,arrayProveedores[i].idProducto);

                contador++;
                acumulador += arrayProveedores[i].dias*arrayProductos[indexProducto].precio;
                retorno = 0;
            }
        }
    }

    printf("\nCantidad contrataciones: %d - Total: %.2f",

                       contador,
                       acumulador);
    return retorno;
}
