void mostrarContactos() {
	if (cantidadContactos == 0) {
        cout << "No hay contactos registrados.\n";
       return;
    }
    for (int i = 0; i < cantidadContactos; i++) {
        cout << "\nNombre: " << listaContactos[i].nombres;
        cout << "\nSexo: " << listaContactos[i].sexo;
        cout << "\nEdad: " << listaContactos[i].edad;
        cout << "\nTeléfono: " << listaContactos[i].telefono;
        cout << "\nEmail: " << listaContactos[i].email;
        cout << "\nNacionalidad: " << listaContactos[i].nacionalidad;
        cout << "\n-----------------------------";
    }
}

