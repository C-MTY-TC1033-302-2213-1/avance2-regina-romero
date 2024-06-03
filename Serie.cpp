//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24.
//

#include "Serie.h"

// Constructor default
Serie::Serie() : Video(), cantidad(0) {}

// Constructor con parámetros
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
    : Video(_iD, _titulo, _duracion, _genero, _calificacion), cantidad(0) {}

// Establece un episodio en una posición específica
void Serie::setEpisodio(int posicion, Episodio episodio) {
    if (posicion >= 0 && posicion < cantidad) {
        episodios[posicion] = episodio;
    }
}

// Establece la cantidad de episodios
void Serie::setCantidad(int _cantidad) {
    cantidad = _cantidad;
}

// Obtiene un episodio en una posición específica
Episodio Serie::getEpisodio(int posicion) {
    if (posicion >= 0 && posicion < cantidad) {
        return episodios[posicion];
    }
    return Episodio();
}

// Obtiene la cantidad de episodios
int Serie::getCantidad() {
    return cantidad;
}

// Calcula el promedio de calificaciones de los episodios
double Serie::calculaPromedio() {
    double acum = 0;
    for (int index = 0; index < cantidad; index++) {
        acum += episodios[index].getCalificacion();
    }
    return (cantidad > 0) ? acum / cantidad : 0;
}

// Agrega un episodio a la serie
void Serie::agregaEpisodio(Episodio episodio) {
    if (cantidad < 5) {
        episodios[cantidad++] = episodio;
    }
}

// Calcula la duración total de la serie sumando la duración de todos los episodios
void Serie::calculaDuracion() {
    int totalDuracion = 0;
    for (int index = 0; index < cantidad; index++) {
        totalDuracion += episodios[index].getTemporada();
    }
    duracion = totalDuracion;
}

// Devuelve una representación en cadena de la serie, incluyendo sus episodios
string Serie::str() {
    string result = Video::str() + " " + to_string(cantidad) + "\n";
    for (int index = 0; index < cantidad; index++) {
        result += episodios[index].str() + "\n";
    }
    return result;
}
