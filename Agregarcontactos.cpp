void agregarContacto(){
	if (cantidadContactos >= MAX_CONTACTOS) {
    	cout<<"Lista de contactos llena"<<endl;
    	return;
    }
	cout<<"Nombre completo: "; getline(cin, listaContactos[cantidadContactos].nombres);
	cout<<"Sexo: "; getline(cin, listaContactos[cantidadContactos].sexo);
	cout<<"Edad: "; getline(cin, listaContactos[cantidadContactos].edad); cin.ignore();
	cout<<"Numero de telefono: "; getline(cin, listaContactos[cantidadContactos].telefono);
	cout<<"Email: "; getline(cin, listaContactos[cantidadContactos].email);
	cout<<"Nacionalidad: "; getline(cin, listaContactos[cantidadContactos].nacionalidad);
	
	cantidadContactos++;
	cout<<"Contacto agregado con exito."<<endl;
}

