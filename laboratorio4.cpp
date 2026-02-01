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