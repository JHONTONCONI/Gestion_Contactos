void eliminarContacto(){
	string nombre;
	cout<<"Ingrese el nombre completo del contacto que desea eliminar: "<<endl;
	getline(cin, nombre);
	
	for(int i=0; i<cantidadContactos; i++){
		if(listaContactos[i].nombres==nombre){
			for(int j=i; j<cantidadContactos-1; j++){
				listaContactos[j]=listaContactos[j+1];
			}
		cantidadContactos--;
		cout<<"Contacto eliminado."<<endl;
		return;
		}
	}
	cout<<"Contacto no encontrado."<<endl;
}

