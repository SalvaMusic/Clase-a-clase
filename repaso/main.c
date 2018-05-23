#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"


int main()
{
    Cliente* pArrayClientes [50];
    int QTYclientes=0;

    cliente_alta(&QTYclientes,pArrayClientes);
    cliente_listar(QTYclientes,pArrayClientes);

    return 0;
}
