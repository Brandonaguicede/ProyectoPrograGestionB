#pragma once
#include "Librerias.h"
#include "Cliente.h"
#include <fstream>
#include <sstream> 

class ContenedorCliente {
private:
	vector<Cliente>contenedorCliente;

public:
	void setAgregarCliente() {
		int id, telefono; 
		string nombre, correo;
		bool estado = false;
		int opcion = 0;

		cout << "Ingrese el ID: ";
		cin >> id;
		if (id < 0) {
			cout << "No se permiten valores negativos" << endl;
		}
		else {
			cout << "Ingrese el nombre: ";
			cin.ignore();
			getline(cin, nombre);

			cout << "Ingrese el correo: ";
			getline(cin, correo);

			cout << "Ingrese el numero de telefono: ";
			cin >> telefono;

			cout << "Ingrese el estado de actividad (1 = Activo, 0 = Inactivo): ";
			cin >> opcion;
			if (opcion == 1) {
				estado = true;
			}
			if (opcion == 0) {
				estado = false;
			}
		}


		Cliente nuevoCliente (id, nombre, telefono, correo, estado);
		contenedorCliente.push_back(nuevoCliente); 
	}

	void setEditarCliente() {
		int id, telefono;
		string nombre, correo; 
		bool encontrado = false;

		cout << "Ingrese el ID del cliente a editar: ";
		cin >> id;

		for (int i = 0; i < contenedorCliente.size(); i++) {
			if (contenedorCliente[i].getId() == id) {
				cout << "Ingrese el nuevo nombre: ";
				cin.ignore();
				getline(cin, nombre);

				cout << "Ingrese el nuevo correo: ";
				getline(cin, correo);

				cout << "Ingrese el nuevo numero de telefono: ";
				cin >> telefono;
				encontrado = true;

				contenedorCliente[i].setNombre(nombre); 
				contenedorCliente[i].setCorreo(correo);
				contenedorCliente[i].setTelefono(telefono); 
			}
		}

		if(!encontrado){
			cout << "Cliente no encontrado." << endl;
		}

	}

	void getConsultarCliente() {
		int opcion;
		int id;
		bool encontrado = false;	


		do {
			system("cls");

			cout << "1. Mostrar lista de clientes." << endl;
			cout << "2. Buscar un clientes de la lista." << endl;
			cout << "3. Salir." << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			switch (opcion) {

				case 1: {
					for (int i = 0; i < contenedorCliente.size(); i++) {
						contenedorCliente[i].getMostrarCliente();
						cout << "_______________________________________________" << endl;
					}
					cout << "La cantidad de clientes actualmente corresponde a " << contenedorCliente.size() << " cliente(s)." << endl;

					system("pause");
					break;
				}

				case 2: {
					cout << "Ingrese el ID a buscar: ";
					cin >> id;

					for (int i = 0; i < contenedorCliente.size(); i++) {

						if (contenedorCliente[i].getId() == id) {
							contenedorCliente[i].getMostrarCliente();
							cout << "_______________________________________________" << endl;
						}

						encontrado = true;
					}

					if (!encontrado) {
						cout << "Cliente no registrado" << endl;
					}

					system("pause");
					break;
				}

				case 3: {
					cout << "Saliendo.." << endl;
					break;
				}

				default: {
					cout << "Opcion invalida." << endl;
				}
			
			}
		} while (opcion != 3);
	}

	void guardarClientes() const {
		ofstream archivo("clientes.txt");
		if (archivo.is_open()) {
			for (int i = 0; i < contenedorCliente.size(); i++) {
				archivo << contenedorCliente[i].getId()
					<< "-" << contenedorCliente[i].getId()
					<< "-" << contenedorCliente[i].getNombre()
					<< "-" << contenedorCliente[i].getTelefono()
					<< "-" << contenedorCliente[i].getCorreo()
					<< "-" << contenedorCliente[i].getEstado()
					<< endl;
			}
			archivo.close();
			cout << "Lista de clientes almacenada en el archivo correctamente..." << endl;
		}
	}

	void cargarClientes() {
		contenedorCliente.clear();
		ifstream archivo("clientes.txt");
		if (archivo.is_open()) {

			

			
				string linea;
				while (getline(archivo, linea)) {
					stringstream ss(linea);
					string id, _nombre, _correo, estado, telefono;


					getline(ss, id, '-');
					int _id = stoi(id);

					getline(ss, _nombre, '-');

					getline(ss, telefono, '-');
					int _telefono = stoi(telefono);

					getline(ss, _correo, '-');

					getline(ss, estado, '-');
					bool _estado = stoi(estado);


					Cliente nuevoCliente(_id, _nombre, _telefono, _correo, _estado);
					contenedorCliente.push_back(nuevoCliente);
				}
				archivo.close();
				cout << "Clientes cargados correctamente..." << endl;
			
		}
	}

	void getMenuCliente() {

		int opcion;

		cargarClientes();

		do {
			system("cls");

			cout << "================== Menu Clientes ==================" << endl;
			cout << "1. Ingresar un nuevo cliente." << endl;
			cout << "2. Modificar datos de un cliente." << endl;
			cout << "3. Consultar datos de los cliente." << endl;
			cout << "4. Guardar datos." << endl;
			cout << "5. Salir." << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			switch (opcion) {

			case 1: {
				setAgregarCliente();

				system("pause");
				break;
			}
			case 2: {
				setEditarCliente();

				system("pause");
				break;
			}
			case 3: {
				getConsultarCliente();

				system("pause");
				break;
			}
			case 4: {
				guardarClientes();
				system("pause");
				break;
			}
			case 5: {
				cout << "Saliendo..." << endl;
				break;
			}
			default: {
				cout << "Opcion invalida. Intente nuevamente." << endl;
			}

			}
		} while (opcion != 5);

	}

};