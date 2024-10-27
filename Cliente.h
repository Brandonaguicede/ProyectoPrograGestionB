#pragma once
#include "Librerias.h"

class Cliente {
private: 
	int id;
	string nombre;
	int telefono;
	string correo;
	bool estado;

public:
	// Constructor
	Cliente(int _id, string _nombre, int _telefono, string _correo, bool _estado){
		this->id = _id;
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->correo = _correo;
		this->estado = _estado;
	}

	//Getters
	void getMostrarCliente() {
		cout << "ID: " << this->id << endl;
		cout << "Nombre: " << this->nombre << endl;
		cout << "Telefono: " << this->telefono << endl;
		cout << "Correo: " << this->correo << endl;

		if (this->estado == true) {
			cout << "Estado: Activo" << endl;
		}
		else {
			cout << "Estado: Inactivo" << endl;
		} 

	}

	const int getId() const {
		return id; 
	}

	const string getNombre() const { 
		return nombre; 
	}

	const int getTelefono() const {
		return telefono; 
	}

	const string getCorreo() const {
		return correo; 
	}

	const bool getEstado() const {
		return estado; 
	}

	//Setters
	void setNombre(string _nombre) {
		this->nombre = _nombre;
	}

	void setTelefono(int _telefono) {
		this->telefono = _telefono;
	}

	void setCorreo(string _correo) {
		this->correo = _correo;
	}

};