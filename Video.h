//
//Regina Romero Alvarado
//A00840840
//ITC
// 1/6/24.
//
/*
¿Qué aprendí en el desarrollo de esta clase?
En el desarrollo de esta clase aprendí a diseñar una clase base que encapsula atributos y comportamientos
comunes a diferentes tipos de videos, como películas y series. Aprendí a definir métodos virtuales puros
para garantizar que las clases derivadas implementen ciertas funcionalidades. Además, comprendí cómo
utilizar la herencia para extender esta clase base y especializarla en clases derivadas específicas, como
Pelicula y Serie. También aprendí cómo esta clase base puede ser utilizada para gestionar una colección
polimórfica de objetos de diferentes tipos de videos.
*/


#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video{
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

public:
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero,  double _calificacion);

    //metodos modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //metodos de acceso
    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //otros metodos
    virtual string str();
};

#endif