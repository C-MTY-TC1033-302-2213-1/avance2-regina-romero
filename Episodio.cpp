//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24
//

#include "Episodio.h"

// Constructor default
Episodio::Episodio() {
    titulo = "Supernatural";
    temporada = 4;
    calificacion = 100;
}

// Constructor con parámetros
Episodio::Episodio(string _titulo, int _temporada, int _calificacion) {
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Establece el título del episodio
void Episodio::setTitulo(string _titulo) {
    titulo = _titulo;
}

// Establece la temporada del episodio
void Episodio::setTemporada(int _temporada) {
    temporada = _temporada;
}

// Establece la calificación del episodio
void Episodio::setCalificacion(int _calificacion) {
    calificacion = _calificacion;
}

// Obtiene el título del episodio
string Episodio::getTitulo() {
    return titulo;
}

// Obtiene la temporada del episodio
int Episodio::getTemporada() {
    return temporada;
}

// Obtiene la calificación del episodio
int Episodio::getCalificacion() {
    return calificacion;
}

// Devuelve una representación en cadena de los atributos del episodio
string Episodio::str() {
    return titulo + " " + to_string(temporada) + " " + to_string(calificacion);
}
