#pragma once

#include "Entidad.h"
using namespace std;

class File
{
private:
	ofstream escribirA;
	ifstream leerA;
	string texto;  //sacar los datos del archivo
	int x,y,vida,tiempo;

public:
	File() {

	}
	~File() {}

	void leerdatos() {


		leerA.open("Configuracion.txt", ios::in); //intentas abrir el archivo
		if (leerA.fail()) {

			leerA.close();	//le el archivo, si da error lo cierra y crea uno
			//escribe el archivo 
			escribirA.open("Configuracion.txt", ios::out);
			escribirA << "400" << endl; //x;
			escribirA << "410" << endl; //y;
			escribirA << "5" << endl; //vida;
			escribirA << "40" << endl; //tiempo;

			escribirA.close();

			//abrimos el archivo para la lectura
			leerA.open("Configuracion.txt", ios::in);
		}

		getline(leerA, texto);
		x = atoi(texto.c_str());
		getline(leerA, texto);
		y = atoi(texto.c_str());
		getline(leerA, texto);
		vida = atoi(texto.c_str());
		getline(leerA, texto);
		tiempo = atoi(texto.c_str());

		leerA.close();


	}

	int getx() { return x; }
	int gety() { return y; }
	int getvida() { return vida; }
	int gettiempo() { return tiempo; }



};