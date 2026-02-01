/* =====================================================
   PERSONA B
   - Buscar
   - Eliminar
   - Contador
   - Extra (Editar)
   - Liberar memoria
   - main()
   ===================================================== */
// ----- Buscar por ID -----
bool buscarPorId(Nodo* head, int id) {
    while (head != NULL) {
        if (head->id == id)
            return true;
        head = head->sig;
    }
    return false;
}
// ----- Eliminar por ID -----
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
// ----- Contar paquetes -----
int contarPaquetes(Nodo* head) {
    int cont = 0;
    while (head != NULL) {
        cont++;
        head = head->sig;
    }
    return cont;
}

// ----- EXTRA: Editar paquete -----
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

// ----- Liberar memoria -----
void liberarLista(Nodo*& head, Nodo*& tail) {
    while (head != NULL) {
        Nodo* borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}
// ----- MAIN -----
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

