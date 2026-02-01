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
