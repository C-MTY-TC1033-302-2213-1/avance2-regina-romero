//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video {
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

public:
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    string getId();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    virtual string str();
};

#endif