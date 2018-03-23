#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 10
int main()
{
    char caracter;
    int aContador=0;
    int eContador=0;
    int iContador=0;
    int oContador=0;
    int uContador=0;
    int i;

    for(i=0;i<CANTIDAD;i++)
    {
        printf("Ingrese una letra\n");
        fflush(stdin);
        scanf("%c", &caracter);

        switch(caracter)
        {
            case 'a':
                aContador++;
                break;
            case 'e':
                eContador++;
                break;
            case 'i':
                iContador++;
                break;
            case 'o':
                oContador++;
                break;
            case 'u':
                uContador++;
                break;
        }//switch(caracter)
    }//for(i=0;i<CANTIDAD;i++)

    printf("Cantidad de 'a': %d\n", aContador);
    printf("Cantidad de 'e': %d\n", eContador);
    printf("Cantidad de 'i': %d\n", iContador);
    printf("Cantidad de 'o': %d\n", oContador);
    printf("Cantidad de 'u': %d\n", uContador);

    return 0;
}
