// Polimorfismo.h
#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

using namespace std;

const int MAX_VIDEOS = 100;

class Polimorfismo {
private:
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:
    Polimorfismo();

    void leerArchivo(string nombre);

    // metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // metodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    // Otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
};

#endif

// Polimorfismo.cpp
#include "Polimorfismo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

Polimorfismo::Polimorfismo() {
    for(int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    cantidad = 0;
}

void Polimorfismo::setPtrVideo(int index, Video *video) {
    if (index >= 0 && index < MAX_VIDEOS) {
        arrPtrVideos[index] = video;
    }
}

void Polimorfismo::setCantidad(int _cantidad) {
    if (_cantidad >= 0 && _cantidad < MAX_VIDEOS) {
        cantidad = _cantidad;
    }
}

Video* Polimorfismo::getPtrVideo(int index) {
    if(index >= 0 && index < cantidad) {
        return arrPtrVideos[index];
    }
    return nullptr;
}

int Polimorfismo::getCantidad() {
    return cantidad;
}

void Polimorfismo::reporteInventario() {
    int contPeliculas = 0;
    int contSeries = 0;

    for (int index = 0; index < cantidad; index++) {
        cout << arrPtrVideos[index]->str() << endl;
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
            contPeliculas++;
        } else if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
            contSeries++;
        }
    }
    cout << "Peliculas = " << contPeliculas << endl;
    cout << "Series = " << contSeries << endl;
}

void Polimorfismo::reporteCalificacion(double _calificacion) {
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if(arrPtrVideos[index]->getCalificacion() == _calificacion) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " <<  total << endl;
}

void Polimorfismo::reporteGenero(string _genero) {
    int total = 0;
    for (int index = 0; index < cantidad; index++) {
        if (arrPtrVideos[index]->getGenero() == _genero) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

void Polimorfismo::reportePeliculas() {
    int total = 0;
    for (int index = 0; index < cantidad; index++) {
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    if (total == 0) {
        cout << "No peliculas" << endl;
    } else {
        cout << "Total Peliculas = " << total << endl;
    }
}

void Polimorfismo::reporteSeries() {
    int total = 0;
    for (int index = 0; index < cantidad; index++) {
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    if (total == 0) {
        cout << "No series" << endl;
    } else {
        cout << "Total Series = " << total << endl;
    }
}

void Polimorfismo::leerArchivo(string nombre) {
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);
    if (!entrada.is_open()) {
        cerr << "No se pudo abrir el archivo: " << nombre << endl;
        return;
    }

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P") {
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if (row[0] == "S") {
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        } else if (row[0] == "E") {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stod(row[4]))));  // corregido stoi por stod
        }
    }

    for (int index = 0; index < cantidadSeries; index++) {
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrSeries[index]->calculaDuracion();
        setPtrVideo(cantidad, arrPtrSeries[index]);  // corregido: se usa 'cantidad' en lugar de 'index'
        cantidad++;
    }

    for (int index = 0; index < cantidadPeliculas; index++) {
        setPtrVideo(cantidad, arrPtrPeliculas[index]);
        cantidad++;
    }

    entrada.close();
}
