#include <iostream>

using namespace std;


//Estructura del nodo
struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};