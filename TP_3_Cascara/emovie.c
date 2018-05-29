#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emovie.h"
#include "utn.h"

static int eMovie_setId(EMovie* this, int id);
static int eMovie_getId(EMovie* this, int* id);
static int isValidString(char* string);
static int validarDuracion(int duracion);
static int validarPuntaje(int puntaje);

int agregarPelicula(EMovie* arrayPunterosEMovie[], int* ocupado, int total,char* path)
{
    int retorno = -1;
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int idEMovie;

    File* pFile;
    pFile = fopen(path,"w");
    if(pFile != NULL && arrayPunterosEMovie != NULL && *ocupado >= 0 && total >= 0 && *ocupado > total)
    {
        eMovie_setParametros(titulo,genero,&duracion,descripcion,&puntaje,linkImagen);
        arrayPunterosEMovie[*ocupado] = eMovie_newParametros(titulo,genero,duracion,descripcion,puntaje,linkImagen,-1);
        retorno = 0;
    }
    fclose(pFile);
    return retorno;
}


EMovie* eMovie_new()
{
    return malloc(sizeof(EMovie));
}

void eMovie_delete(EMovie* this)
{
    free(this);
}

EMovie* eMovie_newParametros(char* titulo,char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen,int id)
{
    EMovie* auxiliarEMovie = eMovie_new();

    if(     !eMovie_setTitulo(auxiliarEMovie,titulo)
        &&  !eMovie_setGenero(auxiliarEMovie, genero)
        &&  !eMovie_setId(auxiliarEMovie, id)
        &&  !eMovie_setDuracion(auxiliarEMovie, duracion)
        &&  !eMovie_setDescripcion(auxiliarEMovie, descripcion)
        &&  !eMovie_setPuntaje(auxiliarEMovie, puntaje)
        &&  !eMovie_setLinkImagen(auxiliarEMovie, linkImagen))
    {
         return auxiliarEMovie;
    }
    eMovie_delete(auxiliarEMovie);
    return NULL;
}

int eMovie_setParametros(char* titulo,char* genero,int* duracion,char* descripcion,int* puntaje,char* linkImagen)
{
    int retorno = -1;
    getString("\nTitulo: ", titulo);
    getString("\nGenero: ", genero);
    if(!getValidInt("\nDuracion: ", "\nCaracteres invalidos!", &duracion,1, 500, 2))
    {
        if(!getValidInt("Puntaje:", "\nCaracteres invalidos!", puntaje, 1, 10, 2))
        {
            getString("\nLink imagen: ", linkImagen);
            retorno = 0;
        }
    }
    return retorno;
}
int eMovie_setDuracion(EMovie* this,int duracion)
{
    int retorno = -1;
    if(this != NULL && !validarDuracion(duracion))
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}

int eMovie_getDuracion(EMovie* this,int* duracion)
{
    int retorno = -1;
    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

int eMovie_setPuntaje(EMovie* this,int puntaje)
{
    int retorno = -1;
    if(this != NULL && !validarPuntaje(puntaje))
    {
        this->puntaje = puntaje;
        retorno = 0;

    }
    return retorno;
}

int eMovie_getPuntaje(EMovie* this,int* puntaje)
{
    int retorno = -1;
    if(this != NULL && puntaje != NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}

int eMovie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && isValidString(titulo))
    {
        retorno = 0;
        strcpy(this->titulo,titulo);
    }
    return retorno;
}

int eMovie_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        retorno = 0;
        strcpy(titulo,this->titulo);
    }
    return retorno;
}

int eMovie_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && isValidString(genero))
    {
        retorno = 0;
        strcpy(this->genero,genero);
    }
    return retorno;
}

int eMovie_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        retorno = 0;
        strcpy(genero,this->genero);
    }
    return retorno;
}

int eMovie_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && isValidString(descripcion))
    {
        retorno = 0;
        strcpy(this->descripcion,descripcion);
    }
    return retorno;
}

int eMovie_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        retorno = 0;
        strcpy(descripcion,this->descripcion);
    }
    return retorno;
}

int eMovie_setLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL && isValidString(linkImagen))
    {
        retorno = 0;
        strcpy(this->linkImagen,linkImagen);
    }
    return retorno;
}

int eMovie_getLinkImagen(EMovie* this, char* linkImagen)
{
    int retorno = -1;
    if(this != NULL && linkImagen != NULL)
    {
        retorno = 0;
        strcpy(linkImagen,this->linkImagen);
    }
    return retorno;
}

static int eMovie_setId(EMovie* this, int id)
{
    int retorno = -1;
    static int maximoId = -1;
    if(this != NULL)
    {
        retorno = 0;
        if(id >= 0)
        {
            if(id > maximoId)
                maximoId = id;
            this->idEMovie = id;
        }
        else
        {
            maximoId++;
            this->idEMovie = maximoId;
        }
    }
    return retorno;
}

static int eMovie_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->idEMovie;
    }
    return retorno;
}

static int isValidString(char* string)
{
    if(esSoloLetras(string))
    {
        return 1;
    }
    return 0;
}

static int validarDuracion(int duracion)
{
    int retorno = -1;
    if (duracion>=0 && duracion<=1000);
        retorno=0;

    return retorno;
}

static int validarPuntaje(int puntaje)
{
    int retorno = -1;
    if (puntaje>=0 && puntaje<=10);
        retorno=0;

    return retorno;
}
