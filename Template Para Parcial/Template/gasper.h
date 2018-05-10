#ifndef GASPER_H_INCLUDED
#define GASPER_H_INCLUDED
typedef struct
{
    char nombre[50];
    float precio;
    int cantidad;
    int idFantasma;
    //------------
    int idGasper;
    int isEmpty;
}Gasper;
#endif // GASPER_H_INCLUDED

int gasper_init(Gasper* array,int limite);
int gasper_buscarPorId(Gasper* array,int limite, int id);
int gasper_baja(Gasper* array,int limite, int id);

int gasper_altaForzada(Gasper* array,int limite,char* nombre, float precio, int cantidad,int idProv);
int gasper_mostrar(Gasper* array,int limite);
int gasper_mostrarDebug(Gasper* array,int limite);
int gasper_alta(Gasper* array,int limite,int idProv);
int gasper_modificacion(Gasper* array,int limite, int id);
int gasper_modificacionCase(Gasper* array,int sizeArray,int id);

int gasper_ordenarNombre(Gasper* array,int limite, int orden);
int gasper_ordenarId(Gasper* array,int limite, int orden);
int gasper_ordenarImporte(Gasper* array,int limite, int orden);

int gasper_promedioGasper(Gasper* array,int limite, int id,float *promedio);
int gasper_importePromedioTotal(Gasper* array,int limite,float *precioTotal,float *promedio);






