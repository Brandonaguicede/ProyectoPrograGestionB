#pragma once
#include "Librerias.h"

class Producto {
private:
	int codigo;
	string nombre;
	double precio;
	int cantidad;
	string ubicacion;

public:
	// Constructor
	Producto(int _codigo, string _nombre, double _precio, int _cantidad, string _ubicacion) {
		this->codigo = _codigo;
		this->nombre = _nombre;
		this->precio= _precio; 
		this->cantidad = _cantidad; 
		this->ubicacion = _ubicacion; 
	}

	//Getters
	void getMostrarProducto() {
		cout << "Codigo: " << this->codigo << endl;
		cout << "Nombre: " << this->nombre << endl;
		cout << "Precio: " << this->precio << endl;
		cout << "Cantidad: " << this->cantidad << endl;
		cout << "Ubicacion: " << this->ubicacion << endl; 
	}

	const int getCodigo() const {
		return this->codigo;
	}

	const string getNombre() const {
		return nombre;
	}

	const double getPrecio() const {
		return this->precio;
	}

	const int getCantidad() const {
		return this->cantidad;
	}

	const string getUbicacion() const { 
		return this->ubicacion;
	}

	//Setters
	void setNombre(string _nombre) {
		this->nombre = _nombre;
	}

	void setPrecio(double _precio) {
		this->precio = _precio;
	}

	void setCantidad(int _cantidad) {
		this->cantidad = _cantidad;
	}

	void setUbicacion(string _ubicacion) {
		this->ubicacion = _ubicacion;
	}

};