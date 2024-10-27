#pragma once
#pragma once
#include "Librerias.h"
#include "Producto.h"
#include <fstream>
#include <sstream> 

class ContenedorProducto{
private:
	vector<Producto>contenedorProducto;

public:
	void setAgregarProducto() {
		int codigo, cantidad;
		string nombre, ubicacion;
		double precio;

		cout << "Ingrese el codigo del Producto: ";
		cin >> codigo;

		cin.ignore();
		cout << "\nIngrese el Nombre del Producto: ";
		getline(cin, nombre);

		cout << "Ingrese el Precio del Producto: ";
		cin >> precio;

		cout << "Ingrese la cantidad del Producto: ";
		cin >> cantidad;

		cin.ignore();
		cout << "Ingrese la Ubicacion del Producto: ";
		getline(cin, ubicacion);

		Producto nuevoProducto = Producto(codigo, nombre, precio, cantidad, ubicacion);
		contenedorProducto.push_back(nuevoProducto);


		cout << "Nuevo provedor agregado correctamente ." << endl;
	}

	void setEditarProducto() {
		int codigo, cantidad;
		string nombre, ubicacion;
		double precio;

		bool encontrado = false;

		cout << "Ingrese el codigo del producto a editar: ";
		cin >> codigo;

		for (int i = 0; i < contenedorProducto.size(); i++) {
			if (contenedorProducto[i].getCodigo() == codigo) {

				cout << "Ingrese el nuevo nombre: ";
				cin.ignore();
				getline(cin, nombre);

				cout << "Ingrese el nuevo precio: ";
				cin >> precio;

				cout << "Ingrese la nueva cantidad: ";
				cin >> cantidad;

				cout << "Ingrese la nueva ubicacion: ";
				getline(cin, ubicacion); 

				encontrado = true;

				contenedorProducto[i].setNombre(nombre);
				contenedorProducto[i].setPrecio(precio);
				contenedorProducto[i].setCantidad(cantidad);
				contenedorProducto[i].setUbicacion(ubicacion); 
			}
		}

		if (!encontrado) { 
			cout << "Producto no encontrado." << endl;
		}

	}

	void getConsultarCliente() {
		int opcion;
		int codigo;
		bool encontrado = false;


		do {
			system("cls");

			cout << "1. Mostrar lista de productos." << endl;
			cout << "2. Buscar un producto de la lista." << endl;
			cout << "3. Salir." << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			switch (opcion) {

			case 1: {
				for (int i = 0; i < contenedorProducto.size(); i++) {
					contenedorProducto[i].getMostrarProducto();
					cout << "_______________________________________________" << endl;
				}
				cout << "La cantidad de productos actualmente corresponde a " << contenedorProducto.size() << " cliente(s)." << endl;

				system("pause");
				break;
			}

			case 2: {
				cout << "Ingrese el codigo a buscar: ";
				cin >> codigo;

				for (int i = 0; i < contenedorProducto.size(); i++) {

					if (contenedorProducto[i].getCodigo() == codigo) {
						contenedorProducto[i].getMostrarProducto();
						cout << "_______________________________________________" << endl;
					}

					encontrado = true;
				}

				if (!encontrado) {
					cout << "Producto no registrado" << endl;
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

	void guardarProductos() const

	{
		ofstream archivo("Productos.txt");
		if (archivo.is_open()) {
			for (int i = 0; i < contenedorProducto.size(); i++){

				archivo << contenedorProducto[i].getCodigo() 
					<< "-" << contenedorProducto[i].getNombre()
					<< "-" << contenedorProducto[i].getPrecio()
					<< "-" << contenedorProducto[i].getCantidad() 
					<< "-" << contenedorProducto[i].getUbicacion() 
					<< endl;
			}
			archivo.close();
			cout << "Lista de Productos en el archivo correctamente...";
		}
	}



	void cargarProductos()
	{
		contenedorProducto.clear();
		ifstream archivo("Productos.txt");

		if (archivo.is_open()) {
			string linea;
			while (getline(archivo, linea)) {
				stringstream ss(linea);
				string codigo, _Nombre, precio, cantidad, _Ubicacion;

				// Leer los campos separados por comas
				getline(ss, codigo, '-');
				int _Codigo = stoi(codigo);

				getline(ss, _Nombre, '-');

				getline(ss, precio, '-');
				float _Precio = stof(precio);

				getline(ss, cantidad, '-');
				int _cantidad = stoi(cantidad);

				getline(ss, _Ubicacion, '-');

				Producto    nuevoProducto = Producto(_Codigo, _Nombre, _Precio, _cantidad, _Ubicacion);

				contenedorProducto.push_back(nuevoProducto);

			}
			archivo.close();
			cout << "Operadores cargados correctamente...";

		}
	}

	void getMenuProducto() {

		int opcion;

		cargarProductos();

		do {
			system("cls");

			cout << "================== Menu Productos ==================" << endl;
			cout << "1. Ingresar un nuevo producto." << endl;
			cout << "2. Modificar un producto." << endl;
			cout << "3. Consultar productos." << endl;
			cout << "4. Guardar productos." << endl;
			cout << "5. Salir." << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			switch (opcion) {

			case 1: {
				setAgregarProducto();

				system("pause");
				break;
			}
			case 2: {
				setEditarProducto();

				system("pause");
				break;
			}
			case 3: {
				getConsultarCliente();

				system("pause");
				break;
			}
			case 4: {
				guardarProductos();
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