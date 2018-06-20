#ifndef _CLIENTE_H
#define _CLIENTE_H
struct
{
    char nombre[64];
    char apellido[64];
    char dni[14];
    int id;
}typedef Cliente;
#endif // _CLIENTE_H

Cliente* cliente_new(void);
Cliente* cliente_newParametrosString(int id,char* strNombre,char* strApellido,char* strDni);
int cliente_setParametros(char* nombre,char* apellido,char* dni);
void cliente_delete(Cliente* this);
int cliente_setId(Cliente* this, int id);
int cliente_getId(Cliente* this,int* id);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_setDni(Cliente* this, char* dni);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_getDni(Cliente* this, char* dni);
int cliente_ordenarApellidoNombre(void* clienteA,void* clienteB);


