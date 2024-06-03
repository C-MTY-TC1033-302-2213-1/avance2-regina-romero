//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

class Pelicula : public Video {
private:
    int oscares;

public:
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    void setOscares(int _oscares);
    int getOscares();

    string str();
};

#endif
