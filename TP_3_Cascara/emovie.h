#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int idEMovie;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* arrayPunterosEMovie[], int* ocupado, int total,char* path);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[]);

#endif // EMOVIE_H_INCLUDED

EMovie* eMovie_newParametros(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen,int id);
int eMovie_setParametros(char* titulo,char* genero,int* duracion,char* descripcion,int* puntaje,char* linkImagen);

int eMovie_setDuracion(EMovie* this,int duracion);
int eMovie_getDuracion(EMovie* this,int* duracion);
int eMovie_setPuntaje(EMovie* this,int puntaje);
int eMovie_getPuntaje(EMovie* this,int* puntaje);
int eMovie_setTitulo(EMovie* this, char* titulo);
int eMovie_getTitulo(EMovie* this, char* titulo);
int eMovie_setGenero(EMovie* this, char* genero);
int eMovie_getGenero(EMovie* this, char* genero);
int eMovie_setDescripcion(EMovie* this, char* descripcion);
int eMovie_getDescripcion(EMovie* this, char* descripcion);
int eMovie_setLinkImagen(EMovie* this, char* linkImagen);
int eMovie_getLinkImagen(EMovie* this, char* linkImagen);

