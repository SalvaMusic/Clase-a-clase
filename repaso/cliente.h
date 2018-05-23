typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int edad;
    int idCliente;
}Cliente;

Cliente* cliente_new();
Cliente* cliente_new2(char* nombre, char* apellido, char* cuit, int edad);
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this, char* nombre);
int cliente_setApellido(Cliente* this, char* apellido);
int cliente_setCuit(Cliente* this, char* cuit);
int cliente_setEdad(Cliente* this,int edad);
int cliente_getNombre(Cliente* this, char* nombre);
int cliente_getApellido(Cliente* this, char* apellido);
int cliente_getCuit(Cliente* this, char* cuit);
int cliente_getEdad(Cliente* this,int* edad);
int validarEdad(int edad);

int cliente_alta(int *cantidad,Cliente *listado[]);
int cliente_listar(int cantidad,Cliente *listado[]);




