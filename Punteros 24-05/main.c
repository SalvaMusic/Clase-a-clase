#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;
    int continuar;

    do
    {
        getValidInt("\n1.Cargar desde Archivo\n2.Mostrar desde archivo\n3.Guardar desde Archivo\n4.Eliminar desde archivo\n","No Valida",&continuar,1,5,2);

        switch(continuar)
        {
            case 1 :
                arrayAlumno_loadFromFile(arrayPunteroAlumnos,&qtyActualArrayAlumnos,qtyMaximaArrayAlumnos,"archivo.pasteleria");
                //arrayPunteroAlumnos[qtyActualArrayAlumnos] = alumno_newParametros("XX",22,-1);
                //qtyActualArrayAlumnos++;
                break;
            case 2 :
                mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);
                break;
            case 3 :
                arrayAlumno_dumpInFile(arrayPunteroAlumnos,&qtyActualArrayAlumnos,qtyMaximaArrayAlumnos,"archivo2.pasteleria");
                break;
            case 4 :

                break;
        }
    }while(continuar != 5);





    //cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);



    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{

}

void mostrar(Alumno* array[],int cantidad)
{
    int i;
    char nombre[50];
    float altura;
    int id;
    for(i=0 ; i<cantidad;i++)
    {
        alumno_getNombre(array[i],nombre);
        alumno_getAltura(array[i],&altura);
        alumno_getId(array[i],&id);
        printf("%s - %f - %d\n",nombre,altura,id);

    }

}

void modificar(Alumno* array[],int cantidad)
{

}
