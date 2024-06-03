//
//Regina Romero Alvarado
//A00840840
//ITC
// 1/6/24.
//
/*
¿Qué aprendí en el desarrollo de esta clase?
En el desarrollo de esta clase aprendí a implementar un sistema de manejo polimórfico de objetos mediante
punteros y clases base. Aprendí a usar punteros a objetos y la palabra clave 'virtual' para permitir el
comportamiento polimórfico. Además, comprendí cómo gestionar un conjunto de objetos de diferentes tipos
mediante un arreglo de punteros a la clase base. También aprendí cómo definir métodos para manipular y
acceder a estos objetos de manera eficiente.
*/


#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo {
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:
    Polimorfismo();

    void leerArchivo(string nombre);

    //metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //metodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    //Otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};

#endif
