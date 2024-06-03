//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

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

    void calculaDuracion();
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    Episodio getEpisodio(int posicion);
    int getCantidad();

    double calculaPromedio();
    void agregaEpisodio(Episodio episodio);

    string str();
};

#endif


