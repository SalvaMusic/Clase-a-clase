#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int idAbonado;
    int idMotivo;
    int idEstado;
    int idLlamada;
    int isEmpty;
}Llamada;
#endif // LLAMADA_H_INCLUDED

int llamada_init(Llamada* array,int limite);
int llamada_buscarPorId(Llamada* array,int limite, int id);
int llamada_baja(Llamada* array,int limite, int id);

int llamada_mostrar(Llamada* array,int limite);
int llamada_mostrarDebug(Llamada* array,int limite);
int llamada_alta(Llamada* array,int limite);
int llamada_modificacion(Llamada* array,int limite, int id);
int llamada_ordenar(Llamada* array,int limite, int orden);

//----------------------------Crear-------------------------------//

int llamada_calcularReclamos(Llamada* array,int limite, int id); // Por cada abonado
int llamada_cantidadMaximaReclamos(Llamada* array,int limite);
int informar_imprimirReclamos(Llamada* array,int limite);



