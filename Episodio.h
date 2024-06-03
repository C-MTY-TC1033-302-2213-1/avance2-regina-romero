//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo;
    int temporada;
    double calificacion;

public:
    Episodio();
    Episodio(string _titulo, int _temporada, double _calificacion);

    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);

    string getTitulo();
    int getTemporada();
    double getCalificacion();

    string str();
};

#endif
