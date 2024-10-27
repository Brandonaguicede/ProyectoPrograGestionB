
#include <iostream>
#include "Librerias.h"
#include "ContenedorCliente.h"
#include "ContenedorProducto.h"

int main()
{
	ContenedorCliente cliente;
	ContenedorProducto producto;

	int opcion;
	
	do
	{
		system("cls");
		cout << "######### Menu de Gestion #########" << endl;
		cout << "1. Gestionar Productos" << endl;
		cout << "2. Gestionar Clientes" << endl;
		cout << "3. Gestionar Ventas " << endl;
		cout << "4. Salir.." << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;

		switch (opcion){
		case 1:
		{
			producto.getMenuProducto();
			system("pause");
			break;
		}
		case 2:
		{
			cliente.getMenuCliente(); 
			system("pause");
			break;
		}
		case 3:
		{

			system("pause");
			break;
		}
		case 4:
		{
			cout << "Saliendo..." << endl;
			break;
		}
		default:
			cout << "Opcion invalida..." << endl;
			system("pause");
			break;
		}
	} while (opcion != 3);

}
