//
//Regina Romero Alvarado
//A00840840
//ITC
// 1/6/24.
//
/*
¿Qué aprendí en el desarrollo de esta clase?
En el desarrollo de esta clase aprendí a definir una clase que representa una serie de televisión.
Aprendí a utilizar la herencia para extender una clase base (Video) y añadir funcionalidades
específicas para las series. Además, comprendí cómo implementar métodos para agregar episodios
a una serie y calcular el promedio de calificaciones de los episodios. También aprendí cómo esta
clase puede interactuar con otras clases en un sistema más grande.
*/


#ifndef SERIE_H
#define SERIE_H

#include "Video.h"
#include "Episodio.h"

class Serie : public Video {
private:
    Episodio episodios[5];
    int cantidad;

public:
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //metodos modificadores
    void calculaDuracion();
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //metodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //motros metoddos
    double calculaPromedio();
    void agregaEpisodio(Episodio episodio);

    string str();
};

#endif


