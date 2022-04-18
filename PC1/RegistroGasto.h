#pragma once
#include <functional>
using namespace std;
using namespace System;
typedef unsigned int uint;

template <typename T, T NADA=0>
class Lista {
private:
	struct Nodo;

	Nodo* ini;
	uint lon; //numero de elementos

public:
	Lista() : ini(nullptr), lon(0) {}
	~Lista() {}

	void agregar(T elem);
	void PromedioDeGastos(int);
	void CatMayorGasto(int, int);
	void CatMenorGasto(int, int);
	uint longitud();
	string vectorCat[3] = { "Cocina", "Entretenimiento","Transporte" };

};

template <typename T, T NADA>
struct Lista<T, NADA>::Nodo {
	T       elem;
	Nodo* sig; // puntero apunta al siguiente nodo

	Nodo(T elem = NADA, Nodo* sig = nullptr) : elem(elem), sig(sig) {}
};

template <typename T, T NADA>
void Lista<T, NADA>::agregar(T elem) {
	Nodo* nuevo = new Nodo(elem, ini);
	if (nuevo != nullptr) {
		ini = nuevo;
		lon++;
	}
}


template <typename T, T NADA>
void Lista<T, NADA>::PromedioDeGastos(int gastos) {
	auto prom = [](int x, int y) {return x/ y; }(gastos, lon);
	cout << "El promedio de gastos por cada vez que se recibió dinero es: " << prom << endl;
}

template <typename T, T NADA>
uint Lista<T, NADA>::longitud() {
	return lon;
}

template <typename T, T NADA>
void Lista<T, NADA>::CatMayorGasto(int gasto, int base) {

	if (gasto == base) {
		cout << "En la categoría en la que más se gastó fue: " << vectorCat[gasto] << endl;
	}
	else
	{
		CatMayorGasto(gasto, base + 1);
	}
	
}

template <typename T, T NADA>
void Lista<T, NADA>::CatMenorGasto(int gasto, int base) {
	
	if(gasto == base){
		cout << "En la categoría en la que menos se gastó fue: " << vectorCat[gasto] << endl;
	}
	else {
		CatMenorGasto(gasto, base + 1);
	}
}