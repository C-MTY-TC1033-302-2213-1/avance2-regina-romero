//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#include "Video.h"

Video::Video() : iD(""), titulo(""), duracion(0), genero(""), calificacion(0.0) {}

Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
    : iD(_iD), titulo(_titulo), duracion(_duracion), genero(_genero), calificacion(_calificacion) {}

void Video::setId(string _iD) {
    iD = _iD;
}

void Video::setTitulo(string _titulo) {
    titulo = _titulo;
}

void Video::setDuracion(int _duracion) {
    duracion = _duracion;
}

void Video::setGenero(string _genero) {
    genero = _genero;
}

void Video::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

string Video::getId() {
    return iD;
}

string Video::getTitulo() {
    return titulo;
}

int Video::getDuracion() {
    return duracion;
}

string Video::getGenero() {
    return genero;
}

double Video::getCalificacion() {
    return calificacion;
}

string Video::str() {
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion);
}

