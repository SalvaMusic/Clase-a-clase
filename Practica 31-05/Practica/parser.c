#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"


int parserEmployee(char* path , ArrayList* pArrayListEmployee)
{
    Cliente* auxiliarCliente;
    int retorno = 0;
    char bNombre[4096];
    char bApellido[4096];
    char bEmail[4096];
    char bGenero;
    char bProfesion[4096];
    char bNacionalidad[4096];
    char bId[4096];
    char bUsuario[4096];


    FILE* pFile;
    pFile = fopen(path,"r");

    if(pFile != NULL)
    {
        retorno = 1;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n",bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);
        while (!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n],\n",bId,bNombre,bApellido,bEmail,bGenero,bProfesion,bUsuario,bNacionalidad);

        }

    }
    fclose(pFile);

    return retorno;
}
