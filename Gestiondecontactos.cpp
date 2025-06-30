#include <iostream>
#include <string>
using namespace std;

struct contactoEmail{
	string nombres;
	string sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

const int MAXCONTACTOS = 100;
contactoEmail listaContactos[MAXCONTACTOS];
int cantidadContactos = 0;

void agregarContacto(){
	if (cantidadContactos >= MAXCONTACTOS) {
    	cout<<"Lista de contactos llena"<<endl;
    	return;
    }
	cout<<"Nombre completo: "; getline(cin, listaContactos[cantidadContactos].nombres);
	cout<<"Sexo: "; getline(cin, listaContactos[cantidadContactos].sexo);
	cout<<"Edad: "; cin >> listaContactos[cantidadContactos].edad; cin.ignore();
	cout<<"Numero de telefono: "; getline(cin, listaContactos[cantidadContactos].telefono);
	cout<<"Email: "; getline(cin, listaContactos[cantidadContactos].email);
	cout<<"Nacionalidad: "; getline(cin, listaContactos[cantidadContactos].nacionalidad);
	
	cantidadContactos++;
	cout<<"Contacto agregado con exito."<<endl;
}

void eliminarContacto(){
	if (cantidadContactos == 0) {
        cout << "No hay contactos registrados para eliminar.\n";
        return;
    }
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

int main(){
	int opcion;
	do{
		cout<<"\nMENU DE CONTACTOS"<<endl;
		cout<<"1. Agregar contacto"<<endl;
		cout<<"2. Eliminar contacto"<<endl;
		cout<<"3. Mostrar lista de contactos"<<endl;
		cout<<"4. Mostrar contactos por servidor"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"Elija cualquier opcion: ";
		cin>>opcion; cin.ignore();
		
		switch(opcion){
			case 1: agregarContacto(); break;
			case 2: eliminarContacto(); break;
			case 3: mostrarContactos(); break;
			case 4: mostrarContactosPorServidor(); break;
			case 5: cout<<"Saliendo del programa..."<<endl; break;
			default: cout<<"Opcion no valida"<<endl;
		}
	}while(opcion != 5);
	
	return 0;
}

