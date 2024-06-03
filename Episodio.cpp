//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#include "Episodio.h"

Episodio::Episodio() : titulo(""), temporada(0), calificacion(0.0) {}

Episodio::Episodio(string _titulo, int _temporada, double _calificacion)
    : titulo(_titulo), temporada(_temporada), calificacion(_calificacion) {}

void Episodio::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada) {
    temporada = _temporada;
}

void Episodio::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

string Episodio::getTitulo() {
    return titulo;
}

int Episodio::getTemporada() {
    return temporada;
}

double Episodio::getCalificacion() {
    return calificacion;
}

string Episodio::str() {
    return titulo + " " + to_string(temporada) + " " + to_string(calificacion);
}
