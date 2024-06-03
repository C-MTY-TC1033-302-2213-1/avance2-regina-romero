//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24.
//

#include "Video.h"

// Constructor default
Video::Video() {
    iD = "A00840840";
    titulo = "Regina Romero";
    duracion = 100;
    genero = "Femenino";
    calificacion = 100;
}

// Constructor con parámetros
Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion) {
    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

// Establece el ID del video
void Video::setId(string _iD) {
    iD = _iD;
}

// Establece el título del video
void Video::setTitulo(string _titulo) {
    titulo = _titulo;
}

// Establece la duración del video
void Video::setDuracion(int _duracion) {
    duracion = _duracion;
}

// Establece el género del video
void Video::setGenero(string _genero) {
    genero = _genero;
}

// Establece la calificación del video
void Video::setCalificacion(double _calificacion) {
    calificacion = _calificacion;
}

// Obtiene el ID del video
string Video::getId() {
    return iD;
}

// Obtiene el título del video
string Video::getTitulo() {
    return titulo;
}

// Obtiene la duración del video
int Video::getDuracion() {
    return duracion;
}

// Obtiene el género del video
string Video::getGenero() {
    return genero;
}

// Obtiene la calificación del video
double Video::getCalificacion() {
    return calificacion;
}

// Devuelve una representación en cadena del video
string Video::str() {
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion);
}
