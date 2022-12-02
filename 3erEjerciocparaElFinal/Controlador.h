#pragma once
#include"Bolas.h"
#include"Personaje.h"
#include"BolasBlue.h"
#include"Tercerabola.h"

using namespace std;

class Controlador
{
private:

	vector<Bolas*>* arrB;
	vector<BolasBlue*>* arrBlue;
	Personaje* personaje;
	vector<Tercerabola*>* arrTercer;
	int random, randoms;

public:
	Controlador(int x, int y, Bitmap^ bmppersona,   int vidas) {

		arrB = new vector<Bolas*>();
		arrBlue = new vector<BolasBlue*>();
		arrTercer = new vector<Tercerabola*>();

		personaje = new Personaje(x, y, bmppersona->Width / 4, bmppersona->Height / 4, vidas);

		random = 1 + rand()% (2);
		randoms = 1 + rand() % (2);

		


	}
	~Controlador(){}

	void agregarBola() {

		for (int i = 0; i < 1; i++)
		{
			arrB->push_back(new Bolas());

		}

		for (int i = 0; i < 1; i++)
		{
			arrBlue->push_back(new BolasBlue());

		}

	}


	void agregarTerceraBola() {

		for (int i = 0; i < 1; i++)
		{
			arrTercer->push_back(new Tercerabola());

		}

	}

	void dibujartodo(Graphics^ gr, Bitmap^ bmppersona) {

		for (int i = 0; i < arrB->size(); i++)
		{
			arrB->at(i)->dibujars(gr);
		}

		for (int i = 0; i < arrBlue->size(); i++)
		{
			arrBlue->at(i)->dibujars(gr);
		}

		for (int i = 0; i < arrTercer->size(); i++)
		{
			arrTercer->at(i)->dibujars(gr);
		}

		personaje->dibujar(gr, bmppersona);

	}

	void movertodo(Graphics^ gr) {

		for (int i = 0; i < arrB->size(); i++)
		{
			arrB->at(i)->mover(gr);
		}

		for (int i = 0; i < arrBlue->size(); i++)
		{
			arrBlue->at(i)->mover(gr);
		}

		for (int i = 0; i < arrTercer->size(); i++)
		{
			arrTercer->at(i)->mover(gr);
		}
	}

	Personaje* getpersonaje() { return personaje; }


	void colision(Graphics^ gr, int x, int y){
	
		//disco rojo con disco azul
		for (int i = 0; i < arrB->size(); i++)
		{
			
			for (int j = 0; j < arrBlue->size(); j++)
			{
				if (arrB->at(i)->getRectangles().IntersectsWith(arrBlue->at(j)->getRectangles()))
				{

					arrB->at(i)->setdy(-1);
					
					arrBlue->at(i)->setdx(-1);
					agregarTerceraBola();


				}
			}

		}
		//personaje disco negro
		for (int i = 0; i < arrTercer->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(arrTercer->at(i)->getRectangles()))
			{
				personaje->setx(x);
				personaje->sety(y);
				personaje->menosvidas();
			}
		}
		//personaje disco rojo

		for (int i = 0; i < arrB->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(arrB->at(i)->getRectangles()))
			{
				personaje->setx(x);
				personaje->sety(y);
				personaje->menosvidas();
			}
		}
		
		//personaje disco azul
		for (int i = 0; i < arrBlue->size(); i++)
		{
			if (personaje->getRectangle().IntersectsWith(arrBlue->at(i)->getRectangles()))
			{
				personaje->setx(x);
				personaje->sety(y);
				personaje->menosvidas();
			}
		}
	
	}
};

