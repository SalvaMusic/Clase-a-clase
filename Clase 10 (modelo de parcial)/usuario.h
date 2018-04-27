#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED 123
typedef struct
{
    char nombreUsuario[50];
    char password [50];
    int idUsuario;
    int isEmpty;
}Usuario;
#endif // EMPLEADO_H_INCLUDED

int usu_mostrar(Usuario* arrayUsuario, int sizeArray);
int usu_alta (Usuario* arrayUsuario, int sizeArray);
int usu_init (Usuario* arrayUsuario, int sizeArray);
int usu_len (Usuario* arrayUsuario,int sizeArray);
int usu_baja(Usuario* arrayUsuario,int sizeArray);
int usu_modificar(Usuario* arrayUsuario,int sizeArray);



