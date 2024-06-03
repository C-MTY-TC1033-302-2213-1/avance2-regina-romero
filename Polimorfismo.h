//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

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
