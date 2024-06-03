//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24.
//

#include "Pelicula.h"

// Constructor default
Pelicula::Pelicula() : Video() {
    oscares = 100; // Inicializa oscares con un valor predeterminado
}

// Constructor con parámetros
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares)
    : Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    oscares = _oscares; // Inicializa oscares con el valor proporcionado
}

// Establece el número de óscares
void Pelicula::setOscares(int _oscares) {
    oscares = _oscares;
}

// Obtiene el número de óscares
int Pelicula::getOscares() {
    return oscares;
}

// Devuelve una representación en cadena de los atributos de la película
string Pelicula::str() {
    return Video::str() + " " + to_string(oscares);
}

