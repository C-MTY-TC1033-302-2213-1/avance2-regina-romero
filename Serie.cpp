//
//Regina Romero Alvarado
//A00840840
//ITC
//26/5/24.
//

#include "Serie.h"

Serie::Serie() : Video(), cantidad(0) {}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
    : Video(_iD, _titulo, _duracion, _genero, _calificacion), cantidad(0) {}

void Serie::setEpisodio(int posicion, Episodio episodio) {
    if (posicion >= 0 && posicion < cantidad) {
        episodios[posicion] = episodio;
    }
}

void Serie::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

Episodio Serie::getEpisodio(int posicion) {
    if (posicion >= 0 && posicion < cantidad) {
        return episodios[posicion];
    }
    return Episodio();
}

int Serie::getCantidad() {
    return cantidad;
}

double Serie::calculaPromedio() {
    double acum = 0;
    for (int index = 0; index < cantidad; index++) {
        acum += episodios[index].getCalificacion();
    }
    return (cantidad > 0) ? acum / cantidad : 0;
}

void Serie::agregaEpisodio(Episodio episodio) {
    if (cantidad < 5) {
        episodios[cantidad++] = episodio;
    }
}

void Serie::calculaDuracion() {
    int totalDuracion = 0;
    for (int index = 0; index < cantidad; index++) {
        totalDuracion += episodios[index].getTemporada();
    }
    duracion = totalDuracion;
}

string Serie::str() {
    string result = Video::str() + " " + to_string(cantidad) + "\n";
    for (int index = 0; index < cantidad; index++) {
        result += episodios[index].str() + "\n";
    }
    return result;
}

