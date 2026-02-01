#include <iostream>
#include <string>

using namespace std;

// Estructura del nodo
struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};

// Prototipos de funciones
bool buscarPorId(Nodo* head, int id);   
bool eliminarPorId(Nodo*& head, Nodo*& tail, int id); 
int contarPaquetes(Nodo* head);         
void editarPaquete(Nodo* head);         
void liberarLista(Nodo*& head, Nodo*& tail); 
void insertarInicio(Nodo*& head, Nodo*& tail);
void insertarFinal(Nodo*& head, Nodo*& tail);
void mostrarAdelante(Nodo* head);
void mostrarAtras(Nodo* tail);

//Funcion insertar al inicio
void insertarInicio(Nodo*& head, Nodo*& tail) {
    int id;
    cout << "ID: ";
    cin >> id;

    if (buscarPorId(head, id)) {
        cout << "ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo();
    nuevo->id = id;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevo->nombre);

    cout << "Peso: ";
    cin >> nuevo->peso;

    nuevo->ant = NULL;
    nuevo->sig = head;

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }
}

// Funcion insertar al final 
void insertarFinal(Nodo*& head, Nodo*& tail) {
    int id;
    cout << "ID: ";
    cin >> id;

    if (buscarPorId(head, id)) {
        cout << "ID repetido.\n";
        return;
    }

    Nodo* nuevo = new Nodo();
    nuevo->id = id;

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nuevo->nombre);

    cout << "Peso: ";
    cin >> nuevo->peso;

    nuevo->sig = NULL;
    nuevo->ant = tail;

    if (head == NULL) {
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }
}


// Buscar por ID 
bool buscarPorId(Nodo* head, int id) {
    while (head != NULL) {
        if (head->id == id)
            return true;
        head = head->sig;
    }
    return false;
}
// Eliminar por ID
bool eliminarPorId(Nodo*& head, Nodo*& tail, int id) {
    if (head == NULL) return false;

    Nodo* act = head;

    while (act != NULL) {
        if (act->id == id) {

            if (act == head) {
                head = act->sig;
                if (head != NULL)
                    head->ant = NULL;
                else
                    tail = NULL;
            }
            else if (act == tail) {
                tail = act->ant;
                tail->sig = NULL;
            }
            else {
                act->ant->sig = act->sig;
                act->sig->ant = act->ant;
            }

            delete act;
            return true;
        }
        act = act->sig;
    }
    return false;
}
// Contar paquetes 
int contarPaquetes(Nodo* head) {
    int cont = 0;
    while (head != NULL) {
        cont++;
        head = head->sig;
    }
    return cont;
}

// EXTRA: Editar paquete 
void editarPaquete(Nodo* head) {
    int id;
    cout << "ID a editar: ";
    cin >> id;

    while (head != NULL) {
        if (head->id == id) {
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, head->nombre);

            cout << "Nuevo peso: ";
            cin >> head->peso;

            cout << "Paquete actualizado.\n";
            return;
        }
        head = head->sig;
    }
    cout << "ID no encontrado.\n";
}

//  Liberar memoria 
void liberarLista(Nodo*& head, Nodo*& tail) {
    while (head != NULL) {
        Nodo* borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}

int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;

    int op, id;

    do {
        cout << "\n--- EMPRESA DE TERRY ---\n";
        cout << "1. Insertar al final\n";
        cout << "2. Insertar al inicio\n";
        cout << "3. Mostrar adelante\n";
        cout << "4. Mostrar atras\n";
        cout << "5. Buscar por ID\n";
        cout << "6. Eliminar por ID\n";
        cout << "7. Contar paquetes\n";
        cout << "8. Editar paquete (EXTRA)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> op;
 switch (op) {
            case 1: insertarFinal(head, tail); break;
            case 2: insertarInicio(head, tail); break;
            case 3: mostrarAdelante(head); break;
            case 4: mostrarAtras(tail); break;
            case 5:
                cout << "ID a buscar: ";
                cin >> id;
                cout << (buscarPorId(head, id) ? "Existe\n" : "No existe\n");
                break;
            case 6:
                cout << "ID a eliminar: ";
                cin >> id;
                cout << (eliminarPorId(head, tail, id) ? "Eliminado\n" : "No encontrado\n");
                break;
            case 7:
                cout << "Cantidad de paquetes: " << contarPaquetes(head) << endl;
                break;
            case 8:
                editarPaquete(head);
                break;
        }
           } while (op != 0);

    liberarLista(head, tail);
    return 0;
}


