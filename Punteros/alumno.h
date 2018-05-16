typedef struct
{
    int edad;
    char nombre[50];
    char apellido[50];
}Alumno;


Alumno* alumno_new();
void alumno_delete(Alumno* this);
int alumno_setEdad(Alumno* this, int edad);
int alumno_setNombre(Alumno* this, char* nombre);
int alumno_setApellido(Alumno* this, char* apellido);
int alumno_getEdad(Alumno* this, int* edad);
int alumno_getNombre(Alumno* this, char* nombre);
int alumno_getApellido(Alumno* this, char* apellido);


