#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
using namespace System;
using namespace std;

class Archivo {
private:
	ifstream lectura;
	ofstream escritura;
	string texto;

	float saldo;
public:
	Archivo() {
		leer();
	}
	~Archivo() {}

	float getSaldo() { return saldo; }

	void leer() {
		//abre el saldo.txt
		lectura.open("saldo.txt", ios::in);
		//leer linea
		getline(lectura, texto);
		saldo = stof(texto);
		//cierra el saldo.txt
		lectura.close();
	}

	void escribir(int g, int i, char cat, float saldo, int op) {
		//fecha y hora basado en el sistema actual
		time_t now = time(0);

		//objeto de la librería ctime
		tm* time = localtime(&now);

		//crea el historial.txt
		escritura.open("historial.txt", ios::app);

		//formato dia/mes/año
		string categoria;
		switch (cat) {
		case 'C': categoria = "Comida"; break;
		case 'T': categoria = "Transporte"; break;
		case 'E': categoria = "Entretenimiento"; break;
		case ' ':categoria = "ninguna categoría"; break;
		}
		escritura << "**********************************************" << endl;
		escritura << time->tm_mday << "/" << time->tm_mon + 1 << "/" << 1900 + time->tm_year << "-> Ingreso de: S/." << i << " // Gasto de: S/." << g << " en " << categoria << " a las " << time->tm_hour << ":" << time->tm_min << endl;
		escritura << "SALDO ACTUAL: " << saldo << endl;
		//cierra el historial.txt
		escritura.close();
	}
};