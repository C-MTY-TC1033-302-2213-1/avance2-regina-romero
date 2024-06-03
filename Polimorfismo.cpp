//
// Regina Romero Alvarado
// A00840840
// ITC
// 1/6/24.
//

#include "Polimorfismo.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

// Constructor default
Polimorfismo::Polimorfismo() {
    for (int index = 0; index < MAX_VIDEOS; index++) {
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

// Establece un puntero a un Video en una posición específica del arreglo
void Polimorfismo::setPtrVideo(int index, Video *video) {
    if (index >= 0 && index < MAX_VIDEOS) {
        arrPtrVideos[index] = video;
    }
}

// Establece la cantidad de videos
void Polimorfismo::setCantidad(int _cantidad) {
    if (_cantidad >= 0 && _cantidad < MAX_VIDEOS) {
        cantidad = _cantidad;
    }
}

// Obtiene un puntero a un Video en una posición específica del arreglo
Video* Polimorfismo::getPtrVideo(int index) {
    if (index >= 0 && index < cantidad) {
        return arrPtrVideos[index];
    }
    return nullptr;
}

// Obtiene la cantidad de videos
int Polimorfismo::getCantidad() {
    return cantidad;
}

// Reporta el inventario de videos, separando películas y series
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

// Reporta los videos con una calificación específica
void Polimorfismo::reporteCalificacion(double _calificacion) {
    int total = 0;
    for (int index = 0; index < cantidad; index++) {
        if (arrPtrVideos[index]->getCalificacion() == _calificacion) {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

// Reporta los videos de un género específico
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

// Reporta todas las películas
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

// Reporta todas las series
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

// Lee los datos de un archivo y los almacena en el arreglo de punteros a videos
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
