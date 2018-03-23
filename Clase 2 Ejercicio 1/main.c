#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int main()
{
    int numero;
    int suma=0;
    float promedio=0;
    int i;
    int mayor;
    int menor;
    int flag=0;


    for(i=0;i<CANTIDAD;i++)
    {
        do
        {
            printf("Ingrese un numero\n");
            scanf("%d", &numero);
        }while(numero<=0);
        suma=suma+numero;

        if(flag==0)
        {
            mayor=numero;
            menor=numero;
            flag=1;
        }
        else
        {
            if(numero>mayor)
            {
                mayor=numero;
            }
            else if(numero<menor)
            {
                menor=numero;
            }
        }
    }

    promedio=(float)suma/CANTIDAD;

    printf("Mayor: %d\n", mayor);
    printf("Menor: %d\n", menor);
    printf("Promedio: %.2f\n",promedio);

    return 0;
}
