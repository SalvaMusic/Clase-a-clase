#include <stdio.h>
#include <stdlib.h>

int main()
{
    char apellido;
    float sueldo;
    int aumento;
    float sueldoFinal;


    printf("Ingrese su apellido\n");
    scanf("%c",&apellido);
    printf("Ingrese sueldo\n");
    scanf("%f",&sueldo);
    printf("Ingrese aumento\n");
    scanf("%d",&aumento);

    sueldoFinal=sueldo+(sueldo*aumento/100);

    printf("apellido: %c, sueldo: %.2f, aumento: %d, sueldo final: %.2f",apellido,sueldo,aumento,sueldoFinal);
    return 0;
}
