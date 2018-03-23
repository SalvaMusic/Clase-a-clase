#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int mayor;

    printf("Ingrese el primer numero\n");
    scanf("%d",&numeroUno);
    printf("Ingrese el segundo numero\n");
    scanf("%d",&numeroDos);
    printf("Ingrese el tercer numero\n");
    scanf("%d",&numeroTres);
    printf("%d %d %d",numeroUno,numeroDos,numeroTres);

    if (numeroUno>numeroDos && numeroUno>numeroTres)
    {
        mayor=numeroUno;
    }
    else
    {
        if(numeroDos>numeroTres)
        {
            mayor=numeroDos;
        }
        else
        {
            mayor=numeroTres;
        }
    }
    printf("El número mayor es: %d",mayor);
    return 0;
}
