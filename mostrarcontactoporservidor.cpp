void mostrarContactosPorServidor() {
    for (int i = 0; i < cantidadContactos - 1; i++) {
        for (int j = 0; j < cantidadContactos - i - 1; j++) {
            string dominioA = "", dominioB = "";

            bool arrobaEncontrada = false;
            for (int k = 0; listaContactos[j].email[k] != 0; k++) {
                if (arrobaEncontrada) {
                    dominioA += listaContactos[j].email[k];
                }
                if (listaContactos[j].email[k] == @) {
                    arrobaEncontrada = true;
                }
            }

            arrobaEncontrada = false;
            for (int k = 0; listaContactos[j + 1].email[k] != 0; k++) {
                if (arrobaEncontrada) {
                    dominioB += listaContactos[j + 1].email[k];
                }
                if (listaContactos[j + 1].email[k] == @) {
                    arrobaEncontrada = true;
                }
            }

            if (dominioA > dominioB) {
                contactoEmail temp = listaContactos[j];
                listaContactos[j] = listaContactos[j + 1];
                listaContactos[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < cantidadContactos; i++) {
        cout << "\nNombre: " << listaContactos[i].nombres;
        cout << "\nEmail: " << listaContactos[i].email;
        cout << "\n---------------------------";
    }
}
