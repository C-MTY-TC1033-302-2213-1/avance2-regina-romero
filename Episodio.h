//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24.
//
/*
¿Qué aprendí en el desarrollo de esta clase?
En el desarrollo de esta clase aprendí a definir una clase que representa un episodio de una serie.
Aprendí a implementar constructores, métodos modificadores y de acceso para los atributos de un
episodio, así como a definir un metodo que devuelve una representación en cadena de los atributos del objeto.
Además, comprendí cómo esta clase puede ser utilizada en conjunción con otras clases (Serie) para formar
una relación de composición.
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include <string>
using namespace std;

class Episodio {
private:
    string titulo; // Título del episodio
    int temporada; // Temporada a la que pertenece el episodio
    int calificacion; // Calificación del episodio

public:
    // Constructor default
    Episodio();

    // Constructor con parámetros
    Episodio(string _titulo, int _temporada, int _calificacion);

    //metodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    //metodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    // otros metodos
    string str();
};

#endif

