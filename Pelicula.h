//
//Regina Romero Alvarado
//A00840840
//ITC
// 1/6/24.
//
/*
¿Qué aprendí en el desarrollo de esta clase?
En el desarrollo de esta clase aprendí a definir una clase que representa una película.
Aprendí a implementar constructores, métodos modificadores y de acceso para los atributos
de una película, así como a definir un metodo que devuelve una representación en cadena
de los atributos del objeto. También comprendí cómo utilizar la encapsulación para
proteger los datos de la clase y cómo los métodos públicos pueden interactuar con estos datos.
*/



#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    int oscares;  // Número de premios Óscar ganados por la película

public:
    // Constructor por default
    Pelicula();

    // Constructor con parámetros
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Metodo modificador
    void setOscares(int _oscares);

    // Metodo de acceso
    int getOscares();

    // otros metodos
    string str();
};

#endif
